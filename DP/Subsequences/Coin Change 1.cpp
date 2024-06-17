    int mod=INT_MAX;
    int solve(int i,vector<int>&coins,int target,vector<vector<int>>&dp){
        if(i==0){
            if(target % coins[0]==0)return target/coins[0];
            else return 1e9;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int ntake=solve(i-1,coins,target,dp);
        int take=INT_MAX;
        if(coins[i]<=target){
            take=1+solve(i,coins,target-coins[i],dp);
        }
        return dp[i][target]=min(ntake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,coins,amount,dp); 
        if(ans>=1e9)return -1;
        return ans;
    }
    ///Tabulation
        int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int ntake=dp[i-1][j];
                 int take=1e9;
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(ntake,take);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }