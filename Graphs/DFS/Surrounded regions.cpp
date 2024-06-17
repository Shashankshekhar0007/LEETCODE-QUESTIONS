class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>board,vector<vector<int>>&vis,int delrow[],int delcol[]){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+delrow[k];
            int nj=j+delcol[k];
            if(ni>0 && ni<board.size() && nj>0 && nj<board[0].size() && !vis[ni][nj] && board[ni][nj]=='O'){
                dfs(ni,nj,board,vis,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           if(!vis[i][0] && board[i][0]=='O')
             dfs(i,0,board,vis,delrow,delcol);
           if(!vis[i][m-1] && board[i][m-1]=='O')
              dfs(i,m-1,board,vis,delrow,delcol);
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O')
              dfs(0,j,board,vis,delrow,delcol);
            if(!vis[n-1][j] && board[n-1][j]=='O')
              dfs(n-1,j,board,vis,delrow,delcol);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }
    }
};