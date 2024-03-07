/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>store;

        queue<pair<TreeNode*,pair<int,int>>>data;
        data.push({root,{0,0}});

        while(!data.empty()){
            auto temp = data.front();
            data.pop();
            int vertical = temp.second.first;
            int level = temp.second.second;
            TreeNode* node = temp.first;
            store[vertical][level].insert(node->val);
            if(node->left){
                data.push({node->left,{vertical-1,level+1}});
            }
            if(node->right){
                data.push({node->right,{vertical+1,level+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto i:store){
            vector<int>temp;
            for(auto j:i.second){
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};