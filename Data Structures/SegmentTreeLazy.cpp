#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
typedef long long int ll;

ll arr[MAXN];

ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

struct Node {
	ll sum;
    
    void make_Node(ll v) {
        sum = v;
    }
	
	void merge(Node left, Node right) {
		sum = mod(left.sum + right.sum, 1000000009);
	}
	
	ll getValue() {
		return sum;
	}
};

struct SegmentTree {
	
	Node *stree;
    vector<ll> lazy;

	SegmentTree(int N) {
		stree = new Node[getSegmentTreeSize(N)];
        lazy.assign(getSegmentTreeSize(N), 1);
        buildTree(1, 0, N - 1);
	}

	void buildTree(int nodo, int L, int R) {
		if (L == R)
			stree[nodo].make_Node(arr[L]);
		else {
			int mid = (L + R) / 2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
			buildTree(leftIdx, L, mid);
			buildTree(rightIdx, mid + 1, R);
			stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
		}
	}

	void propagate(int nodo, int L, int R) {
		int leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
        if (lazy[nodo] != 1) {
        	stree[nodo].sum = mod(stree[nodo].sum * lazy[nodo], 1000000009);
        	if (L != R) {
                lazy[leftIdx] = mod(lazy[leftIdx] * lazy[nodo], 1000000009);
                lazy[rightIdx] = mod(lazy[rightIdx] * lazy[nodo], 1000000009);
            }
            lazy[nodo] = 1;
        }
	}

	Node query(int nodo, int L, int R, int i, int j) {
		propagate(nodo, L, R);
		if (L >= i && R <= j)
			return stree[nodo];
		
		int mid = (L + R) / 2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
		if (j <= mid)
			return query(leftIdx, L, mid, i, j);
		if (i > mid)
			return query(rightIdx, mid + 1, R, i, j);
        
		Node leftResult = query(leftIdx, L, mid, i, mid);
		Node rightResult = query(rightIdx, mid + 1, R, mid + 1, j);
		Node result;
		result.merge(leftResult, rightResult);
		return result;
	}

	void updateRange(int nodo, int low, int high, int startRange, int endRange, ll value) {
        propagate(nodo, low, high);
        if (low > high || startRange > high || endRange < low) {
            return;
        }
		int mid = (low + high) / 2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
		if (startRange <= low && endRange >= high) {
			stree[nodo].sum = mod(stree[nodo].sum * value, 1000000009);
			if (low != high) {
                lazy[leftIdx] = mod(lazy[leftIdx] * value, 1000000009);
                lazy[rightIdx] = mod(lazy[rightIdx] * value, 1000000009);
            }
            return;
		}
        updateRange(leftIdx, low, mid, startRange, endRange, value);
        updateRange(rightIdx, mid + 1, high, startRange, endRange, value);
		stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
	}

	int getSegmentTreeSize(int N) {
		int size = 1;
		for(; size < N; size <<= 1);
		return size << 1;
	}
};

int main() {
	
	int N, Q, l, r, opc;
	ll v;
    
    while (scanf("%d %d", &N, &Q) != EOF) {
	    fill(arr, arr + N, 1);
	    SegmentTree st(N);
	    while (Q--) {
	       	scanf("%d %d %d", &opc, &l, &r);
	       	if (r < l) swap(l, r);
	        if (opc == 0) {
	        	scanf("%lld", &v);
	            st.updateRange(1, 0, N - 1, l - 1, r - 1, v);
	        }
	        else {
	        	Node q = st.query(1, 0, N - 1, l - 1, r - 1);
	            printf("%lld\n", q.getValue());
	        }
	    }
    }
    return 0;
}
