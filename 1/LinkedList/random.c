#include <stdlib.h>
#include "random.h"

float random_float(const float min, const float max)
{
	return ((float)rand() / RAND_MAX) * (max - min + 1) + min;
}