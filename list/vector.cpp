/*	
*	Author : aahcbird
*	Created : 19/05/20
*/
#include <cstdio>

template <typename T>
class my_vector {
public:
	my_vector() : cpct_(10), size_(0) {
		arr_ = new T[cpct_]();
	}
	my_vector(int cpct) : cpct_(cpct), size_(0) {
		arr_ = new T[cpct_]();
	}
	~my_vector() {
		delete []arr_;
	}

	int size() {
		return size_;
	}

	void resize(int tmp_size) {
		T *tmp = new T[tmp_size]();
		for (int i = 0; i < size_; ++i) {
			tmp[i] = arr_[i];
		}
		delete []arr_;
		arr_ = tmp;
		cpct_ = tmp_size;
	}

	void clear() {
		delete []arr_;
		
		cpct_ = 10;
		size_ = 0;
		arr_ = new T[cpct_]();
	}

	void push_back(T val) {
		if (cpct_ <= size_) {
			resize(cpct_*2);
		}

		arr_[size_] = val;
		++size_;
	}

	void pop_back() {
		arr_[size_-1] = 0;
		--size_;
	}

	T* begin() {
		return &arr_[0];
	}

	T* end() {
		return &arr_[0] + size_;
	}

	T operator [](int idx) {
		return arr_[idx];
	}

	T *arr_;
	int cpct_;
	int size_;
};