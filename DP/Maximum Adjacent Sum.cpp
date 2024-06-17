 int maximumNonAdjacentSum(vector<int> &nums){
   int prev=nums[0];
   int prev2=0;
   int n=nums.size();
   int curr=0;
   for(int i=1;i<n;i++){
       int take=nums[i];
       if(i>1)take+=prev2;
       int notpick=prev;
       curr=max(take,notpick);
       prev2=prev;
       prev=curr;
   }
   return prev;
}