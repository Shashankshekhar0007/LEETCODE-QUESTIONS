    int cutRod(int i,int N,int price[],vector<vector<int>>&dp){
      if(i==0)return N*price[0];
      if(dp[i][N]!=-1)return dp[i][N];
      int ntake=cutRod(i-1,N,price,dp);
      int rodlength=i+1;
      int take=INT_MIN;
      if(rodlength<=N){
        take=price[i]+cutRod(i,N-rodlength,price,dp);
      }
      return dp[i][N]=max(take,ntake);
    }
    
    /////   Tabulation Version
    
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)dp[0][i]=i*price[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int ntake=dp[i-1][j];
                int take=INT_MIN;
                int rodlength=i+1;
                if(rodlength<=j){
                    take=price[i]+dp[i][j-rodlength];
                }
                dp[i][j]=max(take,ntake);
            }
        }
        return dp[n-1][n];
    }
    /// Space optimised
    int cutrod(int price[],int n){
      vector<int>prev(n+1,0),curr(n+1,0);
       for(int i=0;i<=n;i++)prev[i]=i*price[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int ntake=prev[j];
                int take=INT_MIN;
                int rodlength=i+1;
                if(rodlength<=j){
                    take=price[i]+curr[j-rodlength];
                }
                curr[j]=max(take,ntake);
            }
            prev=curr;
        }
        return curr[n];
    }