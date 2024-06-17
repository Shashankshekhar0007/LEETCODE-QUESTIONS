    int solve(int i,vector<int>&arr,int sum,vector<vector<int>>&dp){
      if(sum==0)return 1;
      if(i==0)return arr[i]==sum;
      if(dp[i][sum]!=-1)return dp[i][sum];
      int nottake=solve(i-1,arr,sum,dp);
      int take=0;
      if(sum>=arr[i] && i>=0){
          take=solve(i-1,arr,sum-arr[i],dp);
      }
      return dp[i][sum]=nottake|take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
/// Tabulation
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
      int nottake=dp[i-1][j];
      int take=false;
      if(arr[i]<=j){
          take=dp[i-1][j-arr[i]];
      }
      dp[i][j]=nottake|take;
            }
        }
        return dp[n-1][sum];
    }