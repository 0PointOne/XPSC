#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m;   cin >> n >> m;
    string s, t;    cin >> s >> t;

    int op = 0;
    while(1){
        if(s.find(t) != string::npos) break;
        if(s.size() > t.size()*4 && op > 3){
            cout << -1 << "\n";
            return;
        }
        s += s;
        op++;
    }
    cout << op << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}