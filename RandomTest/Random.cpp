#include "stdafx.h"
#include <random>
#include <chrono> // timed seed
#include "Random.h"

Random::Random()
{
	// construct
}

Random::~Random()
{
	// destruct
}

/*
template<typename T>
T Random::Get(T from, T to)
{
	std::seed_seq seed_seq{ {
		static_cast<std::uintmax_t>(std::random_device{}()),
		static_cast<std::uintmax_t>(std::chrono::steady_clock::now()
		.time_since_epoch().count())
	} };

	thread_local std::mt19937 eng{ seed_seq };

	if (from > to)
	{
		return std::uniform_int_distribution<T>{ to, from }(eng);
	}

	return std::uniform_int_distribution<T>{ from, to }(eng);
}
*/