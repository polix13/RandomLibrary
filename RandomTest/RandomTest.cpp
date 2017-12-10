// RandomTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.h"
#include "InternetRandom.h"
#include <memory>
#include <iostream>
#include <string>
#include <gtest/gtest.h>

using namespace std;

/*
TEST(RandomTest, CheckTrueRandomInteger)
{
	bool isDifferentNumber = true;

	for(int i = 0; i < 10000; i++)
	{
		const auto firstRandomNumber = Random::Get(
			std::numeric_limits<int>::min(),
			std::numeric_limits<int>::max());

		const auto secondRandomNumber = Random::Get(
			std::numeric_limits<int>::min(),
			std::numeric_limits<int>::max());

		isDifferentNumber = firstRandomNumber != secondRandomNumber;
	}

	EXPECT_EQ(isDifferentNumber, true);
}

TEST(RandomTest, TestRandomRangeOverflow)
{
	bool isRangeOverflow = false;

	// From lower to greater
	for (std::uint8_t i = 0u; i < std::numeric_limits<std::uint8_t>::max() && !isRangeOverflow; ++i)
	{
		const auto randomNumber = Random::Get(-1, 1);
		isRangeOverflow = randomNumber < -1 || randomNumber > 1;
	}
	
	EXPECT_EQ(isRangeOverflow, false);

	// From greater to lower
	for (std::uint8_t i = 0u; i < std::numeric_limits<std::uint8_t>::max(); ++i)
	{
		const auto randomNumber = Random::Get(1, -1);
		isRangeOverflow = randomNumber < -1 || randomNumber > 1;
	}

	EXPECT_EQ(isRangeOverflow, false);

	// Range with 0 gap
	for (std::uint8_t i = 0u; i < std::numeric_limits<std::uint8_t>::max(); ++i)
	{
		const auto randomNumber = Random::Get(0, 0);
		isRangeOverflow = randomNumber != 0;
	}

	EXPECT_EQ(isRangeOverflow, false);
}

TEST(RandomTest, TestRandomDataTypes)
{
	// int
	static_assert(std::is_same<int,
		decltype(Random::Get(0, 0))>::value, "int type failed");

	//static_assert(std::is_same<float,
	//	decltype(Random::Get(0.0f, 0.0f))>::value, "float type failed");
}
*/
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();



	//std::shared_ptr<Random> Random;

	std::cout << "------------------------------------" << std::endl;


	for (auto i = 0; i < 10; i++)
	{
		auto randomNumber = Random::Get(1.0f, 100.0f);

		std::cout << "Number = " << randomNumber << std::endl;
	}

	for (auto i = 0; i < 10; i++)
	{
		auto randomReal = Random::Generate(1.0f, 100.0f);

		auto randomInt = Random::Generate(1, 100);

		std::cout << "Number = " << randomReal << std::endl;
	}

	string input;

	std::getline(std::cin, input);

    return 0;
}

