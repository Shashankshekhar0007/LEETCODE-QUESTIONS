class node{
    public:
    int val;
    int row;
    int col;
    node(int a,int i,int j){
        val=a;
        row=i;
        col=j;
    }
};
class compare{
   public:
   bool operator()(node*a,node*b){
    return a->val>b->val;
   }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>,compare>pq;
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i=0;i<n;i++){
           mini=min(mini,nums[i][0]);
           maxi=max(maxi,nums[i][0]);
           pq.push(new node(nums[i][0],i,0));
        }
        int start=mini;
        int end=maxi;
        while(!pq.empty()){
            node* temp=pq.top();
            pq.pop();
            mini=temp->val;
            if(maxi-mini<end-start){
                end=maxi;
                start=mini;
            }
            if(temp->col+1<nums[temp->row].size()){
                maxi=max(maxi,nums[temp->row][temp->col+1]);
                pq.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else{
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};