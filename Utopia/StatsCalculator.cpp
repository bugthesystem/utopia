
#include <iostream>
#include "StatsCalculator.h"
#include "Constants.h"

StatsCollector::StatsCollector() {
	this->total = nullptr;
}

StatsCollector::~StatsCollector() {
	delete[] responseTimeArray;
	delete total;
}

void StatsCollector::PushValue(int value) {
	if (this->total == nullptr) this->total = new long long(1);
	else (*this->total)++;

	if (responseTimeArray[value] == nullptr) responseTimeArray[value] = new int(1);
	else (*responseTimeArray[value])++;
}

long long StatsCollector::GetMedian() {
	float mid = (*this->total) / 2.0, even = (*this->total) % 2;
	long long sum = 0LL;

	for (int i = 0; i < MAX_RESPONSE_SIZE_IN_MS; ++i) {
		if (responseTimeArray[i] != nullptr) sum += *responseTimeArray[i];

		if (sum > mid) return even == 0 ? (i + this->GetNext(i)) / 2 : i;
	}
}

long long StatsCollector::GetAverage() {
	long long sum = 0, tmp = 0;

	for (int i = 0; i < MAX_RESPONSE_SIZE_IN_MS; ++i) {
		if (responseTimeArray[i] != nullptr) tmp = (*responseTimeArray[i]) * i;

		if (tmp != 0) sum += tmp;

		tmp = 0;
	}

	return sum / *this->total;
}

void StatsCollector::Dump() {

	for (int i = 0; i < MAX_RESPONSE_SIZE_IN_MS; ++i) {
		if (responseTimeArray[i] == nullptr) {
			std::cout << "Item " << i << ": NULL" << std::endl;
		}
		else {
			std::cout << "Item " << i << ":" << *responseTimeArray[i] << std::endl;
		}
	}
}

int StatsCollector::GetNext(int index)
{
	for (; index < MAX_RESPONSE_SIZE_IN_MS && this->responseTimeArray[index] == nullptr; index++);

	return index;
}
