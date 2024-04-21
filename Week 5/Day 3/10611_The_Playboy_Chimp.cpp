#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define s(a, b) a+b
#define v_all v.begin(), v.end()
#define mod 100000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print_v(v) for(auto it : v) cout << it << " "; cout << endl;
#define print_v_pair(v) for(auto it: v) cout << it.first << " " << it.second << endl;
#define input_v for(auto &it : v)   cin >> it;
using namespace std;

int low_bin_search(vector<int> &v, int hi){
    int s = 0, e = v.size() - 1;

    int mid = s + (e - s) / 2;
    while(s <= e){
        mid = s + (e - s) / 2;
        if(v[mid] == hi){
            return v[mid - 1];
        }
        if(v[mid] > hi){
            e = mid - 1;
        }
        else if(v[mid] < hi && v[mid+1] <= hi){
            s = mid + 1;
        }
        else if(v[mid] < hi && v[mid+1] > hi){
            return v[mid];
        }
    }
    return -1;

}   

int high_bin_search(vector<int> &v, int hi){
    int s = 0, e = v.size() - 1;

    int mid = s + (e - s) / 2;
    while(s <= e){
        mid = s + (e - s) / 2;
        if(v[mid] == hi){
            return v[mid + 1];
        }
        if(v[mid] < hi){
            s = mid + 1;
        }
        else if(v[mid] > hi && v[mid-1] >= hi){
            e = mid - 1;
        }
        else if(v[mid] > hi && v[mid-1] < hi){
            return v[mid];
        }  
    }
    return -1;
}

void solve(){
    
    int n;  cin >> n;
    vector<int> v(n);
    input_v(v);
    auto it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));


    int q;  cin >> q;
    while(q--){
        int hi; cin >> hi;
        if(v[0] == hi && n == 1){
            cout << "X X" << endl; 
        }
        else if(v[0] > hi){
            cout << "X " << v[0] << endl;
        }
        else if(v[0] == hi){
            cout << "X " << v[1] << endl;
        }
        else if(v[n-1] < hi){
            cout << v[n-1] << " X" << endl;
        }
        else if(v[n-1] == hi){
            cout << v[n-2] << " X" << endl;
        }

        else{
            int lower = low_bin_search(v, hi);
            int upper = high_bin_search(v, hi);
            cout << lower << " " << upper << endl;
        }
    }
}

int main(){
    fast_io;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}