class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       int n=nums.size();
       deque<int>minq;
       deque<int>maxq;
       int ans=0;
       int i=0;
       int j=0;
       while(i<n){
        int x=nums[i];
        while(!minq.empty() && nums[minq.back()]>=x){
            minq.pop_back();
        }
        minq.push_back(i);
        while(!maxq.empty() && nums[maxq.back()]<=x){
            maxq.pop_back();
        }
        maxq.push_back(i);
        int mini=nums[minq.front()];
        int maxi=nums[maxq.front()];
        if(maxi-mini>limit){
            j++;
            if(j>minq.front())minq.pop_front();
            if(j>maxq.front())maxq.pop_front();
        }
        else{
            ans=max(ans,i-j+1);
            i++;
        }
       } 
       return ans;
    }
};