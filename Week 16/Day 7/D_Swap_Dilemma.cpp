#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++)  cin >> a[i], a[i]--;
    for(int i = 0; i < n; i++)  cin >> b[i], b[i]--;

    
    vector<int> x = a; vector<int> y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
 

    if(x != y){
        cout << "NO\n";
        return;
    }

    auto count = [&](vector<int>& z){

        vector<int> vis(n);
        int cnt = n % 2;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = z[j];
            }
            cnt ^= 1;
        }
        return cnt;
    };

    for(int i = 0; i < n; i++){
        a[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
    }

    for(int i = 0; i < n; i++){
        b[i] = lower_bound(y.begin(), y.end(), b[i]) - y.begin();
    }

    if(count(a) == count(b))     cout << "YES\n";
    else                          cout << "NO\n";
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}