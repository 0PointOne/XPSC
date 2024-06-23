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

bool cmp(string &a, string &b){
    return a.size() < b.size();
}

void solve(){

    int n;  cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    sort(all(v), cmp);

    map<pair<int, int>, int> mp;
    int ans = n;

    for(int i = 0; i < n; i++){

        int sz = v[i].size();
        for(int j = 1; j <= sz; j++){
            if( (sz + j) % 2 != 0) continue;

            int mid = (sz + j) / 2;
            int sum = 0;
            for(int k = 0; k < mid; k++)  sum += (v[i][k] - '0');
            for(int k = mid; k < sz; k++) sum -= (v[i][k] - '0');

            if(sum >= 0) ans += mp[{j, sum}];
        }
        reverse(all(v[i]));
        for(int j = 1; j <= sz; j++){
            if( (sz + j) % 2 != 0) continue;

            int mid = (sz + j) / 2;
            int sum = 0;
            for(int k = 0; k < mid; k++)  sum += (v[i][k] - '0');
            for(int k = mid; k < sz; k++) sum -= (v[i][k] - '0');

            if(sum >= 0) ans += mp[{j, sum}];
        }
        int t = 0;
        for(int j = 0; j < sz; j++) t += v[i][j] - '0';
        mp[{sz, t}]++;
    }

    cout << ans << "\n";

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