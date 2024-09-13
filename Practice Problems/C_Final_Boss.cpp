#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int h, n;   cin >> h >> n;
    vector<int> d(n), c(n);
    for(int i = 0; i < n; i++) cin >> d[i], h -= d[i];
    for(int i = 0; i < n; i++)  cin >> c[i];

    if(h <= 0){
        cout << 1 << endl;
        return;
    }

    auto Tot = [&](int k){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (k / c[i]) * d[i];
            if(sum >= h) break;
        }

        return sum;
    };

    int l = 0, r = 1e12;
    int ans = 0;
    int mid = l + (r - l) / 2;
    while(l <= r){

        if(h - Tot(mid) <= 0)  ans = mid, r = mid - 1;
        else                    l = mid + 1;

        mid = l + (r - l) / 2;
    }

    cout << ans + 1 << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}