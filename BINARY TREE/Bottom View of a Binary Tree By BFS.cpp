class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==nullptr) return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node *node=it.first;
            int line=it.second;
            if(mp.find(line)!=mp.end())mp[line]=node->data;
            else mp[line]=node->data;
            if(node->left!=nullptr){
                q.push({node->left,line-1});
            }
            if(node->right!=nullptr){
                q.push({node->right,line+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};