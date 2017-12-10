//Automobile.h
#ifndef _RANDOM_H
#define _RANDOM_H

#include <random>
#include <chrono> // timed seed

namespace details
{

	/// True if type T is applicable by a std::uniform_int_distribution
	template<typename T>
	struct is_uniform_int {
		static constexpr bool value =
			std::is_same<T, short>::value
			|| std::is_same<T, int>::value
			|| std::is_same<T, long>::value
			|| std::is_same<T, long long>::value
			|| std::is_same<T, unsigned short>::value
			|| std::is_same<T, unsigned int>::value
			|| std::is_same<T, unsigned long>::value
			|| std::is_same<T, unsigned long long>::value;
	};

	template<typename T>
	struct is_uniform_real {
		static constexpr bool value =
			std::is_same<T, float>::value
			|| std::is_same<T, double>::value
			|| std::is_same<T, long double>::value;
	};
}

class Random
{
public:
	Random();
	~Random();

	/*template<typename T>
	static typename std::enable_if<details::is_uniform_int<T>::value, T>::type Get(T from, T to)
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
	}*/

	template<typename T>
	static typename std::enable_if<details::is_uniform_real<T>::value, T>::type Get(T from, T to)
	{
		std::seed_seq seed_seq{ {
				static_cast<std::uintmax_t>(std::random_device{}()),
				static_cast<std::uintmax_t>(std::chrono::steady_clock::now()
				.time_since_epoch().count())
			} };

		thread_local std::mt19937 eng{ seed_seq };

		if (from > to)
		{
			return std::uniform_real_distribution<T>{ to, from }(eng);
		}

		return std::uniform_real_distribution<T>{ from, to }(eng);
	}

	static int Generate(int f, int t)
	{
		return 0;
	}

	static float Generate(float f, float t)
	{
		return 0.0f;
	}

	static double Generate(double f, double t)
	{
		return 0.0f;
	}

	static string Generate(char* Array)
	{
		return "";
	}
};

#endif // #define _RANDOM_H