#include <bits/stdc++.h>
using namespace std;
vector<int>getinorder(TreeNode*node){
  vector<int>ans;
  TreeNode* cur=root;
  while(cur!=null){
    if(cur->left==NULL){
      ans.push_back(cur->val);
      cur=cur->right;
    }
    else{
      TreeNode*prev=cur->left;
      while(prev->right && prev->right!=cur){
        prev=prev->right;
      }
      if(prev->right==NULL){
        prev->right=cur; //for preorder add it to ans;
        cur=cur->left;
      }
      else{
        prev->right=NULL;
        ans.push_back(cur->val);//
        cur=cur->right;
      }
    }
  }
  return ans;
}
int main()
{

return 0;
}