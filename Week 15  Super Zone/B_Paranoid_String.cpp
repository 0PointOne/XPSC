#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    string s;   cin >> s;
    int cnt = n + (n * (n - 1) / 2);
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) cnt -= i;
    }
    cout << cnt << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}