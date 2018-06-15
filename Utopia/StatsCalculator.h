
#ifndef UTOPIA_STATSCALCULATOR_H
#define UTOPIA_STATSCALCULATOR_H

#include "Constants.h"

class StatsCollector {
public:
	StatsCollector();
	~StatsCollector();
	long long GetMedian();
	long long GetAverage();

	void PushValue(int value);

	void Dump();

private:
	int * responseTimeArray[MAX_RESPONSE_SIZE_IN_MS] = { nullptr };
	long long *total;

private:
	int GetNext(int index);
};


#endif //UTOPIA_STATSCALCULATOR_H
