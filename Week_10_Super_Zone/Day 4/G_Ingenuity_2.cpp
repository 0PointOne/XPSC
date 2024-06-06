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

    int sz;  cin >> sz;
    string str;   cin >> str;
    vector<int> N, S, E, W;
    for(int i = 0; i < sz; i++){
        if(str[i] == 'N') N.pb(i);
        if(str[i] == 'S') S.pb(i);
        if(str[i] == 'E') E.pb(i);
        if(str[i] == 'W') W.pb(i);
    }

    int n = 0, s = 0, e = 0, w = 0;
    int r_cnt = 0, h_cnt = 0;
    string ans = str;
    for(int i = 0; i < sz; i++){
        if(str[i] == 'N'){
            if(ans[i] == 'N' && s < S.size() ){
                if(r_cnt == 0){
                    ans[N[n++]] = 'R';
                    ans[S[s++]] = 'R';
                    r_cnt++;
                }
                else{
                    ans[N[n++]] = 'H';
                    ans[S[s++]] = 'H';
                    h_cnt++;
                }
            }
            else if(ans[i] == 'N' && n + 1 < N.size()){
                ans[N[n++]] = 'R', r_cnt++;
                ans[N[n++]] = 'H', h_cnt++;
            }
        }
        else if(str[i] == 'S'){
            if(ans[i] == 'S' && n < N.size() ){

                if(r_cnt == 0){
                    ans[S[s++]] = 'R';
                    ans[N[n++]] = 'R';
                    r_cnt++;
                }
                else{
                    ans[S[s++]] = 'H';
                    ans[N[n++]] = 'H';
                    h_cnt++;
                }
            }
            else if(ans[i] == 'S' && s + 1 < S.size()){
                ans[S[s++]] = 'R', r_cnt++;
                ans[S[s++]] = 'H', h_cnt++;
            }
        }
        else if(str[i] == 'E'){
            if(ans[i] == 'E' && w < W.size() ){

                if(r_cnt == 0){
                    ans[E[e++]] = 'R';
                    ans[W[w++]] = 'R';
                    r_cnt++;
                }
                else{
                    ans[E[e++]] = 'H';
                    ans[W[w++]] = 'H';
                    h_cnt++;
                }
            }
            else if(ans[i] == 'E' && e + 1 < E.size()){
                ans[E[e++]] = 'R', r_cnt++;
                ans[E[e++]] = 'H', h_cnt++;
            }
        }
        else{
            if(ans[i] == 'W' && e < E.size() ){
                if(r_cnt == 0){
                    ans[W[w++]] = 'R';
                    ans[E[e++]] = 'R';
                    r_cnt++;
                }
                else{
                    ans[W[w++]] = 'H';
                    ans[E[e++]] = 'H';
                    h_cnt++;
                }
            }
            else if(ans[i] == 'W' && w + 1 < W.size()){
                ans[W[w++]] = 'R', r_cnt++;
                ans[W[w++]] = 'H', h_cnt++;
            }
        }
    }
    if(h_cnt == 0 || r_cnt == 0 || (S.size() + N.size()) & 1 || (E.size() + W.size()) & 1){
        cout << "NO" << "\n";
    }else   cout << ans << "\n";
    
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