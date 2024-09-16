#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, k;   cin >> n >> k;
    vector<int> v(n*k);
    for(int i = 0; i < n * k; i++) cin >> v[i];

    int sum = 0;
    int med = n / 2;

    for(int i = (n*k)-med-1; i >= 0, k-- > 0; i -= (med+1)){
        sum += v[i];
    }

    cout << sum << '\n';
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}