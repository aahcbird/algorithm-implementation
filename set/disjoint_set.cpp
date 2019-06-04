/*	
*	Author : aahcbird
*	Created : 19/06/04
*/
#include <cstdio>

class dj_set {
public:
	dj_set(int n) {
		parent_ = new int[n+1];
		for (int i = 1; i <= n; ++i) {
			parent_[i] = i;
		}
		
		size_ = new int[n+1];
		for (int i = 1; i <= n; ++i) {
			size_[i] = 1;
		}
	}
	~dj_set() {
		delete []parent_;
		delete []size_;
	}

	void merge(int s1, int s2) {
		int r1 = find(s1);
		int r2 = find(s2);

		if (size_[r1] > size_[r2]) {
			parent_[r2] = r1;
			size_[r1] += size_[r2];
		}
		else {
			parent_[r1] = r2;
			size_[r2] += size_[r1];
		}
	}

	int find(int s) {
		if (parent_[s] == s) {
			return s;
		}
		else {
			return parent_[s] = find(parent_[s]); // path compression
		}
	}

	bool has_same_root(int s1, int s2) {
		return find(s1) == find(s2);
	}

	int *parent_;
	int *size_;
};