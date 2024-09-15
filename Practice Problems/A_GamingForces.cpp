#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    int one = 0, greaterOne = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x == 1) one++;
        else greaterOne++;
    }

    cout << greaterOne + (one + 1) / 2 << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}