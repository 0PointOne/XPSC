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


int cal_pw(int k){
    int cnt = 0;
    while(k){
        k /= 2;
        cnt++;
    }
    return cnt;
}

int setBit(int n){
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n = n + 1;
	return (n >> 1);
}

int pw(int a, int b, int m){
    if(b == 0)  return 1;

    if(b & 1){
        int t = pw(a, (b-1) / 2, m);
        t = (t * t) % m;
        return (a * t % m);
    }
    else{
        int t = pw(a, b / 2, m);
        return (t * t % m);
    }
}

void solve(){

    /* int n, k;   cin >> n >> k;
    vector<int> v;

    int t_k = k;
    while(t_k){
        int sb = setBit(t_k);
        v.pb(cal_pw(sb - 1));
        debug(sb)
        t_k -= sb;
    }
    debug(v)

    int sum = 0;
    for(int i = 0; i < sz(v); i++){
        int calu = pw(n, v[i], MOD);
        sum += calu;
    }

    cout << sum % MOD << nline; */


    int n, k;   cin >> n >> k;
    int p = 1;
    int ans = 0;
    for(int i = 0; i <= 31; i++){
        if(k & (1 << i)){
            ans += p;
        }

        p *= n;
        p %= MOD;
    }

    cout << ans % MOD << nline;

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