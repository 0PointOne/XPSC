#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m, k, x;    cin >> n >> m >> k;
    set<int> a, b;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(x <= k) a.insert(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        if(x <= k) b.insert(x);
    }

    if(a.size() + b.size() < k || a.size() < k/2 || b.size() < k/2) cout << "NO\n";
    else{
        int SCnt = 0;
        for(auto it: a){
            if(b.find(it) != b.end()){
                SCnt++;
            }
        }
        int x = a.size() - SCnt, y = b.size() - SCnt;
        if(x < k / 2)   SCnt -= (k / 2 - x);
        if(y < k / 2)   SCnt -= (k / 2 - y);

        cout << (SCnt >= 0 ?  "YES"  :  "NO") << "\n";
    }
}
signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}