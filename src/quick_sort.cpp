/*	
*	Author : aahcbird
*	Created : 19/05/24
*/
#include <cstdio>
#include <ctime>
#include <cstdlib>

void swap(int *p1, int *p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void insertion_sort(int *begin, int *end) {
	int *idx = begin;

	while (idx < end) {
		int *tmp = idx;
		while (tmp > begin && *tmp < *(tmp - 1)) {
			swap(tmp, tmp-1);
			--tmp;
		}
		++idx;
	}
}

void quick_sort(int *begin, int *end) {
	if (begin >= end) return;

	if (end - begin <= 15) {
		insertion_sort(begin, end);
		return;
	}

	// driver function must include "srand(time(0));"
	int rand_size = 7;
	int *rand_arr = new int[rand_size];

	for (int i = 0; i < rand_size; ++i) {
		rand_arr[i] = rand() % (end - begin);
	}
	insertion_sort(rand_arr, rand_arr + rand_size);

	swap(begin + rand_arr[rand_size/2], end - 1);

	delete []rand_arr;

	int *pivot = end - 1;
	int p_val = *pivot;
	int *left = begin;
	int *right = end - 1;

	while (left < right) {
		while (left < right && *left <= p_val) {
			++left;
		}
		while (left < right && *right >= p_val) {
			--right;
		}
		if (left < right) {
			swap(left, right);
		}
	}

	swap(left, pivot);

	quick_sort(begin, left);
	quick_sort(left+1, end);
}