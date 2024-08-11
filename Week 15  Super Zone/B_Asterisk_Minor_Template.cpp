#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    string s, t;    cin >> s >> t;
    if(s == t){
        cout << "YES" << "\n";
        cout << s << "\n";
        return;
    }
    if(s[0] == t[0]){
        cout << "YES" << "\n";
        cout << s[0] << "*\n";
        return;
    }
    if(s.back() == t.back()){
        cout << "YES" << "\n";
        cout << "*" << t.back() << "\n";
        return;
    }
    for(int i = 0; i < s.size()-1; i++){
        for(int j = 0; j < t.size()-1; j++){
            if(s[i] == t[j] && s[i+1] == t[j+1]){
                cout << "YES" << "\n";
                cout << "*" << s[i] << s[i+1] << "*" << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}