#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> fr(n+1, 0), v;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        fr[x]++;
        v.push_back(x);
    }

    int cnt = 0;
    for(int i = n; i >= 1; i--){
        if((!fr[i] && !cnt) || (fr[i] > 2)){
            cout << "NO" << "\n";
            return;
        }
        else if(!fr[i] && cnt) cnt--;
        else if(fr[i] == 2) cnt++;
    }

    cout << "YES" << "\n";
    vector<int> a(n), b(n);
    vector<pair<int, int>> remA, remB;
    for(int i = 0; i < n; i++){
        if(fr[v[i]] <= 2 && fr[v[i]] > 0){
            a[i] = v[i];
            if(fr[v[i]]== 2) fr[v[i]] = 3;
            else fr[v[i]] -= 2;
        }
        else if(fr[v[i]] == 3){
            b[i] = v[i];
            fr[v[i]] -= 4;
        }
        if(a[i] == 0) remA.push_back({v[i], i});
    }
    sort(remA.begin(), remA.end(), greater());
    int j = n;
    for(int i = 0; i < remA.size(); i++){
        while(fr[j] != 0) j--;
        a[remA[i].second] = j, fr[j]--;
        j--;
    }

    for(int i = 1; i <= n; i++) fr[i] = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == 0) remB.push_back({v[i], i});
        else fr[v[i]]--;
    }
    sort(remB.begin(), remB.end(), greater());
    j = n;
    for(int i = 0; i < remB.size(); i++){
        while(fr[j] != 0) j--;
        b[remB[i].second] = j, fr[j]--;
        j--;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}