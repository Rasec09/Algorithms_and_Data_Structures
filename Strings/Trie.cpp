#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 30;

struct TrieNode {
	
	TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;

	TrieNode() : isEndOfWord(false) {
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
	}
};

struct Trie {
	
	TrieNode *root;

	Trie() : root(new TrieNode()) {}

	void insert(string str) {

		TrieNode *current = root;
		for (int i = 0; i < str.size(); i++) {
			int idx = str[i] - 'a'; 
			if (current -> children[idx] == NULL) {
				current -> children[idx] = new TrieNode();
			}
			current = current -> children[idx];
		}
		current -> isEndOfWord = true;
	}

	bool search(string str) {

		TrieNode* current = root;
		for (int i = 0; i < str.size(); i++) {
			int idx = str[i] - 'a';
			if (current -> children[idx] == NULL) {
				return false;
			}
			current = current -> children[idx];
		}
		return current -> isEndOfWord;
	}
};

int main() {
	
	int TC, n;
	string input;
	Trie trie;

	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> input;
			trie.insert(input);
		}
		cin >> input;
		cout << (trie.search(input) ? "1\n" : "0\n");
	}
	return 0;
}
