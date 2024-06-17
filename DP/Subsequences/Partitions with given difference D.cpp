    int mod=1e9+7;
	int solve(int i,vector<int>&arr,int sum,vector<vector<int>>&dp){
	      if (i == 0) {
        if (sum == 0 && arr[0] == 0) return 2;
        if (sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
	   if(dp[i][sum]!=-1)return dp[i][sum];
	    int ntake=solve(i-1,arr,sum,dp)%mod;
	    int take=0;
	    if(sum>=arr[i]){
	        take=solve(i-1,arr,sum-arr[i],dp)%mod;
	    }
	    return dp[i][sum]=(take+ntake)%mod;
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        int s1=(sum-d)/2;
        if((sum-d)%2==1)return 0;
        if(sum<d)return 0;
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));
        return solve(n-1,arr,s1,dp);
    }

  ////// TABULATION ////
    int mod=1e9+7;
  int solve(int n,vector<int>&arr,int sum){
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    if(arr[0]==0)dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=sum)dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
        int ntake=dp[i-1][j];
        int take=0;
        if(arr[i]<=j)take=dp[i-1][j-arr[i]];
        dp[i][j]=(take+ntake)%mod;
    }
    }
       return dp[n-1][sum];
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        int s1=(sum-d)/2;
        if((sum-d)%2==1)return 0;
        if(sum<d)return 0;
        return solve(n,arr,s1);
    }