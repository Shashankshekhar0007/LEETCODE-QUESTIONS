// Using Stack
 vector<int>findpreorder(TreeNode*root){
  stack<TreeNode*>st;
  vector<int>ans;
  st.push(root);
  while(!st.empty()){
    TreeNode*node = st.top();
    st.pop();
    ans.push_back(node->val);
    if(node->left){
      st.push_back(node->left);
    }
    if(node->right){
      st.push_back(node->right);
    }
  }
 }