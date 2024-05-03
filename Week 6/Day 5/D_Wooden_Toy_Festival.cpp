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


void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(all(v));

    auto isPos = [&](int t){

        int c1 = v[0] + t + t;

        debug(c1)
        if(c1 >= v.back()) return true;

        int c2_idx = upper_bound(all(v), c1) - v.begin();

        int c2 = v[c2_idx] + t + t;

        debug(c2)
        if(c2 >= v.back()) return true;
        

        int c3_idx = upper_bound(all(v), c2) - v.begin();
        int c3 = v[c3_idx] + t + t;

        debug(c3)
        if(c3 >= v.back()) return true;

        return false;
    };

    int s = 0, e = 2*1e10;

    int mid = s + (e - s) / 2;
    int ans = 0;
    while(s <= e){

        if(isPos(mid)){
            ans = mid;
            e = mid - 1;
        }
        else   s = mid + 1;

        mid = s + (e - s) / 2;
        debug(mid)
        debug("\n")
    }
    
    cout << ans << nline;

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