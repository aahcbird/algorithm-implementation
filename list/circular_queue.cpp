/*	
*	Author : aahcbird
*	Created : 19/05/31
*/
#include <cstdio>

template <typename T>
class c_queue {
public:
	
	class node {
	public:
		node(T val) : val_(val), prev_(NULL), next_(NULL) {}
		~node() {}

		node *prev_;
		node *next_;
		T val_;
	};

	c_queue() : cur_(NULL), size_(0) {}
	~c_queue() {
		while (size_ != 0) {
			remove();
		}
	}

	void insert(T val) {
		node *tmp = new node(val);
		if (size_ == 0) {
			cur_ = tmp;
			cur_->prev_ = cur_;
			cur_->next_ = cur_;
		}
		else {
			tmp->prev_ = cur_->prev_;
			tmp->next_ = cur_;
			cur_->prev_->next_ = tmp;
			cur_->prev_ = tmp;
		}
		++size_;
	}

	void remove() {
		if (size_ == 1) {
			delete cur_;
			cur_ = NULL;
		}
		else {
			node *tmp = cur_->next_;
			cur_->next_->prev_ = cur_->prev_;
			cur_->prev_->next_ = cur_->next_;
			delete cur_;
			cur_ = tmp;
		}

		--size_;
	}

	void find(T val) {
		while (cur_->val_ != val) {
			cur_ = cur_->next_;
		}
	}

	int size() {
		return size_;
	}

	bool empty() {
		return size_ == 0;
	}

	node* cur_;
	int size_;
};