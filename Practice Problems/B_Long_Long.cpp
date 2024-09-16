#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    int sum = 0, cnt = 0;
    bool change = false;
    for(int i = 0; i < n; i++){
        if(!change && v[i] < 0) cnt++, change = true;
        else if(v[i] > 0) change = false;

        if(v[i] < 0) v[i] *= -1;
        sum += v[i];
    }
    cout << sum << " " << cnt << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}