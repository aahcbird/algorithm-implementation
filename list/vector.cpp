template <typename T>
class my_vector {
public:
	my_vector() : my_vector(10) {}
	my_vector(int cpct) : cpct_(cpct), size_(0) {
		arr_ = new T[cpct_]();
	}
	~my_vector() {
		delete []arr_;
	}

	int size() {
		return size_;
	}

	void reserve(int new_cpct) {
		cpct_ = new_cpct;
		T *tmp = new T[new_cpct]();
		for (int i = 0; i < size_; ++i) {
			tmp[i] = arr_[i];
		}
		delete []arr_;
		arr_ = tmp;
	}

	void clear() {
		delete []arr_;

		cpct_ = 10;
		size_ = 0;
		arr_ = new T[cpct_]();
	}

	void push_back(const T &val) {
		if (cpct_ <= size_) {
			reserve(cpct_ * 2);
		}

		arr_[size_] = val;
		++size_;
	}

	void pop_back() {
		--size_;
	}

	T* begin() {
		return arr_;
	}

	T* end() {
		return arr_ + size_;
	}

	T& operator [](int idx) {
		return arr_[idx];
	}

	T *arr_;
	int cpct_;
	int size_;
};