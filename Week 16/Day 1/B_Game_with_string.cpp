#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    string s;   cin >> s;

    int cnt = 0;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            cnt++;
            if(i+2 < s.size()) s.erase(s.begin()+i, s.begin()+i+2);
            else break;
            i -= 2;
            if(i < -1) i++;
        }
    }
    cout << (cnt & 1 ?  "Yes"  :  "No") << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}