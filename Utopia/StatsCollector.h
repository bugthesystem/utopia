
#ifndef UTOPIA_STATSCOLLECTOR_H
#define UTOPIA_STATSCOLLECTOR_H

#include "Constants.h"

class StatsCollector {
public:
    StatsCollector();

    ~StatsCollector();

    long long GetMedian();

    long long GetAverage();

    void PushValue(int value);

private:
    int *responseTimeArray[MAX_RESPONSE_SIZE_IN_MS] = {nullptr};
    long long *total;

private:
    int GetNextIndexWithValue(int index);
};


#endif //UTOPIA_STATSCOLLECTOR_H
