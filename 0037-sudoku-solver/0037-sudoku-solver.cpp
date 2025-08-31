class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') continue;
                for(char digit='1';digit<='9';digit++){
                    if(valid(board,i,j,digit)){
                        board[i][j]=digit;
                        if(solve(board) == true){
                            return true;
                        }
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool valid(const vector<vector<char>>& grid, int row, int col,int digit){
        for(int i=0;i<9;i++)
        {
            if(grid[row][i]==digit) return false;
            if(grid[i][col]==digit) return false;
        }
        int start_i= (row/3)*3;
        int start_j= (col/3)*3;

        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(grid[start_i+k][start_j+l]==digit)return false;
            }
        }
        return true;
    }
};