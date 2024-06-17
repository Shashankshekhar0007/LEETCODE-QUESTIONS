  int findways(vector<int>&nums,int target){
    int n=nums.size();
    vector<int>prev(target+1,0),curr(target+1,0);
    if(nums[0]==0)prev[0]=2;
    else prev[0]=1;
    if(nums[0]!=0 && nums[0]<=target)prev[nums[0]]=1;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            int ntake=prev[sum];
            int take=0;
            if(nums[i]<=sum){
                take=prev[sum-nums[i]];
            }
            curr[sum]=ntake+take;
        }
        prev=curr;
    }
    return prev[target];
  }
  int countpartitions(int n,int d,vector<int>&nums){
    int totalsum=accumulate(nums.begin(),nums.end(),0);
    if(totalsum-d < 0 || (totalsum-d)%2==1)return 0;
    return findways(nums,(totalsum-d)/2);
  }