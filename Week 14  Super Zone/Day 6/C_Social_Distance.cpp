#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, k;   cin >> n >> k;
    string s;   cin >> s;
    bool isM = true;

    int ans = 0;
    int i = 0;
    int idx = 0;
    for(; i <= min(n-1, k); i++){
        if(s[i] == '1'){
            idx = i;
            isM = false;
            break;
        }
    }
    if(isM) ans++, i = 1, s[0] = '1';
    
    int cnt = 0;
    for(i = idx; i < n; i++){
        if(cnt == 2 * k + 1){
            ans++;
            cnt = k-1;
            s[i-k-1] = '1';
            idx = i - k - 1;
            i--;
        }
        if(s[i] == '1') cnt = 0, idx = i;
        else cnt++;

    }
    if(cnt > k) ans++, s[idx+k+1] = '1';

    isM = true;
    for(int i = n-1; i >= (n-k-1); i--){
        if(s[i] == '1') isM = false;
    }
    if(isM) ans++, s[n-1] = '1';

    cout << ans << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}