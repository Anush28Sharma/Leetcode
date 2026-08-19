class Solution {
public:
    bool helper(vector<vector<int>>& grid, int row , int col, int expectedval)
    {
        int n = grid.size();
        if(row>=n || col>=n |row<0 ||col<0 || grid[row][col]!=expectedval) return false;
        if(expectedval ==n*n-1)return true;
        bool ans1 = helper(grid,row-2,col+1,expectedval+1);
        bool ans2 = helper(grid,row-1,col+2,expectedval+1);
        bool ans3 = helper(grid,row+1,col+2,expectedval+1);
        bool ans4 = helper(grid,row+2,col+1,expectedval+1);
        bool ans5 = helper(grid,row+2,col-1,expectedval+1);
        bool ans6 = helper(grid,row+1,col-2,expectedval+1);
        bool ans7 = helper(grid,row-1,col-2,expectedval+1);
        bool ans8 = helper(grid,row-2,col-1,expectedval+1);
        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {

        return helper(grid,0,0,0);
        
    }
};