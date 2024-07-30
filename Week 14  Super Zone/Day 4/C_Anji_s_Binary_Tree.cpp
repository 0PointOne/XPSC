#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    string s;   cin >> s;

    vector<int> adj[n];
    for(int i = 0; i < n; i++){
        int l, r;   cin >> l >> r;
        l--;
        r--;
        adj[i].push_back(l);
        adj[i].push_back(r);
    }

    // for(int i = 0; i < n; i++){
    //     cout << adj[i][0] << " " << adj[i][1] << "\n";
    // }cout << "\n";


    queue<pair<int, int> > q;
    q.push({0, 0});

    int mn = INT_MAX;
    while(!q.empty()){
        
        auto [v, cnt] = q.front();
        q.pop();

        if(adj[v][0] == -1 && adj[v][1] == -1) mn = min(mn, cnt);

        else{
            if(adj[v][0] != -1){
                // cout << s[v] << "\n";
                if(s[v] == 'L') q.push({adj[v][0], cnt});
                else            q.push({adj[v][0], cnt+1});
            }
            if(adj[v][1] != -1){
                // cout << s[v] << "\n";
                if(s[v] == 'R') q.push({adj[v][1], cnt});
                else            q.push({adj[v][1], cnt+1});
            }
        }

    }

    cout << mn << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}