#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int cnt(string s, char ch){
    int op = 0;
    string temp = "";
    while(1){
        int i = 0;
        while(i < s.size() && s[i] == ch) temp += s[i], i++;
         
        while(i < s.size()){
            int j = i;
            while(j < s.size() && s[j] == ch)  temp += s[j++];
            if(i == j){
                i++;
                if(i < s.size()) temp += s[i++];
            }
            else i = j;
        }
        if(temp.size() != s.size())  op++;
        else   break;
        s = temp;
        temp = "";
    }
    return op;
}

void solve(){

    string s;   cin >> s;
    vector<int> fr(26, 0);
    for(int i = 0; i < s.size(); i++)   fr[s[i] - 'a']++;

    int op = INT_MAX;
    for(int i = 0; i < 26; i++){
        if(fr[i]){
            op = min(op, cnt(s, char(i + 'a')));
        }
    }
    cout << op << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}