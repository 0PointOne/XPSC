#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N], tr[4*N];

void build(int n, int l, int r){
    if(l == r){
        tr[n] = v[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*n, l, mid);
    build(2*n+1, mid+1, r);

    tr[n] = __gcd(tr[2*n], tr[2*n+1]);
}

int ans(int n, int l, int r, int a, int b){
    if(l > b || r < a) return 0;
    else if(l >= a && r <= b) return tr[n];
    int mid = l + (r - l) / 2;
    
    return __gcd(ans(2*n, l, mid, a, b), ans(2*n+1, mid+1, r, a, b));
}

void solve(){

    int n;  cin >> n;
    int mn = INT_MAX;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] == 1) mn = 1;
    }
    if(mn == 1){
        cout << 1 << "\n";
        return;
    }

    int gcd_ = v[1];
    for(int i = 1; i <= n; i++){
        gcd_ = __gcd(v[i], gcd_);
    }
    if(gcd_ != 1){
        cout << -1 << "\n";
        return;
    }

    build(1, 1, n);
    int i = 1, j = 1;
    while(i <= j && j <= n){
        gcd_ = ans(1, 1, n, i, j);
        if(gcd_ == 1){
            mn = min(mn, j - i + 1);
            i++;
        }
        else j++;
    }

    cout << mn << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}