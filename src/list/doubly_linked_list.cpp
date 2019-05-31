/*	
 *	Author : aahcbird
 *	Created : 19/05/19
 */
#include <cstdio>

template <typename T>
class my_list {
public:
	class node {
	public:
		node(T val) : prev_(NULL), next_(NULL), val_(val) {}
		~node(){}

		node* prev_;
		node* next_;
		T val_;
	};

	my_list() : front_(NULL), back_(NULL), size_(0) {}
	~my_list(){
		while (back_ != NULL) {
			pop_back();
		}
	};

	void push_front(T val) {
		node* tmp = new node(val);
		if (front_ == NULL) {
			front_ = back_ = tmp;
		}
		else {
			front_->prev_ = tmp;
			tmp->next_ = front_;
			front_ = tmp;
		}
		++size_;
	}

	void pop_front() {
		node* tmp = front_->next_;
		delete front_;
		front_ = tmp;
		if (front_ == NULL) {
			back_ = NULL;
		}
		else {
			front_->prev_ = NULL;
		}
		--size_;
	}
	
	void push_back(T val) {
		node* tmp = new node(val);
		if (back_ == NULL) {
			front_ = back_ = tmp;
		}
		else {
			back_->next_ = tmp;
			tmp->prev_ = back_;
			back_ = tmp;
		}
		++size_;
	}

	void pop_back() {
		node* tmp = back_->prev_;
		delete back_;
		back_ = tmp;
		if (back_ == NULL) {
			front_ = NULL;
		}
		else {
			back_->next_ = NULL;
		}
		--size_;
	}

	T front() {
		return front_->val_;
	}

	T back() {
		return back_->val_;
	}

	int size() {
		return size_;
	}

	bool empty() {
		return size_ == 0;
	}

	node* front_;
	node* back_;
	int size_;
};