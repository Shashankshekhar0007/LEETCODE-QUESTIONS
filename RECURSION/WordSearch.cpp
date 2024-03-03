bool solve(int curr,int i,int j,string &word,vector<vector<char>>&board,vector<vector<bool>>&visited){
    if(curr==word.size()-1)return true;
    if(i-1>=0 && board[i-1][j]==word[curr+1] && !visited[i-1][j] ){
        visited[i-1][j]=true;
        bool ans=solve(curr+1,i-1,j,word,board,visited);
        if(ans) return true;
        visited[i-1][j]=false;
    }
    if(j-1>=0 && board[i][j-1]==word[curr+1] && !visited[i][j-1] ){
        visited[i][j-1]=true;
        bool ans=solve(curr+1,i,j-1,word,board,visited);
        if(ans) return true;
        visited[i][j-1]=false;
    }
    if(i+1<board.size() && board[i+1][j]==word[curr+1] && !visited[i+1][j] ){
        visited[i+1][j]=true;
        bool ans=solve(curr+1,i+1,j,word,board,visited);
        if(ans) return true;
        visited[i+1][j]=false;
    }
    if(j+1<board[0].size() && board[i][j+1]==word[curr+1] && !visited[i][j+1] ){
        visited[i][j+1]=true;
        bool ans=solve(curr+1,i,j+1,word,board,visited);
        if(ans) return true;
        visited[i][j+1]=false;
    }
    return false;
  }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                visited[i][j]=true;
                if(board[i][j]==word[0] && solve(0,i,j,word,board,visited)){
                    return true;
                }
                visited[i][j]=false;
            }
        }
        return false;
    }