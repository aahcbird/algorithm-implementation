/*	
*	Author : aahcbird
*	Created : 19/05/23
*/
#include <cstdio>

class my_trie {
public:
	my_trie() : is_end_(false) {
		for (int i = 0; i < 26; ++i) {
			subtrie_[i] = NULL;
		}
	}

	~my_trie() {
		for (int i = 0; i < 26; ++i) {
			if (subtrie_[i] != NULL) {
				delete subtrie_[i];
			}
		}
	}

	void insert(const char* ch) {
		if (ch[0] == 0) {
			is_end_ = true;
			return;
		}

		int ch_i = (ch[0] >= 'a') ? ch[0] - 'a' : ch[0] - 'A';
		if (subtrie_[ch_i] == NULL)
			subtrie_[ch_i] = new my_trie();

		subtrie_[ch_i]->insert(ch+1);
	}

	my_trie* find(const char* ch) {
		if (ch[0] == 0) {
			return this;
		}

		int ch_i = (ch[0] >= 'a') ? ch[0] - 'a' : ch[0] - 'A';
		if (subtrie_[ch_i] == NULL)
			return NULL;
		return subtrie_[ch_i]->find(ch+1);
	}

	my_trie* subtrie_[26];
	bool is_end_;
};