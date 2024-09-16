#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    vector<int> temp = v;
    sort(temp.begin(), temp.end());

    if(temp == v) cout << 0 << "\n";
    else if(v[0] == 1 || v.back() == n) cout << 1 << "\n";
    else if(v[0] == n && v.back() == 1) cout << 3 << "\n";
    else cout << 2 << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}