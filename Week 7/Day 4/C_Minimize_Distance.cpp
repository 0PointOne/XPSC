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
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int num;    cin >> num;
        if(num > 0) a.pb(num);
        else        b.pb(-1 * num);
    }
    sort(all(a));
    sort(all(b));

    debug(a)
    debug(b)

    int dis = 0;
    for(int i = sz(a) - 1; i >= 0; i--){
        if(i == sz(a)-1){
            dis += a.back();
            i -= (k - 1);
        }
        else{
            dis += (a[i] * 2);
            i -= (k - 1);
        }
        debug(i)
    }
    debug(dis)
    for(int i = sz(b) - 1; i >= 0; i--){
        if(i == sz(b)-1){
            dis += b.back();
            i -= (k - 1);
        }
        else{
            dis += (b[i] * 2);
            i -= (k - 1);
        }
        debug(i)
    }
    
    if(a.size() > 0 && b.size() > 0){
        dis += min(a.back(), b.back());
    }
    cout << dis << nline;

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