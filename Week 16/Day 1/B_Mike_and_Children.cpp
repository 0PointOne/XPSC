#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    map<int, int> mp;
    int mx = 1;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            mp[v[i]+v[j]]++;
            mx = max(mx, mp[v[i]+v[j]]);
        }
    }
    cout << mx << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}