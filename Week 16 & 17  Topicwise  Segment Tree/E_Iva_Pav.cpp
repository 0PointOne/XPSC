#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e6;
int v[N], tr[4*N];

void build(int n, int l, int r){
    if(l == r){
        tr[n] = v[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*n, l, mid);
    build(2*n+1, mid+1, r);
    tr[n] = tr[2*n] & tr[2*n+1];
}

int and_(int n, int l, int r, int a, int b){
    if(r < a || l > b)   return (1 << 31) - 1;
    if(l >= a && r <= b) return tr[n];

    int mid = l + (r - l) / 2;
    return and_(2*n, l, mid, a, b) & and_(2*n+1, mid+1, r, a, b);
}

void solve(){


    int n;  cin >> n;
    for(int i = 1; i <= n; i++) v[i] = 0;
    for(int i = 1; i <= 4 * n; i++) tr[i] = (1 << 31) - 1;

    for(int i = 1; i <= n; i++)  cin >> v[i];
    build(1, 1, n);

    int q;  cin >> q;
    while(q--){
        int l, k;   cin >> l >> k;

        int s = l, e = n, ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(and_(1, 1, n, l, mid) >= k)  ans = mid,  s = mid + 1;
            else e = mid - 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}