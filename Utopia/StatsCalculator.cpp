
#include <iostream>
#include "StatsCalculator.h"
#include "Constants.h"

StatsCalculator::StatsCalculator() {
	// stuff
}

StatsCalculator::~StatsCalculator() {
	delete[] responseTimeArray;
	delete total;
}

long long StatsCalculator::GetMedian() {
	return 0;
}

long long StatsCalculator::GetAverage() {
	long long sum, tmp = 0;

	for (int i = 0; i < MAX_RESPONSE_SIZE_IN_MS; ++i) {
		if (responseTimeArray[i] != nullptr) tmp = (*responseTimeArray[i]) * i;

		if (tmp != 0) sum += tmp;

		tmp = 0;
	}

	return sum / *this->total;
}

void StatsCalculator::PushValue(int value) {
	if (this->total == nullptr) this->total = new long long(1);
	else (*this->total)++;

	if (responseTimeArray[value] == nullptr) responseTimeArray[value] = new int(1);
	else (*responseTimeArray[value])++;
}

void StatsCalculator::Dump() {

	for (int i = 0; i < MAX_RESPONSE_SIZE_IN_MS; ++i) {
		if (responseTimeArray[i] == nullptr) {
			std::cout << "Item " << i << ": NULL" << std::endl;
		}
		else {
			std::cout << "Item " << i << ":" << *responseTimeArray[i] << std::endl;
		}
	}
}

