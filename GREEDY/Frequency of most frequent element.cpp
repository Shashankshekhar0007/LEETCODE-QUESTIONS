    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long int sum=0,ans=1,j=0;
        for(long long int i=0;i<n;i++){
            sum+=nums[i];
            while((nums[i]*(i-j+1))>(sum+k) && j<=i){
             sum-=nums[j];
             j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }