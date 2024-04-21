#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define ll long long
#define s(a, b) a+b
#define v_all v.begin(), v.end()
#define mod 100000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print_v(v) for(auto it : v) cout << it << " "; cout << endl;
#define print_v_pair(v) for(auto it: v) cout << it.first << " " << it.second << endl;
#define input_v for(auto &it : v)   cin >> it;
using namespace std;
using namespace __gnu_pbds;
template<class T> using od_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    
    int n;  cin >> n;
    vector<int> pf(n);
    int k;  cin >> k;   
    pf[0] = k;

    for(int i = 1; i < n; i++){
        cin >> k;
        pf[i] = pf[i-1] + k;
    }

    // print_v(pf);

    int q;  cin >> q;
    while(q--){
        int m;  cin >> m;

        // number_of_pile(pf, int m);
        
        auto it = lower_bound(pf.begin(), pf.end(), m);

        int piles = it - pf.begin();

        cout << piles + 1 << endl;

    }
}

int main(){
    fast_io;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}