#include<bits/stdc++.h> 
using namespace std;
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> copied;
    copy(nums.begin(), nums.end(), back_inserter(copied));
    copy(nums.begin(), nums.end(), back_inserter(copied));
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
     for(int i=(2*n)-1;i>=0;i--){
        while(!st.empty() && st.top()<=copied[i]){
          st.pop();
        }
        if(!st.empty() && st.top()>copied[i]){
          ans[i%n]=st.top();
          st.push(copied[i]);
        }
        if(st.empty()){
          ans[i%n]=-1;
          st.push(copied[i]);
        }
     }
      return ans;
    }
int main() {
 vector<int>nums={2,10,12,1,11};
 vector<int>ans=nextGreaterElements(nums);
 for(int num:ans){
  cout<<num<<endl;
 }
    return 0;
}
