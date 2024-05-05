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

    int n;  cin >> n;
    string s;   cin >> s;
    int l = 0, r = s.size() - 1;
    
    char a = '*', b = '*';
    int a_cnt = 0, b_cnt = 0;

    set<char> st;
    while(l <= r){
        if(s[l] == s[r]){
            st.insert(s[l]);
            st.insert(s[r]);
            l++;
            r--;
        }
        else{
            a = s[l];
            b = s[r];
            break;
        }
    }

    debug(a);
    debug(b)
    if(a == '*' && b == '*'){
        cout << 0 << nline;
        return;
    }

    l = 0, r = sz(s) - 1;
    while(l <= r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            if(s[l] == a){
                l++;
                a_cnt++;
            }
            else if(s[r] == a){
                r--;
                a_cnt++;
            }
            else{
                a = '*';
                a_cnt = -1;
                break;
            }
        }
    }

    l = 0, r = sz(s) - 1;
    while(l <= r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            if(s[l] == b){
                l++;
                b_cnt++;
            }
            else if(s[r] == b){
                r--;
                b_cnt++;
            }
            else{
                b = '*';
                b_cnt = -1;
                break;
            }
        }
    }

    debug(a)
    debug(b)

    debug(a_cnt)
    debug(b_cnt)

    if(a_cnt == -1 && b_cnt == -1){
        cout << -1 << nline;
    }
    else if(a_cnt == -1){
        cout << b_cnt << nline;
    }
    else if(b_cnt == -1){
        cout << a_cnt << nline;
    }
    else{
        cout << min(a_cnt, b_cnt) << nline;
    }
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