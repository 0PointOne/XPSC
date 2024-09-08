#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    if(v[0] != 0){
        cout << 1 << "\n";
        return;
    }

    int st = 0;
    for(int i = 1; i < n; i++){
        if(v[i] <= st) continue;
        if(v[i] - 1 == st) st++;
        else{
            cout << i+1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}