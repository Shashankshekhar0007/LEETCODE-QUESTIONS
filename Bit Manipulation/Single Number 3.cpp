    vector<int> singleNumber(vector<int>& nums) {
       int n=nums.size();
       long long totalxor=0;
       for(int i=0;i<n;i++){
         totalxor^=nums[i];
       }
       int lastsetbit=totalxor & -totalxor;
       int first=0;
       for(int i=0;i<n;i++){
         if(lastsetbit& nums[i]){
            first^=nums[i];
         }
       }
       int second=totalxor^first;
      return {first,second};
    }