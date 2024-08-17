#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, x;   cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    vector<int> a(n+1, INT_MIN); a[0] = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += v[j];
            a[j-i+1] = max(sum, a[j-i+1]);
        }
    }

    for(int i = 0; i <= n; i++){
        int mx = 0;
        for(int j = 0; j <= n; j++){
            mx = max(mx, a[j] + min(i, j) * x);
        }
        cout << mx << " ";
    }cout << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}