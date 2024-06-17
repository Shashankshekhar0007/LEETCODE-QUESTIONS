	void dfs(int node,stack<int>&st,vector<int>&vis,vector<int>adj[]){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,st,vis,adj);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    vector<int>vis(V+1,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,st,vis,adj);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}