#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    vector<int> v(n);
    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);

    int k = 0;
    for(int i = 1; i < n; i++){
        cin >> v[i];
        if(st.count(v[i] - v[i-1]))  st.erase(v[i] - v[i-1]);
        else  k = v[i] - v[i-1];
    }

    if((st.size() == 2 && (*st.begin()) + (*st.rbegin()) == k) || (st.size() == 1))   cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}