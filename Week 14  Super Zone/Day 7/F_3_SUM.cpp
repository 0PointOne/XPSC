#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> fr(10, 0);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        fr[x%10]++;
    }

    auto isPos = [&](int k){
        int a = 3 - k, b = 13 - k, c = 23 - k;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(fr[i] && fr[j] && (i != j) && ((a-i-j == 0) || (b-i-j == 0) || (c-i-j == 0)))  return true;
                if((i == j) && (fr[i] >= 2) && ((a-i-i == 0) || (b-i-i == 0) || (c-i-i == 0)))    return true;
            }
        }
        return false;
    };

    for(int i = 0; i < 10; i++){
        if(fr[i]){
            fr[i]--;
            if(isPos(i)){
                cout << "YES" << "\n";
                return;
            }
            fr[i]++;
        }
    }cout << "NO" << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}