#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    int qx, qy; cin >> qx >> qy;
    int kx, ky; cin >> kx >> ky;
    int cx, cy; cin >> cx >> cy;

    if(cx < qx && cy < qy && kx < qx && ky < qy) cout << "YES";
    else if(cx > qx && cy > qy && kx > qx && ky > qy) cout << "YES";
    else if(cx > qx && cy < qy && kx > qx && ky < qy) cout << "YES";
    else if(cx < qx && cy > qy && kx < qx && ky > qy) cout << "YES";
    else cout << "NO";
}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}