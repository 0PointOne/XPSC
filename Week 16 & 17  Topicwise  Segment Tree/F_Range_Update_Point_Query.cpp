#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m;   cin >> n >> m;
    vector<int> v(n+1);
    set<int> st;
    for(int i = 1; i <= n; i++)  cin >> v[i], st.insert(i);

    auto sum = [&](int num){
        int to = 0;
        while(num){
            to += num % 10;
            num /= 10;
        }
        return to;
    };

    while(m--){
        int op; cin >> op;
        if(op == 2){
            int idx;   cin >> idx;
            cout << v[idx] << "\n";
        }
        else{
            int l, r;   cin >> l >> r;
            if(st.empty()) continue;

            auto it = st.lower_bound(l);
            vector<int> rem;
            while(it != st.end() && (*it <= r)){
                if(v[*it] < 10) rem.push_back(*it);
                else{
                    v[*it] = sum(v[*it]);
                    if(v[*it] < 10) rem.push_back(*it);
                }
                it++;
            }

            for(int i = 0; i < rem.size(); i++){
                st.erase(st.find(rem[i]));
            }
        }
    }
    
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}