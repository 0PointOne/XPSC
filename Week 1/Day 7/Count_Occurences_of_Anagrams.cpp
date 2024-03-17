bool isEqual(vector<int> &par_mp, vector<int> &txt_mp){
    for(int i = 0; i < 26; i++){
        if(par_mp[i] != txt_mp[i])    return false;
    }
    return true;
}

int search(string &pat, string &txt) {

    int ans = 0;
    vector<int> pat_mp(26, 0);

    int n = pat.size(), m = txt.size();
    for(int i = 0; i < n; i++)     pat_mp[pat[i] - 'a']++;

    debug(pat_mp)
    
    int l = 0, r = 0, sz = 0;
    vector<int> txt_mp(26, 0);

    while(r < m){
        txt_mp[txt[r] - 'a']++;
        sz++;
        if(sz == n){
            debug(txt_mp)
            if(isEqual(pat_mp, txt_mp))               ans++;

            txt_mp[txt[r-n+1] - 'a']--;
            sz--;
        }
        r++;

    }
    
    return ans;

}