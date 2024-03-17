vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    vector<long long> ans;
    queue<long long> q;
    long long r = 0;
    long long sz = 0;
    
    while(r < N){
        if(A[r] < 0)    q.push(A[r]);
        sz++;
        
        if(sz == K){
            
            ans.push_back( (q.empty() ?  0  :  q.front() ) );
            if(q.front() == A[r - K + 1])  q.pop();
            sz--;
        }
        
        r++;    
    }
    
    return ans;
      
 }