 int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
     unordered_set<int>set1({nums1.begin(),nums1.end()});   
     unordered_set<int>set2({nums2.begin(),nums2.end()});
     unordered_set<int>common;
     for(auto it:set1){
         if(set2.count(it)) common.insert(it);
     }
     int n=nums1.size();
     int n1=set1.size();
     int n2=set2.size();
     int m=common.size();
     int max1=min(n/2,n1-m);
     int max2=min(n/2,n2-m);
     return min(n,max1+max2+m);
    }