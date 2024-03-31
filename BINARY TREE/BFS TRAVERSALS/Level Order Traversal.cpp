vector<vector<int>>levelorder(TreeNode* node){
  vector<vector<int>>ans;
  queue<TreeNode*>q;
  q.push(node);
  while(!q.empty()){
    int size=q.size();
    vector<int>level;
    for(int i=0;i<size;i++){
      TreeNode* node = q.front();
      q.pop();
      if(node->left){
        q.push(node->left);
      }
      if(node->right){
        q.push(node->right);
    }
    level.push_back(node->val);
  }
  ans.push_back(level);
}
}