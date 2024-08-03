#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++)  cin >> v[i], mp[v[i]]++;

    int cnt = 0;
    for(auto [x, y]: mp){
        cnt += (y * (y - 1)) / 2;
    }

    cnt += (mp[1] * mp[2]);
    cout << cnt << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}