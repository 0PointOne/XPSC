#include<bits/stdc++.h>
#define int long long int
using namespace std;

bool isMul(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return true;
    }return false;
}

void solve(){
    int l, r;   cin >> l >> r;

    while(l <= r){
        if(isMul(l)){

            int s = 2, e = l - 2;
            while(s <= e){
                if(__gcd(s, e) > 1){
                    cout << s << " " << e << "\n";
                    return;
                }
                s++;
                e--;
            }
        }
        l++;
    }
    cout << -1 << "\n";
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