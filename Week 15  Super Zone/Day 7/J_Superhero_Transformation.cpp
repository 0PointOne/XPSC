#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    string s, t;    cin >> s >> t;

    auto isVowel = [&](char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    };
    if(s.size() == t.size()){
        for(int i = 0; i < s.size(); i++){
            if((isVowel(s[i]) && isVowel(t[i])) || (!isVowel(s[i]) && !isVowel(t[i])) ) continue;
            else{
                cout << "No";
                return;
            }
        }
        cout << "Yes";
        return;
    }
    cout <<  "No";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}