/*	
*	Author : aahcbird
*	Created : 19/05/31
*/
#include <cstdio>

template <typename T>
class my_list {
public:
	
	class node {
	public:
		node(T val) : val_(val), prev_(NULL), next_(NULL) {}

		node *prev_;
		node *next_;
		T val_;
	};

	my_list() : front_(NULL), back_(NULL), size_(0) {}
	~my_list() {
		while (size_ != 0) {
			pop_back();
		}
	}

	void push_back(T val) {
		node *tmp = new node(val);
		if (back_ == NULL) {
			back_ = tmp;
			front_ = tmp;
		}
		else {
			back_->next_ = tmp;
			tmp->prev_ = back_;
			back_ = tmp;
		}
		++size_;
	}

	void pop_back() {
		if (back_->prev_ == NULL) {
			delete back_;
			front_ = NULL;
			back_ = NULL;
		}
		else {
			back_ = back_->prev_;
			delete back_->next_;
			back_->next_ = NULL;
		}
		--size_;
	}

	void erase(T val) {
		node *cur = find(val);
		if (cur->prev != NULL) {
			cur->prev->next = cur->next;
		}
		if (cur->next != NULL) {
			cur->next->prev = cur->prev;
		}
		if (front_ == back_) {
			delete cur;
			front_ = NULL;
			back_ = NULL;
		}
		else {
			if (cur == front_) {
				front_ = cur->next_;
			}
			if (cur == back_) {
				back_ = cur->prev_;
			}
		}
		delete cur;
		--size_;
	}

	node* find(T val) {
		node *cur = front_;
		while (cur != NULL) {
			if (cur->val_ == val) {
				return cur;
			}
			cur = cur->next_;
		}
		return NULL;
	}

	node *front_;
	node *back_;
	int size_;
};

template <typename T>
class unordered_set {
public:
	unordered_set(int t_size) : t_size_(t_size) {
		h_table_ = new my_list<T>[t_size];
	}

	~unordered_set() {
		delete []h_table_;
	}

	void insert(T val) {
		int idx = hash(val);
		h_table_[idx].push_back(val);
	}

	my_list<int>::node* find(T val) {
		int idx = hash(val);
		return h_table_[idx].find(val);
	}
	
	void erase(T val) {
		int idx = hash(val);
		h_table_[idx].erase(val);
	}

	int hash(T val) {
		return val % t_size_;
	}

	my_list<T> *h_table_;
	int t_size_;
};