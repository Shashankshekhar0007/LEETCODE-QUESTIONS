    int solve(int i,int W,vector<vector<int>>&dp,int wt[], int val[]){
       if(i==0){
        if(wt[0]<=W){
            return val[0];
        }
        else return 0;
       }
        if(dp[i][W]!=-1)return dp[i][W];
        int ntake=solve(i-1,W,dp,wt,val);
        int take=INT_MIN;
        if(wt[i]<=W){
            take=val[i]+solve(i-1,W-wt[i],dp,wt,val);
        }
        return dp[i][W]=max(ntake,take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<vector<int>>dp(n,vector<int>(W+1,-1));
      return solve(n-1,W,dp,wt,val);
    }
    /// Tabulation
        int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++)dp[0][i]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int j=0;j<=W;j++){
               int ntake=dp[ind-1][j];
               int take=INT_MIN;
               if(wt[ind]<=j){
                   take=val[ind]+dp[ind-1][j-wt[ind]];
               }
               dp[ind][j]=max(take,ntake);
           }
       }
       return dp[n-1][W];
    }
    //// Using only Two row
            int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<int>prev(W+1,0),curr(W+1,0);
       for(int i=wt[0];i<=W;i++)prev[i]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int j=0;j<=W;j++){
               int ntake=prev[j];
               int take=INT_MIN;
               if(wt[ind]<=j){
                   take=val[ind]+prev[j-wt[ind]];
               }
               curr[j]=max(take,ntake);
           }
           prev=curr;
       }
       return curr[W];
    }
    ////Using Only one Row
int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<int>prev(W+1,0);
       for(int i=wt[0];i<=W;i++)prev[i]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int j=W;j>=0;j++){
               int ntake=prev[j];
               int take=INT_MIN;
               if(wt[ind]<=j){
                   take=val[ind]+prev[j-wt[ind]];
               }
               prev[j]=max(take,ntake);
           }
           prev=curr;
       }
       return prev[W];
    }