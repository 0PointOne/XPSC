#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m, h;    cin >> n >> m >> h;

    vector<pair< pair<int,int>, int >> v;

    for(int i = 0; i < n; i++){

        vector<int> a(m);
        for(int j = 0; j < m; j++) cin >> a[j];
        sort(a.begin(), a.end());

        int sol = 0, pen = 0, t = 0;
        for(int j = 0; j < m; j++){

            if(t + a[j] <= h){
                t += a[j];
                pen += t;
                sol++;
            }
            else  break;
        }
        v.push_back({{sol, -pen}, -(i + 1)});
    }

    sort(v.begin(), v.end(),greater());

    for(int i = 0; i < n; i++){
        if(v[i].second == -1){
            cout << i + 1 << "\n";
            return;
        }
    }
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}