/*	
*	Author : aahcbird
*	Created : 19/05/26
*/
#include <cstdio>

int gcd(int num1, int num2) {
	int tmp = -1;
	while (tmp != 0) {
		tmp = num1 % num2;
		num1 = num2;
		num2 = tmp;
	}

	return num1;
}

int lcm(int num1, int num2) {
	return num1 * num2 / gcd(num1, num2);
}