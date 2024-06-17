    int minPatches(vector<int>& nums, int n) {
        int sz=nums.size();
        long int maxi=0;
        int i=0;
        int cnt=0;
        while(maxi<n){
            if(i<sz && (maxi+1)>=nums[i]){
                maxi+=nums[i];
                i++;
            }
            else {
                cnt++;
                maxi+=maxi+1;
            }
        }
        return cnt;
    }

//  nums=[1,5,10] n=20  ans=2
//  patched array nums is =[1,2,4,5,10]