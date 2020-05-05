/*	
*	Author : aahcbird
*	Created : 19/05/26
*/
#include <cstdio>

double sqrt(double num) {
	int digit = 0;
	double tmp = num;
	double ret = 1;

	while (tmp >= 1) {
		++digit;
		tmp /= 10;
	}

	digit /= 2;

	while (digit != 0) {
		--digit;
		ret *= 10;
	}

	for (int i = 0; i < 6; ++i) {
		ret = (ret + num / ret) / 2;
	}

	return ret;
}