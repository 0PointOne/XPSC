#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    vector<int> ans(n, n);
    for(int i = n-2; i >= 0; i--){
        if(v[i] == v[i+1]) ans[i] = ans[i+1];
        else               ans[i] = i + 1;
    }

    int q;  cin >> q;
    while(q--){
        int l, r;   cin >> l >> r;
        if(ans[l-1] > r-1){
            cout << -1 << " " << -1 << "\n";
        }
        else{
            cout << l << " " << ans[l-1] + 1 << "\n";
        }
    }
    cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}