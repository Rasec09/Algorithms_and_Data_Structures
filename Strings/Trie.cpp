#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 30;

struct TrieNode {
	vector<TrieNode*> children;
	int prefix;
	bool isEndOfWord;

	TrieNode() : isEndOfWord(false), prefix(0) {
		children.assign(ALPHABET_SIZE, NULL);	
	}
};

struct Trie {
	
	TrieNode *root;

	Trie() : root(new TrieNode()) {}

	void insert(string &str) {
		TrieNode *current = root;
		current -> prefix++;
		for (int i = 0; i < str.size(); i++) {
			int idx = str[i] - 'a'; 
			if (current -> children[idx] == NULL) {
				current -> children[idx] = new TrieNode();
			}
			current = current -> children[idx];
			current -> prefix++;
		}
		current -> isEndOfWord = true;
	}

	bool search(string &str) {
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
