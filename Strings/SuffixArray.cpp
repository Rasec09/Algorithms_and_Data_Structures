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
	//lcp(i, j) = min(lcp[i + 1], lcp[i + 2], ..., lcp[j])
	vector<int> buildLCP() {
		int n = s.size();
		vector<int> lcp(n);
		for (int i = 0, k = 0; i < n - 1; i++) {
		    int j = sa[rank[i] - 1];
		    while (s[i + k] == s[j + k]) k++;
		    lcp[rank[i]] = k;
		    if (k) k--;
		}
		return lcp;
    }
};

int lowerbound(const SuffixArray &SA, const string &p) {
	int n = SA.s.size(), low = 0, hig = n;
	while (low < hig) {
		int mid = (low + hig) / 2;
		int res = SA.s.compare(SA.sa[mid], p.size(), p);
		if (res >= 0)
			hig = mid;
		else
			low = mid + 1;
	}
	return low;
}

int upperbound(const SuffixArray &SA, const string &p) {
	int n = SA.s.size(), low = 0, hig = n;
	while (low < hig) {
		int mid = (low + hig) / 2;
		int res = SA.s.compare(SA.sa[mid], p.size(), p);
		if (res <= 0)
			low = mid + 1;
		else
			hig = mid;
	}
	return low;
}

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
