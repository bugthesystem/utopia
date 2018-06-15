
#ifndef UTOPIA_STATSCALCULATOR_H
#define UTOPIA_STATSCALCULATOR_H

#include "Constants.h"

class StatsCalculator {
public:
	StatsCalculator();
	~StatsCalculator();
	long long GetMedian();
	long long GetAverage();

	void PushValue(int value);

	void Dump();

private:
	
	int * responseTimeArray[MAX_RESPONSE_SIZE_IN_MS] = { nullptr };
	long long *total = nullptr;
};


#endif //UTOPIA_STATSCALCULATOR_H
