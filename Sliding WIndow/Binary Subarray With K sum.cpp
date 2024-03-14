// Use the logic of finding all the subsets upto k and subtract the number of subsets for upto k-1 and you will get the number of subsets for exactly k
int slidingwindow(vector<int>&num,int k){
        long long currentsum=0;
        int totalsize=0;
        int n=num.size();
        int i=0;
        int j=0;
        while(j<n){
           currentsum+=num[j];
           while(i<=j &&currentsum>k){
            currentsum-=num[i];
            i++;
           } 
           totalsize=totalsize +(j-i+1);
           j++;
        }
        return totalsize;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        cnt=slidingwindow(nums,goal)-slidingwindow(nums,goal-1);
        return cnt;
    }