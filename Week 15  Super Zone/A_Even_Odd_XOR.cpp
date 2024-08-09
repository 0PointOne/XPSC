#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    
    if(n % 4 == 0){
        for(int i = 0; i < n; i++) cout << i << " ";
        cout << "\n";
    }
    else if(n % 4 == 1){
        cout << 0 << " ";
        int k = 4;
        for(int i = 0; i < n-1; i++) cout << k << " ", k++;
        cout << "\n";
    }
    else if(n % 4 == 2){
        n -= 6;
        cout << "4 1 2 12 3 8 ";
        int k = 16;
        for(int i = 0; i < n; i++) cout << k << " ", k++;
        cout << "\n";
    }
    else{
        n -= 3;
        cout << "2 1 3 ";
        int k = 4;
        for(int i = 0; i < n; i++) cout << k << " ", k++;
        cout << "\n";
    }

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}