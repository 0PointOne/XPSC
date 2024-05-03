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

    int n, q;  cin >> n >> q;
    vector<int> v(n), pf(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i == 0) pf[i] = v[i];
        else       pf[i] = pf[i-1] + v[i];
    }

    vector<pair<int, int> > qu(q);
    for(int i = 0; i < q; i++){
        cin >> qu[i].ff;
        qu[i].ss = i;
    }

    debug(qu);
    debug(pf);

    sort(all(qu));
    vector<pair<int, int> > re(q);
    debug(re)
    
    int j = 0;
    for(int i = 0; i < q; i++){

        while(j < n && qu[i].ff >= v[j]) j++;
        debug(i)
        debug(j)

        if(j == n){
            while(i < q){
                re[i].ff = qu[i].ss;
                re[i].ss = pf[n-1];
                i++;
            }
            break;
        }
        re[i].ff = qu[i].ss;    // qu  idx;
        (j == 0  ?    re[i].ss =  0   : re[i].ss = pf[j-1]);
    }

    qu.clear();
    pf.clear();
    v.clear();

    sort(all(re));

    debug(re)
    for(int i = 0; i < q; i++)    cout << re[i].ss << " ";
    cout << endl;
    
    re.clear();
    return;
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