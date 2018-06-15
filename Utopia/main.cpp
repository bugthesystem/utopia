
#include <iostream>
#include "StatsCalculator.h"
#include "Constants.h"
#include "Helpers.h"

void SeedData(StatsCalculator * calculator) {
	for (int i = 0; i < RANDOM_ITEM_COUNT; ++i) {
		calculator->PushValue(RandomIntInRange(MIN_RESPONSE_SIZE_IN_MS, MAX_RESPONSE_SIZE_IN_MS));
	}
}

int main()
{
	auto *calculator = new StatsCalculator();

	SeedData(calculator);

	calculator->Dump();

	std::cout << "=============================" << std::endl;
	std::cout << "| Median: " << calculator->GetMedian() << std::endl;
	std::cout << "| Average: " << calculator->GetAverage() << std::endl;
	std::cout << "==============================" << std::endl;

	system("PAUSE");
	return 0;
}
