#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        mp[31 - __builtin_clz(x)]++;
    }

    int ans = 0;
    for(auto [x, cnt]: mp){
        ans += (cnt * (cnt - 1) / 2);
    }
    cout << ans << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}