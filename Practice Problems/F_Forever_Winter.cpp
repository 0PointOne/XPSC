#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


void solve(){

    int n, m;   cin >> n >> m;
    vector<int> adj[n+1];
    while(m--){
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lef = 0;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1){
            lef = i;
            break;
        }
    }

    int cnt = 0;
    int src = adj[lef][0];
    int mid = -1;
    for(int i = 0; i < adj[src].size(); i++){
        if(adj[adj[src][i]].size() != 1){
            mid = adj[src][i];
        }
    }
    if(mid == -1){
        cout << 1 << " " << adj[src].size()-1 << "\n";
    }
    else cout << adj[mid].size() << " " << adj[src].size()-1 << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}