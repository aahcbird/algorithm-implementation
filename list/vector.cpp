#define max(x, y) (((x)>(y))?(x):(y))

template<typename T>
struct mvector {
	mvector() : cp(0), sz(0), buf(0) {}
	mvector(int cp) : cp(0), sz(0), buf(0) {
		reserve(cp, false);
	}
	mvector(int sz, const T &val) : cp(0), sz(0), buf(0) {
		assign(sz, val);
	}
	~mvector() {
		delete []buf;
	}

	void reserve(int cp, bool copy) {
		if (this->cp >= cp) return;
		T *tmp = new T[cp];
		if (copy) {
			for (int i=0; i<sz; ++i) {
				tmp[i] = buf[i];
			}
		}
		delete []buf;
		buf = tmp;
		this->cp = cp;
	}

	void assign(int sz, const T &val) {
		if (this->cp < sz) reserve(sz, false);
		for (int i=0; i<sz; ++i) {
			buf[i] = val;
		}
		this->sz = sz;
	}

	inline void push_back(const T &val) {
		if (cp == sz) reserve(max(8, cp*2), true);
		buf[sz++] = val;
	}

	inline void pop_back() {
		if (sz > 0) --sz;
	}

	inline T &back() {
		return buf[sz-1];
	}

	inline T &operator[](int idx) {
		return buf[idx];
	}

	inline T *begin() {
		return buf;
	}

	inline T *end() {
		return buf + sz;
	}

	inline int size() {
		return sz;
	}

	inline void clear() {
		sz = 0;
	}

	int cp; // capacity
	int sz; // size
	T *buf; // buffer array
};