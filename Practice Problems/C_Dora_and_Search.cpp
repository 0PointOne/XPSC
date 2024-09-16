#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)  cin >> v[i];

    int mx = n, mn = 1;
    int s = 1, e = n;
    while(s <= e){
        if(v[s] == mn) s++, mn++;
        else if(v[e] == mn) e--, mn++;
        else if(v[s] == mx) s++, mx--;
        else if(v[e] == mx) e--, mx--;
        else{
            cout << s << " " << e << "\n";
            return;
        }
    }
    cout << -1 << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}