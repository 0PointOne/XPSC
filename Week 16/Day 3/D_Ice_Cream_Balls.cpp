#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    int l = 0, r = 1e10, ans = 0;
    while(l <= r){

        int mid = l + (r - l) / 2;

        if(mid * (mid + 1) / 2 <= n){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    int t = ans;
    ans += (n - (t * (t + 1) / 2));

    cout << ans + 1 << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}