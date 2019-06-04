/*	
*	Author : aahcbird
*	Created : 19/06/04
*/
#include <cstdio>
#include <ctime>
#include <cstdlib>

bool cmp(int &a, int &b) {
	return a < b;
}

template <typename It>
void swap(It *p1, It *p2) {
	It tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

template <typename It, typename Comp>
void insertion_sort(It *begin, It *end, Comp cmp) {
	It *idx = begin;

	while (idx < end) {
		It *tmp = idx;
		while (tmp > begin && *tmp < *(tmp - 1)) {
			swap(tmp, tmp-1);
			--tmp;
		}
		++idx;
	}
}

template <typename It, typename Comp>
void quick_sort(It *begin, It *end, Comp cmp) {
	if (begin >= end) return;

	if (end - begin <= 15) {
		insertion_sort(begin, end, cmp);
		return;
	}

	// driver function must include "srand(time(0));"
	int rand_size = 7;
	int *rand_arr = new int[rand_size];

	for (int i = 0; i < rand_size; ++i) {
		rand_arr[i] = rand() % (end - begin);
	}
	insertion_sort(rand_arr, rand_arr + rand_size, cmp);

	swap(begin + rand_arr[rand_size/2], end - 1);

	delete []rand_arr;

	It *pivot = end - 1;
	It p_val = *pivot;
	It *left = begin;
	It *right = end - 1;

	while (left < right) {
		while (left < right && !cmp(p_val, *left)) {
			++left;
		}
		while (left < right && !cmp(*right, p_val)) {
			--right;
		}
		if (left < right) {
			swap(left, right);
		}
	}

	swap(left, pivot);

	quick_sort(begin, left, cmp);
	quick_sort(left+1, end, cmp);
}