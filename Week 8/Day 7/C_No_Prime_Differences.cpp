#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 10^6;
vector<bool> pr(N, true);

void solve(){
    
    int n, m;   cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));

    int s = 1, e = m;
    for(int i = 0; i < n; i++){
        iota(grid[i].begin(), grid[i].end(), s);
        s = e + 1;
        e = s + (m-1);
    }

    // if(!pr[grid[1][0] - grid[0][0]]){
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             cout << grid[i][j] << " ";
    //         }cout << "\n";
    //     }cout << "\n";
    //     return;
    // }
    // else{
        for(int i = 0; i < n; i++){
            if(i % 2 != 0){
                for(int j = 0; j < m; j++){
                    cout << grid[i][j] << " ";
                }cout << "\n";
            }
        }
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                for(int j = 0; j < m; j++){
                    cout << grid[i][j] << " ";
                }cout << "\n";
            }
        }
        cout << "\n";
    // }
}

signed main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);


    int t;
    cin >> t;
    pr[1] = false;
    for(int i = 2; i * i <= N; i++){
        if(pr[i]){
            for(int j = i * i; j <= N; j += i)   pr[j] = false;
        }
    }
    while(t--){
        solve();
    }
    
    return 0;
}