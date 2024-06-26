    int solve(int i,vector<int>&coins,int target,vector<vector<int>>&dp){
        if(i==0){
            if(target % coins[0]==0)return 1;
            else return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int ntake=solve(i-1,coins,target,dp);
        int take=0;
        if(coins[i]<=target){
            take=solve(i,coins,target-coins[i],dp);
        }
        return dp[i][target]=ntake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp); 
    }