class Solution {
public:

    bool helper(int row,int col,vector<vector<char>>& board,string word,vector<vector<int>>& visited,int index )
    {
        int n= board.size();
        int m = board[0].size();
        visited[row][col]=1;
        if(index==word.size()) return true;
        int nr[] ={1,0,-1,0};
        int nc[] = {0,-1,0,1};

        for(int k =0;k<4;k++)
        {
            int nrow = row+nr[k];
            int ncol = col+nc[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            {
                if(!visited[nrow][ncol] && board[nrow][ncol]==word[index]){
                    if(helper(nrow,ncol,board,word,visited,index+1))
                    return true;
                }
            }
        }
        
        visited[row][col]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m = board[0].size();
        char ch= word[0];

        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j]==ch)
                {
                  if(helper(i,j,board,word,visited,1))
                  return true;
                }
            }
        }
        return false;
    }
};