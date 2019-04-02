#ifndef __THREAD_POOL_WITH_LOCAL_WORK_QUEUE_H__
#define __THREAD_POOL_WITH_LOCAL_WORK_QUEUE_H__

#include <thread>
#include <atomic>
#include <vector>
#include <iostream>
#include <future>
#include <numeric>
#include <list>
#include "thread_safe_queue.h"
#include "common.h"

class thread_pool_with_local_work_queue {

	std::atomic_bool done;
	threadsafe_queue< function_wrapper> global_work_queue;

	typedef std::queue<function_wrapper> local_queue_type;
	static thread_local std::unique_ptr<local_queue_type> local_work_queue ;

	std::vector<std::thread> threads;
	join_threads joiner;

	void worker_thread()
	{
		local_work_queue.reset(new local_queue_type{});

		while (!done)
		{
			run_pending_task();
		}
	}

public:
	thread_pool_with_local_work_queue() :done(false), joiner(threads)
	{
		int const thread_count = std::thread::hardware_concurrency();

		try
		{
			for (int i = 0; i < thread_count; ++i)
			{
				threads.push_back(
					std::thread(&thread_pool_with_local_work_queue::worker_thread, this));
			}
		}
		catch (...)
		{
			done = true;
			throw;
		}
	}

	~thread_pool_with_local_work_queue()
	{
		done = true;
	}

	template<typename FunctionType>
	std::future<typename std::result_of<FunctionType()>::type> submit(FunctionType f)
	{
		typedef typename std::result_of<FunctionType()>::type result_type;

		std::packaged_task<result_type()> task(std::move(f));
		std::future<result_type> res(task.get_future());

		if (local_work_queue)
		{
			local_work_queue->push(std::move(task));
		}
		else
		{
			global_work_queue.push(std::move(task));
		}
		return res;
	}

	void run_pending_task()
	{
		function_wrapper task;
		if (local_work_queue && !local_work_queue->empty())
		{
			task = std::move(local_work_queue->front());
			local_work_queue->pop();
			task();
		}
		else if (global_work_queue.try_pop(task))
		{
			task();
		}
		else
		{
			std::this_thread::yield();
		}
	}
};

thread_local std::unique_ptr<std::queue<function_wrapper>> thread_pool_with_local_work_queue::local_work_queue;

template<typename T>
struct sorter {

	thread_pool_with_local_work_queue pool;

	std::list<T> do_sort(std::list<T> & chunk_data)
	{
		if (chunk_data.size() < 2)
			return chunk_data;

		std::list<T> result;
		result.splice(result.begin(), chunk_data, chunk_data.begin());
		T const & partition_val = *result.begin();

		typename std::list<T>::iterator divide_point = std::partition(chunk_data.begin(),
			chunk_data.end(), [&](T const & val)
		{
			return val < partition_val;
		});

		std::list<T> new_lower_chunk;
		new_lower_chunk.splice(new_lower_chunk.end(), chunk_data,
			chunk_data.begin(), divide_point);

		std::future<std::list<T>> new_lower =
			pool.submit(std::bind(&sorter::do_sort, this, std::move(new_lower_chunk)));

		std::list<T> new_higher(do_sort(chunk_data));

		result.splice(result.end(), new_higher);

		//while (!new_lower._Is_ready())
		while(new_lower.wait_for(std::chrono::seconds(0))== std::future_status::timeout)
		{
			pool.run_pending_task();
		}

		result.splice(result.begin(), new_lower.get());

		return result;

	}

};

template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
	if (input.empty())
	{
		return input;
	}

	sorter<T> s;
	return s.do_sort(input);
}

void run()
{
	thread_pool_with_local_work_queue pool;
	const int size = 800;
	std::list<int> my_array;

	srand(0);

	for (size_t i = 0; i < size; i++)
	{
		my_array.push_back(rand());
	} 

	my_array = parallel_quick_sort(my_array);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << my_array.front() << std::endl;
		my_array.pop_front();
	}
}

#endif //__THREAD_POOL_WITH_LOCAL_WORK_QUEUE_H__
