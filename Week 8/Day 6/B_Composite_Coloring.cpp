#include<bits/stdc++.h>
#define int long long int
using namespace std;

int slP(int n){
    for(int i = 2; i <= n; i++){
        if(n % i == 0) return i;
    }
    return 1;
}

void solve(){

    int n;  cin >> n;

    map<int, vector<int> > mp;
    for(int i = 0; i < n; i++){
        int num;    cin >> num;
        mp[slP(num)].push_back(i);
    }  

    cout << mp.size() << "\n";

    vector<int> ans(n);
    int k = 1;
    for(auto it: mp){
        for(auto j: it.second) ans[j] = k;

        k++; 
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << "\n";
    
}

signed main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}