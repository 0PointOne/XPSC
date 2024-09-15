#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        int x;  cin >> x;
        mp[x] = max(mp[x], i);
    }
    
    int mx = -1;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            if(mp[i] && mp[j] && __gcd(i, j) == 1){
                mx = max(mx, mp[i] + mp[j]);
            }
        }
    }
    cout << mx << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}