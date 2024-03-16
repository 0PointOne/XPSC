class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long sum = 0;
        for(int i = 0; i < K; i++)      sum += Arr[i];
        
        long long ans = sum;
        for(int i = K; i < N; i++){
            sum -= Arr[i - K];
            sum += Arr[i];
            
            ans = max(ans, sum);
        }
        
        return ans;

        //! XPSC approach:
        /* int l = 0, r = 0;
        long long sum = 0, ans = 0;
        while(r < N){
            sum += Arr[r];

            if(r - l + 1 == K){
                ans = max(ans, sum);
                sum -= Arr[l++];
                r++;
            }
            else    r++;
        }

        return ans; */
    }
};
