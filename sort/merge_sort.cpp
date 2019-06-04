/*	
*	Author : aahcbird
*	Created : 19/06/04
*/
#include <cstdio>

bool cmp(int &a, int &b) {
	return a < b;
}

template <typename It, typename Comp>
void merge(It *begin, It *mid, It *end, Comp cmp) {
	It *le = begin;
	It *ri = mid;

	It *tmp = new It[end-begin];
	int i = 0;
	while (le < mid && ri < end) {
		if (cmp(*le, *ri)) {
			tmp[i] = *le;
			++i; ++le;
		}
		else {
			tmp[i] = *ri;
			++i; ++ri;
		}
	}

	while (le < mid) {
		tmp[i] = *le;
		++i; ++le;
	}

	while (ri < end) {
		tmp[i] = *ri;
		++i; ++ri;
	}

	le = begin;
	for (int i = 0; i < end - begin; ++i, ++le) {
		*le = tmp[i];
	}
	delete []tmp;
}

template <typename It, typename Comp>
void merge_sort(It *begin, It *end, Comp cmp) {
	if (begin >= end-1) return;

	It *mid = begin + (end-begin)/2;

	merge_sort(begin, mid, cmp);
	merge_sort(mid, end, cmp);
	merge(begin, mid, end, cmp);
}