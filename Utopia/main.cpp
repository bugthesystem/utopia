
#include <iostream>
#include "StatsCollector.h"
#include "Constants.h"
#include "Random.h"

void SeedData(StatsCollector *calculator, Random *rand) {
    for (int i = 0; i < RANDOM_ITEM_COUNT; ++i) {
        calculator->PushValue(rand->integer(MIN_RESPONSE_SIZE_IN_MS, MAX_RESPONSE_SIZE_IN_MS));
    }
}

int main() {
    auto *calculator = new StatsCollector();
    auto *rand = new Random();

    SeedData(calculator, rand);

    std::cout << "=============================" << std::endl;
    std::cout << "| Median : " << calculator->GetMedian() << std::endl;
    std::cout << "| Average: " << calculator->GetAverage() << std::endl;
    std::cout << "==============================" << std::endl;

    system("PAUSE");
    return 0;
}
