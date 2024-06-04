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

    string s;   cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++) mp[s[i]]++;

    vector<pair<int, char> > v;
    int odd = 0;

    int oddsno = 0;
    char ch = '*';

    for(auto it: mp){
        if(it.ss & 1){
            odd++;
            oddsno = it.ss;
            ch = it.ff;
        }
        v.pb({it.ss, it.ff});
    }

    if(odd > 1){
        cout << "NO SOLUTION" << "\n";
        return;
    }

    sort(all(v), greater());
    debug(v)

    int l = 0, r = s.size()-1;
    for(int i = 0; i < v.size(); i++){
        int cnt = v[i].ff;

        if(cnt & 1){
            continue;
        }
        else{
            int t = cnt / 2;
            while(t--){
                s[l++] = v[i].ss;
            }
            t = cnt / 2;
            while(t--){
                s[r--] = v[i].ss;
            }
        }
    }
    if(odd > 0){
        for(int i = l; i <= r; i++){
            s[i] = ch;
        }
    }
    cout << s;
    
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