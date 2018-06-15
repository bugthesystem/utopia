#ifndef UTOPIA_HELPERS_H
#define UTOPIA_HELPERS_H

#include "Constants.h"
#include <algorithm>

int RandomIntInRange(int min, int max) {
	return min +
		(rand() % static_cast<int>(max - min + 1));
}

#endif //UTOPIA_HELPERS_H