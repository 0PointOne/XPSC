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
    tr[n] = tr[2*n] + tr[2*n+1];
}

void update(int n, int l, int r, int idx, int num){
    if(idx > r || idx < l) return;

    if(l == r){
        tr[n] += num;
        return;
    }
    int mid = l + (r - l) / 2;
    update(2*n, l, mid, idx, num);
    update(2*n+1, mid+1, r, idx, num);
    tr[n] = tr[2*n] + tr[2*n+1];
}

int empty(int n, int l, int r, int idx){
    if(idx > r || idx < l) return 0;
    if(l == r){
        return tr[n];
    }
    int mid = l + (r - l) / 2;
    return empty(2*n, l, mid, idx) + empty(2*n+1, mid+1, r, idx);
}

int sum(int n, int l, int r, int a, int b){
    if(r < a || l > b) return 0;
    if(l >= a && r <= b) return tr[n];

    int mid = l + (r - l) / 2;
    return sum(2*n, l, mid, a, b) + sum(2*n+1, mid+1, r, a, b);
}

void solve(){

    int n, q;   cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int idx;    cin >> idx;
            int val = empty(1, 1, n, idx+1);
            cout << val << "\n";
            update(1, 1, n, idx+1, val * -1);
        }
        else if(op == 2){
            int idx, val;   cin >> idx >> val;
            update(1, 1, n, idx+1, val);
        }
        else{
            int l, r;   cin >> l >> r;
            cout << sum(1, 1, n, l+1, r+1) << "\n";
        }

    }

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    int i = 0;
    while(i++ < t){
        memset(v, 0, sizeof(v));
        memset(tr, 0, sizeof(tr));

        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}