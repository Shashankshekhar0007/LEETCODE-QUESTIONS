// Using Stack
//  vector<int>findpreorder(TreeNode*root){
//   stack<TreeNode*>st;
//   vector<int>inorder;
//   while(true){
//   if(node){
//     st.push(node);
//     node=node->left;
//   }
//   else{
//     if(st.empty()) break;
//     node=st.top();
//     st.pop();
//     inorder.push_back(node->val);
//     node=node->right;
//   }
//   }
//  }
#include <bits/stdc++.h>
using namespace std;
int main()
{
vector<int>n={1 ,2 ,3 ,4 ,5};
cout<<n[4];

return 0;
}