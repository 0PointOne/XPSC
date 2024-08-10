#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, k;   cin >> n >> k;
    int l = 0, r = n;
    while(l < r){
        int mid = l + (r - l) / 2;
        int all = n * (n + 1) / 2;
        int sub = (n - mid) * (n - mid + 1) / 2;
        int curr = all - (all - sub) - mid;

        if(curr == k){
            cout << mid;
            return;
        }
        else if(curr > k)  l = mid;
        else               r = mid;
    }
    
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}