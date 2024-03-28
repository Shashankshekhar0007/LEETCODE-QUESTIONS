class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int mask=0;
        int start=0;
        for(int i=0;i<n;i++){
                   while(mask&nums[i]){
                    mask^=nums[start];
                    start++;
                   }
                   ans=max(ans,i-start+1);
                   mask |=nums[i];
        }
        return ans;
    }
};