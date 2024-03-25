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
    vector<int> v(n);

    int mx = INT_MIN;
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;

        if(mp[v[i]] > mx){
            mx = mp[v[i]];
        } 
    }
    int others = n - mx;
    int op = 0;
    while(others > 0){
        op++;
        op += min(others, mx);
        others -= mx;
        mx *= 2;
    }
    cout << op << endl;
}

int main(){
    fast_io;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}