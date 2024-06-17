class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size();
        int galat=-1;
        int mini=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                galat=i;
            }
            if(nums[i]==minK)mini=i;
            if(nums[i]==maxK)maxi=i;
            ans+=max(0,min(mini,maxi)-galat);
        }
        return ans;
    }
};