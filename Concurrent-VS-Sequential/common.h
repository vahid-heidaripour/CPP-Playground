#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>

struct operations
{
    int firstOperand;
    int secondOperand;
    int oper; // 0 is add, 1 is swap
};

std::vector<operations> read_operations_file(char* filename)
{
    std::vector<operations> resultVec;
    std::ifstream infile;
    infile.open(filename);

    int first, second, op;

    while (infile >> first >> second >> op)
    {
        operations operation;
        operation.firstOperand = first;
        operation.secondOperand = second;
        operation.oper = op;

        resultVec.push_back(operation);
    }

    infile.close();

    return resultVec;
}

class thread_guard {

	std::thread & t;

public:
	explicit thread_guard(std::thread & _t) : t(_t)
	{}

	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}

	thread_guard(const thread_guard &) = delete;
	thread_guard & operator= (const thread_guard &) = delete;
};

class join_threads {
	std::vector<std::thread>& threads;

public:
	explicit join_threads(std::vector<std::thread> & _threads) :
		threads(_threads)
	{}

	~join_threads()
	{
		for (long i = 0; i < threads.size(); i++)
		{
			if (threads[i].joinable())
				threads[i].join();
		}
	}

};

class function_wrapper{
	struct impl_base {
		virtual void call() = 0;
		virtual ~impl_base() {}
	};

	template<typename F>
	struct impl_type : impl_base
	{
		F f;
		impl_type(F&& f_) : f(std::move(f_)) {}
		void call() { f(); }
	};

	std::unique_ptr<impl_base> impl;

public:
	template<typename F>
	function_wrapper(F&& f) :
		impl(new impl_type<F>(std::move(f)))
	{}

	void operator()() { impl->call(); }

	function_wrapper()
	{}

	function_wrapper(function_wrapper&& other) :
		impl(std::move(other.impl))
	{}

	function_wrapper& operator=(function_wrapper&& other)
	{
		impl = std::move(other.impl);
		return *this;
	}

	function_wrapper(const function_wrapper&) = delete;
	function_wrapper(function_wrapper&) = delete;
	//function_wrapper& operator=(const function_wrapper&) = delete;
};

#endif // __COMMON_H__