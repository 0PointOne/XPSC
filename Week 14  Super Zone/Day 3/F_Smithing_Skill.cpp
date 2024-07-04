#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

map<int, int> dp;
int expri(int mat, vector<pair<int, int> > &v){
    
    if(dp.count(mat)) return dp[mat];

    int l = 0, r = v.size()-1;
    int idx = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid].second <= mat){
            idx = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(idx == -1){
        return dp[mat] = 0;
    }

    int p = (mat - v[idx].second) / v[idx].first + 1;

    int rem = mat - (p * v[idx].first);
    int ans = p * 2 + expri(rem, v);
    return dp[mat] = ans;

}

signed main(){
    fast;
    int n, m;   cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    vector<pair<int, int> > b(n);
    for(int i = 0; i < n; i++){
        int r;  cin >> r;
        b[i] = {a[i]-r, a[i]};
    }

    sort(b.begin(), b.end());

    vector<pair<int, int> > v;
    v.push_back(b[0]);
    for(int i = 1; i < n; i++){
        if(v.back().second > b[i].second) v.push_back(b[i]);
    }
    b = v;
    vector<int> c(m);
    for(int i = 0; i < m; i++)  cin >> c[i];
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        int res = expri(c[i], b);
        ans += res;
    }
    cout << ans << "\n";
    return 0;
}