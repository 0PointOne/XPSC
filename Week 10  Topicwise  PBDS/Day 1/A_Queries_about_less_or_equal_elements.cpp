#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long int
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;  // less == set, less_equal == multiset;

signed main() {
    fast;

    int a, b;   cin >> a >> b;
    pbds<int> p;
    for(int i = 0; i < a; i++){
        int x;  cin >> x;
        p.insert(x);
    }

    while(b--){
        int x;  cin >> x;
        cout << p.order_of_key(x + 1) << " ";
    }

    return 0;
}