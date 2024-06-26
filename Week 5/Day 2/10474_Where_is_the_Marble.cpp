#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define int long long
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int b_s(vector<int> &v, int key){
    int s = 0, e = v.size()-1;
    int mid = (s + e) / 2;
    int ans = -1;
    while(s <= e){
        if(v[mid] == key){
            ans = mid + 1;
            e = mid - 1;
        }  
        else if(v[mid] < key)  s = mid + 1;
        else                   e = mid - 1;

        mid = (s + e) / 2;
    }
    return ans;
}

void solve(){

    int cnt = 1;
    while(1){
        int n, q;   cin >> n >> q;
        if(n == 0 && q == 0) return;

        vector<int> v(n);
        for(int i = 0; i < n; i++)  cin >> v[i];
        sort(all(v));

        cout << "CASE# " << cnt << ":" << nline;

        while(q--){
            int key;    cin >> key;
            int ans = b_s(v, key);
            if(ans != -1){
                cout << key << " found at " << ans << nline;
            }
            else{
                cout << key << " not found" << nline;
            }
        }
        cnt++;
    }
    
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    int t = 1;   	
    // cin >> t;
    while(t--){     solve(); }
    return 0;
}