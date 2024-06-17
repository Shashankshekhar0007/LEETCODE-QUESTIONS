    bool detect(int start,vector<int>adj[],vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({start,-1});
        vis[start]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacentnode:adj[node]){
                if(!vis[adjacentnode]){
                    vis[adjacentnode]=1;
                    q.push({adjacentnode,node});
                }
                else if(parent!=adjacentnode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(detect(i,adj,vis))return true;
           }
       }
       return false;
    }