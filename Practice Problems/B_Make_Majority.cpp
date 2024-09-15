#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    string s;   cin >> s;

    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            one++;
        }
        if(s[i] == '0'){
            while(i < n && s[i] == '0') i++;
            i--;
            zero++;
        }
    }

    cout << (one > zero ? "Yes" : "No") << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}