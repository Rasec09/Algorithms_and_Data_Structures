#include <bits/stdc++.h>
using namespace std;

//Algoritmo Manber and Myers para construir suffix array
//Complejidad: O(n * (log n)^2)
struct SuffixArray {
	string s;
	vector<int> sa, rank;

	SuffixArray(const string &s) : s(s), sa(s.size()), rank(s.size()) {
		int n = s.size();
		for (int i = 0; i < n; i++)
			sa[i] = i, rank[i] = (int)s[i];
		vector<int> tmp(n);
		for (int h = 1; tmp[n - 1] != n - 1; h *= 2) {
			auto cmp = [&](int i, int j) {
				if (rank[i] != rank[j]) return rank[i] < rank[j];
				return (i + h < n && j + h < n ? rank[i + h] < rank[j + h] : i > j);
			};
			sort(sa.begin(), sa.end(), cmp);
			for (int i = 0; i < n - 1; i++)
				tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
			for (int i = 0; i < n; i++)
				rank[sa[i]] = tmp[i]; 
		}
	}

	//Para hallar el LCP de dos sufijos arbitrarios i y j
	//lcp(i, j) = min(lcp[i], lcp[i + 1], ..., lcp[j - 1])
	vector<int> buildLCP() {
        int n = s.size();
        vector<int> lcp(n - 1, 0);
        for (int i = 0, k = 0; i < n; i++) {
            if (rank[i] < n - 1) {
                int j = sa[rank[i] + 1];
                while (i + k < n && j + k < n && s[i + k] == s[j + k])
                    k++;
                lcp[rank[i]] = k;
                if (k)
                    k--;
            }
        }
        return lcp;
    }
};

int main() {
	
	int TC;   
    string str;

    cin >> TC;
    while (TC--) {
        cin >> str;
        SuffixArray suffixArray(str);
        vector<int> lcp = suffixArray.buildLCP();
        int total = str.size() * (str.size() + 1) / 2;
        for (int i = 0; i < lcp.size(); i++)
        	total -= lcp[i];
        cout << total << "\n";
    }
	return 0;
}
