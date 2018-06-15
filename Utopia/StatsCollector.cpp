
#include <iostream>
#include "StatsCollector.h"
#include "Constants.h"

StatsCollector::StatsCollector() {
    this->total = nullptr;
}

StatsCollector::~StatsCollector() {
    delete total;
    delete[] responseTimeArray;
}

void StatsCollector::PushValue(int value) {
    if (this->total == nullptr) this->total = new long long(1);
    else (*this->total)++;

    if (responseTimeArray[value] == nullptr) responseTimeArray[value] = new int(1);
    else (*responseTimeArray[value])++;
}

long long StatsCollector::GetMedian() {
    double mid = (*this->total) / 2.0;
    long long even = (*this->total) % 2;
    long long sum = 0LL;

    for (int i = 0; i < MAX_RESPONSE_SIZE_IN_MS; ++i) {
        if (responseTimeArray[i] != nullptr) sum += *responseTimeArray[i];

        if (sum > mid) return even == 0 ? (i + this->GetNextIndexWithValue(i)) / 2 : i;
    }

    return 0;
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

int StatsCollector::GetNextIndexWithValue(int index) {
    for (; index < MAX_RESPONSE_SIZE_IN_MS && this->responseTimeArray[index] == nullptr; index++);

    return index;
}
