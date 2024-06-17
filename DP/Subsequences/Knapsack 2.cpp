        int solve(int i,int W,vector<vector<int>>&dp,int wt[], int val[]){
       if(i==0){
        if(wt[0]<=W){
            return (W/wt[0])*val[0];
        }
        else return 0;
       }
        if(dp[i][W]!=-1)return dp[i][W];
        int ntake=solve(i-1,W,dp,wt,val);
        int take=INT_MIN;
        if(wt[i]<=W){
            take=val[i]+solve(i,W-wt[i],dp,wt,val);
        }
        return dp[i][W]=max(ntake,take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
     vector<vector<int>>dp(N,vector<int>(W+1,-1));
      return solve(N-1,W,dp,wt,val);
    }