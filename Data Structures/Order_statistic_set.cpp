#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
int main() {
    optimizar_io
    int n, q, x;
    ordered_set orderedSet;
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        orderedSet.insert(x);
    }
    while (q--) {
        cin >> x;
        if (x > 0) {
            orderedSet.insert(x);
        }
        else {
            x *= -1;
            int num = *orderedSet.find_by_order(x - 1);
            auto it = orderedSet.upper_bound(num);
            orderedSet.erase(it);
        }
    }
    if (orderedSet.empty())
        cout << "0\n";
    else
        cout << *orderedSet.find_by_order(0) << "\n";
    return 0;
}
