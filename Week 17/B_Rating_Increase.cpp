#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    string s;   cin >> s;

    string a = ""; a += s[0];
    string b = "";
    int i = 1;
    int addfrom = 0;
    while(i < s.size()){
        if(s[i] != '0'){
            addfrom = i;
            b += s[i];
            i++;
            while(i < s.size()){
                b += s[i++];
            }
        }
        i++;
    }

    for(int i = 1; i < addfrom; i++)  a += s[i];

    if(a.size() == b.size()){
        for(int i = 0; i < a.size(); i++){
            if(b[i] == a[i]) continue;
            else if(b[i] > a[i]){
                cout << a << " " << b << "\n";
                return;
            }
            if(b[i] < a[i]){
                cout << -1 << "\n";
                return;
            }
        }
        cout << -1 << "\n";
    }
    else if(a.size() > b.size()) cout << -1 << "\n";
    else   cout << a << " " << b << "\n";
    

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}