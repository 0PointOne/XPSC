#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    string s;   cin >> s;
    if(s[0] == '9'){
        string ans = "";
        int ca = 0;
        for(int i = n-1; i >= 0; i--){
            int x = s[i] - '0' + ca;
            if(x > 1) ans += 11 - x + '0', ca = 1;
            else      ans += 1 - x + '0', ca = 0;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else{
        for(int i = 0; i < n; i++) cout << '9' - s[i];
    }
    cout << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}