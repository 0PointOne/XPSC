#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define int long long int
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // less == set, less_equal == multiset;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
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

void solve(){

    int n, k;   cin >> n >> k;
    vector<int> v(n + 1), vis(n + 1);

    int t = 1;
    vector<int> a;
    for(int i = 1; i <= n; i += k){
        v[i] = t++;
        a.pb(i);
        vis[i] = true;
    }
    debug(a)

    vector<int> b;
    while(t <= n){

        for(int i = a.size()-1; i >= 0; i--){
            if(a[i] + 1 > n || vis[a[i] + 1]) continue;
            else{
                v[a[i] + 1] = t++;
                b.pb(a[i] + 1);
                vis[a[i] + 1] = true;
            }
        }
        if(t > n) break;
        a.clear();

        for(int i = b.size()-1; i >= 0; i--){
            if(b[i] + 1 > n || vis[b[i] + 1]) continue;
            else{
                v[b[i] + 1] = t++;
                a.pb(b[i] + 1);
                vis[b[i] + 1] = true;
            }
        }
        b.clear();
    }
    for(int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << "\n";

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