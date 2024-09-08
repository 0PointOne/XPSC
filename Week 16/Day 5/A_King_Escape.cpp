#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    int qx, qy; cin >> qx >> qy;
    int kx, ky; cin >> kx >> ky;
    int cx, cy; cin >> cx >> cy;

    if(qx == kx || qx == cx || qy == ky || qy == cy){
        cout << "NO";
        return;
    }

    int tx = qx, ty = qy;
    while(tx <= n && ty <= n){
        if(cx == tx && cy == ty){
            cout << "NO";
            return;
        }
        tx++, ty++;
    }
    tx = qx, ty = qy;
    while(tx >= 0 && ty >= 0){
        if(cx == tx && cy == ty){
            cout << "NO";
            return;
        }
        tx--, ty--;
    }

    tx = qx, ty = qy;
    while(tx >= 0 && ty <= n){
        if(tx == cx && ty == cy){
            cout << "NO";
            return;
        }
        tx--;
        ty++;
    }
    tx = qx, ty = qy;
    while(tx <= n && ty >= 0){
        if(tx == cx && ty == cy){
            cout << "NO";
            return;
        }
        tx++;
        ty--;
    }

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