#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    if(n & 1){
        cout << -1 << "\n";
        return;
    }
    int a = n, b = 1;
    vector<int> v(n+1);
    for(int i = 1; i <= (n / 2); i++){
        if(i & 1){
            v[i] = a--;
            v[n-i+1] = a--;
        }
        else{
            v[i] = b++;
            v[n-i+1] = b++;
        }
    }
    for(int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}