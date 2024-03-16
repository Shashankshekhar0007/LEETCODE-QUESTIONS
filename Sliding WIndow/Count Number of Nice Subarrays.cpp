   int slidingwindow(vector<int>&arr,int cnt){
        int n=arr.size();
        int i=0;
        int j=0;
        int current=0;
        int size=0;
        while(i<n && j<n){
            if(arr[j]%2==1)current++;
            while(i<=j && current>cnt){
                if(arr[i]%2==1){
                    current--;
                    i++;
                }
                else{
                    i++;
                }
            }
          size=size+(j-i+1);
          j++;
        }
        return size;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        ans=slidingwindow(nums,k)-slidingwindow(nums,k-1);
        return ans;
    }