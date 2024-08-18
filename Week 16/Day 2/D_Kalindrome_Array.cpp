#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool check(vector<int> &v, int s, int e, int idx){
    
    while(s <= e){
        if(v[s] == v[idx])      s++;
        else if(v[e] == v[idx]) e--;
 
        else if(v[s] != v[e])   return false;
        else{
            s++;
            e--;
        }
    }
    return true;
}

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int s = 0, e = n-1;
    vector<int> a, b;
    bool isC = false;
    while(s <= e){

        if(v[s] != v[e]){
            if(check(v, s+1, e, s) || check(v, s, e-1, e)){
                cout << "YES" << "\n";
                return;
            }
            isC = true;
            break;
        }
        s++;
        e--;

    }

    cout << (isC ?   "NO" : "YES") << "\n";
    
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    int t = 1;   	
    cin >> t;
    while(t--){     solve(); }
    return 0;
}