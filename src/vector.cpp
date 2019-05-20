/*	
*	Author : aahcbird
*	Created : 19/05/20
*/
#include <cstdio>

template <typename T>
class my_vector {
public:
	my_vector() : cpct_(10), size_(0) {
		arr = new T[cpct_]();
	}
	my_vector(int cpct_) : cpct_(cpct_), size_(0) {
		arr = new T[cpct_]();
	}
	~my_vector() {
		delete []arr;
	}

	int size() {
		return size_;
	}

	void resize(int tmp_size) {
		T *tmp = new T[tmp_size]();
		for (int i = 0; i < size_; ++i) {
			tmp[i] = arr[i];
		}
		delete []arr;
		arr = tmp;
		cpct_ = tmp_size;
	}

	void clear() {
		delete []arr;
		
		cpct_ = 10;
		size_ = 0;
		arr = new T[cpct_]();
	}

	void push_back(T val) {
		if (cpct_ <= size_) {
			resize(cpct_*2);
		}

		arr[size_] = val;
		++size_;
	}

	void pop_back() {
		arr[size_-1] = 0;
		--size_;
	}

	T* begin() {
		return &arr[0];
	}

	T* end() {
		return &arr[0] + size_;
	}

	T operator [](int idx) {
		return arr[idx];
	}

	T *arr;
	int cpct_;
	int size_;
};