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

struct cmp{
    bool operator()(pair<int, int> &a,pair<int, int> &b){
	    if(a.first == b.first) return a.ss > b.ss;
	    return a.first < b.first;
    }
};

void solve(){

    int q;  cin >> q;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> poly;
    queue<pair<int, int> > mono;
    int i = 1;
    vector<bool> vis;
    vis.pb(false);
    
    while(q--){
        int op;    cin >> op;
        if(op == 1){
            int k;  cin >> k;
            poly.push({k, i});
            mono.push({k, i});
            vis.pb(false);
            i++;
        }
        else if(op == 2){
            while(!mono.empty() && vis[mono.front().ss] == true) mono.pop();

            if(!mono.empty()){
                cout << mono.front().ss << " ";
                vis[mono.front().ss] = true;
                mono.pop();
            }
        }
        else{

            while(!poly.empty() && vis[poly.top().ss] == true) poly.pop();

            if(!poly.empty()){
                cout << poly.top().ss << " ";
                vis[poly.top().ss] = true;
                poly.pop();
            }
        }
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