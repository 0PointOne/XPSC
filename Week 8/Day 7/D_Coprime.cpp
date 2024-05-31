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

const int N = 1e3 + 1;
vector<int> coPr[N];

void solve(){

    int n;  cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i < n + 1; i++)  cin >> v[i];

    vector<int> Idx(N, -1);
    for(int i = 1; i <= n; i++){
        Idx[v[i]] = i;
    }
    
    int ans = -1;
    for(int i = 1; i < N; i++){
        if(Idx[i] == -1) continue;

        if(i == 1){
            ans = max(ans, Idx[i] * 2);
        }
        else{
            for(int j = 0; j < coPr[i].size(); j++){
                if(Idx[coPr[i][j]] != -1){
                    ans = max(ans, Idx[coPr[i][j]] + Idx[i]);
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            if(__gcd(i, j) == 1){
                coPr[i].pb(j);
            }
        }
    }


    int t = 1;   	
    cin >> t;
    while(t--){     solve(); }
    return 0;
}