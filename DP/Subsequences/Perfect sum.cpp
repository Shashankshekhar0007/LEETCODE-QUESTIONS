#include <bits/stdc++.h>
using namespace std;
//////    1  // Memoization 
	   int mod=1e9+7;
	int solve(int i,int arr[],int sum){
	      if (i == 0) {
        if (sum == 0 && arr[0] == 0) return 2;
        if (sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
	    if(i<0)return 0;
	   if(dp[i][sum]!=-1)return dp[i][sum];
	   if(sum==0)return 1;
	    int ntake=solve(i-1,arr,sum);
	    int take=0;
	    if(sum>=arr[i]){
	        take=solve(i-1,arr,sum-arr[i]);
	    }
	    return (take+ntake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
     vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n-1,arr,sum);
	}
	  
// Tabulation
	int perfectSum(int arr[], int n, int sum)
	{
     vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for(int i=0;i<n;i++)dp[i][0]=1;
    if(arr[0]<=sum)dp[0][arr[0]]=1;
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
int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin>>t;
while(t--){

}
return 0;
}