 int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int rem=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=(sum%k+k)%k;
            // if(rem<0)rem=k+rem;
            cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
    }