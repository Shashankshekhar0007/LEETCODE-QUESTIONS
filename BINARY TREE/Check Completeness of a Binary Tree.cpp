

//   Using DFS
class Solution {
public:
    int getCount(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + getCount(root->left) + getCount(root->right);
  }
    bool iscbt(TreeNode* root,int i,int nodecount){
        if(root==nullptr){
            return true;
        }
        if(i>nodecount){
            return false;
        }
         return iscbt(root->left, 2 * i, nodecount) && iscbt(root->right, 2 * i + 1, nodecount);
    }
    bool isCompleteTree(TreeNode* root) {
        const int count=getCount(root);
        return iscbt(root,1,count);
    }
};