    bool detect(int node,int parent,vector<int> adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(detect(it,node,adj,vis))return true;
            }
            else if(parent!=it)return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(detect(i,-1,adj,vis))return true;
           }
       }
       return false;
    }