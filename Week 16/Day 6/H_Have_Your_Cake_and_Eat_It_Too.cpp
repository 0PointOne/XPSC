#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        b[i] += b[i-1];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        c[i] += c[i-1];
    }

    vector<int> ans;    
    int div = (a.back() + 2 ) / 3;

    auto isPos = [&](vector<int>& x, vector<int>& y, vector<int>& z){

        auto it = lower_bound(x.begin(), x.end(), div);
        if(it == x.end()) return false;
        int idx = it - x.begin();

        auto it1 = lower_bound(y.begin(), y.end(), div + y[idx]);
        if(it1 == y.end()) return false;
        int idx1 = it1 - y.begin();

        auto it2 = lower_bound(z.begin(), z.end(), div + z[idx1]);
        if(it2 == z.end()) return false;

        ans = {1, idx, idx+1, idx1, idx1 + 1, n};
        return true;
    };


    if(isPos(a, b, c)){
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << "\n";
    }
    else if(isPos(a, c, b)){
        cout << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3] << "\n";
    }
    else if(isPos(b, a, c)){
        cout << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5] << "\n";
    }
    else if(isPos(b, c, a)){
        cout << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
    }
    else if(isPos(c, a, b)){
        cout << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1] << "\n";
    }
    else if(isPos(c, b, a)){
        cout << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1] << "\n";
    }
    else cout << -1 << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}