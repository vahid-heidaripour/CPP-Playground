#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

// Population is a vector of Individuals
struct Individual {
	double	x;
	double	y;
	double	z;
	double	fitness;

	bool operator> (const Individual &o) const {
		return fitness > o.fitness;
	}
};

std::vector<Individual>	generate(int);
std::vector<Individual>	reproduce(std::vector<Individual> &, int);
std::vector<Individual>	select(const std::vector<Individual> &,
			    const std::vector<Individual> &, int);
void			mutate(std::vector<Individual> &, int);
void			evaluate(std::vector<Individual> &);
bool			is_converged(const std::vector<Individual> &);
void			print_summary(const std::vector<Individual> &);
double			f(double, double, double);

const double xmin = 0, xmax = 100;
const double ymin = 0, ymax = 100;
const double zmin = 0, zmax = 100;
auto generator = std::default_random_engine(); // for random generation

int
main(void)
{
	// generating first generation randomly
	auto population = generate(100000);
	// calculate fitness and sort all by fitness
	evaluate(population);

	// repeat the algorithm until population is converged
	while (!is_converged(population)) {
		// generate new population by applying crossover
		auto new_generation = reproduce(population, 100000);
		// mutate generated population randomly
		mutate(new_generation, 10000);
		// calculate fitness and sort all by fitness
		evaluate(new_generation);
		// select best individuals as next generation
		population = select(population, new_generation, 100000);
		print_summary(population);
	}

	return 0;
}

// generate population randomly
std::vector<Individual>
generate(int count)
{
	auto res = std::vector<Individual>(count);
	// using uniform distribution to generate numbers
	auto xdist = std::uniform_real_distribution<double>(xmin, xmax);
	auto ydist = std::uniform_real_distribution<double>(ymin, ymax);
	auto zdist = std::uniform_real_distribution<double>(zmin, zmax);

	for (auto &p: res) {
		p.x = xdist(generator);
		p.y = ydist(generator);
		p.z = zdist(generator);
	}

	return res;
}

// reproduce new individuals from existing ones
std::vector<Individual>
reproduce(std::vector<Individual> &parents, int count)
{
	auto res = std::vector<Individual>(count);
	// using uniform distribution to select parents
	auto parentdist = std::uniform_int_distribution<int>(
		0, parents.size() - 1);
	// using uniform distribution to derive numbers from parents
	// we generate new individual as a weighted average of parents
	auto weightdist = std::uniform_real_distribution<double>(
		0.0, 1.0);

	for (auto &child: res) {
		// select parents randomly
		const auto &p1 = parents[parentdist(generator)];
		const auto &p2 = parents[parentdist(generator)];
		// select weights for weighted average
		// if we use weight w1 for parent1,
		// we should use weight w2 = (1 - w1) for parent2
		double wx1 = weightdist(generator), wx2 = 1 - wx1;
		double wy1 = weightdist(generator), wy2 = 1 - wy1;
		double wz1 = weightdist(generator), wz2 = 1 - wz1;

		// a simple weighted average of parents
		child.x = wx1 * p1.x + wx2 * p2.x;
		child.y = wy1 * p1.y + wy2 * p2.y;
		child.z = wz1 * p1.z + wz2 * p2.z;
	}

	return res;
}

// select best individuals of 2 generations
std::vector<Individual>
select(const std::vector<Individual> &generation1,
    const std::vector<Individual> &generation2, int count)
{
	// we can not generate more than all available individuals
	auto res = std::vector<Individual>(std::min(count,
		(int)(generation1.size() + generation2.size())));
	auto it1 = generation1.begin();
	auto it2 = generation2.begin();

	// a simple merge (as in merge-sort)
	for (auto &p: res) {
		// when there is no more individual from generation2
		// or when next one from generation1 is better than
		// next one from generation2, we select generation1
		if (it2 == generation2.end() ||
		    (it1 != generation1.end() && *it1 > *it2))
			p = *it1++;
		// otherwise we select next one from generation2
		else
			p = *it2++;
	}

	return res;
}

// mutate individuals randomly
void
mutate(std::vector<Individual> &population, int count)
{
	// using uniform distribution to select individuals
	auto selectdist = std::uniform_int_distribution<int>(
		0, population.size() - 1);
	// using uniform distribution to select fields (x, y, z)
	auto fielddist = std::uniform_int_distribution<int>(0, 2);
	// using uniform distribution to generate new numbers
	auto xdist = std::uniform_real_distribution<double>(xmin, xmax);
	auto ydist = std::uniform_real_distribution<double>(ymin, ymax);
	auto zdist = std::uniform_real_distribution<double>(zmin, zmax);

	for (int iteration = 0; iteration < count; ++iteration) {
		auto &p = population[selectdist(generator)];
		switch (fielddist(generator)) {
		case 0:
			p.x = xdist(generator);
			break;
		case 1:
			p.y = ydist(generator);
			break;
		default:
			p.z = zdist(generator);
			break;
		}
	}
}

// calculate fitness by a user-defined function
// also sort all individuals by calculated fitness
void
evaluate(std::vector<Individual> &population)
{
	for (auto &p: population)
		p.fitness = f(p.x, p.y, p.z);
	// we use greater, to order individuals from best to worst
	std::sort(population.begin(), population.end(),
	    std::greater<Individual>());
}

// examine population to find out about convergence
bool
is_converged(const std::vector<Individual> &population)
{
	// after evaluation (or merging) the first one is
	// always the best individual and the last one is
	// always the worst individual
	const auto &first = population[0];
	const auto &last = population[population.size() - 1];

	// we consider small difference between the best
	// and the worst fitness as convergence
	return std::abs(first.fitness - last.fitness) < 1e-6;
}

void
print_summary(const std::vector<Individual> &population)
{
	const auto &best = population[0];

	std::cout << "Population Size: " << population.size();
	std::cout << "   Best = (X: " << best.x
		<< ", Y: " << best.y << ", Z: " << best.z << ")";
	std::cout << "   Fitness = " << best.fitness << std::endl;
}

double
f(double x, double y, double z)
{
	double	y2 = y * y;
	double	y3 = y * y2;
	double	z3 = z * z * z;

	return 2 * x * z * std::exp(-x) - 2 * y3 + y2 - 3 * z3;
}
