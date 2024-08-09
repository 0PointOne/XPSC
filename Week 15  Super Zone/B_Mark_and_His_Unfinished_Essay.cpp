#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, c, q;    cin >> n >> c >> q;
    string s;   cin >> s;
    vector<pair<int, int> > v, pos;

    int j = s.size();
    while(c--){
        int l, r;   cin >> l >> r;
        v.push_back({l, r});
        pos.push_back({j+1, j + r - l + 1});
        j += (r - l + 1);
    }

    while(q--){
        int k;  cin >> k;
        for(int i = pos.size()-1; i >= 0; i--){
            if(k <= n) break;
            if(k >= pos[i].first && k <= pos[i].second){
                k = v[i].first + k - pos[i].first;
            }
        }
        cout << s[k-1] << "\n";
    }

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}