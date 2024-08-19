#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    if(v[0] > n){
        cout << "NO" << "\n";
        return;
    }
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++)  b[v[i]-1]++;
    for(int i = n-2; i >= 0; i--)  b[i] += b[i+1];

    cout << (v == b ?  "YES"  :   "NO") << "\n";
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}