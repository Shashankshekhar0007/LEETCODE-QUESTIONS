#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int i = 1;
    while (!nodeQueue.empty() && i < nodes.size()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        string val = nodes[i++];
        if (val != "null") {
            current->left = new TreeNode(stoi(val));
            nodeQueue.push(current->left);
        }

        if (i < nodes.size()) {
            val = nodes[i++];
            if (val != "null") {
                current->right = new TreeNode(stoi(val));
                nodeQueue.push(current->right);
            }
        }
    }
    return root;
}

vector<string> split(const string& str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

    void mark(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*current=q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                parent[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                parent[current->right]=current;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*>parent;
       mark(parent,root);
       unordered_map<TreeNode*,bool>visit;
       queue<TreeNode*>que;
       que.push(target);
       visit[target]=true;
       int currlevel=0;
       while(!que.empty()){
        int n=que.size();
        if(currlevel++==k){
            break;
        }
        for(int i=0;i<n;i++){
            TreeNode* current=que.front();
            que.pop();
            if(current->left && !visit[current->left]){
                visit[current->left]=true;
                que.push(current->left);
            }
            if(current->right && !visit[current->right]){
                visit[current->right]=true;
                que.push(current->right);
            }
            if(parent[current] && !visit[parent[current]]){
                visit[parent[current]]=true;
                que.push(parent[current]);
            }
        }
       }
       vector<int>result;
       while(!que.empty()){
        TreeNode *current=que.front();
        que.pop();
        result.push_back(current->val);
       }
       return result;
    }


int main() {
    string rootInput;
    getline(cin, rootInput);
    vector<string> rootNodes = split(rootInput, ',');
    TreeNode* root = buildTree(rootNodes);

    int target, k;
    // cout << "Enter the target value: ";
    cin >> target;
    // cout << "Enter the value of k: ";
    cin >> k;
    vector<int>ans;
    ans=distanceK(root,root->right,k);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i];
    }

    return 0;
}

