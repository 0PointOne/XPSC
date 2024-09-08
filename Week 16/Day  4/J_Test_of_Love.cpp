#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m, w;    cin >> n >> m >> w;
    string s;   cin >> s;

    int ju = m;
    for(int i = 0; i < n; i++){
        ju--;

        if(s[i] == 'W'){
        
            if(ju <= 0){
                if(w == 0){
                    cout << "NO" << "\n";
                    return;
                }
                w--;
            }
        }
        else if(s[i] == 'C' && ju <= 0){
            cout << "NO" << "\n";
            return;
        }
        else if(s[i] == 'L') ju = m;

    }
    cout << "YES" << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}