class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        
        for(int i = 0; i < rows; i++)
        {
            unordered_set<int> seen;
            for(int j = 0; j < cols; j++)
            {   

                if(board[i][j] == '.')
                {
                    continue;
                }
                if(seen.find(board[i][j]) != seen.end())
                {
                    return false;
                }
                seen.insert(board[i][j]);
            }

        }


        for(int j = 0; j < cols; j++)
        {
            unordered_set<int> seen;
            for(int i = 0; i < rows; i++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(seen.find(board[i][j]) != seen.end())
                {
                    return false;
                }
                seen.insert(board[i][j]);
            }

        }


        for(int r = 0; r < 9; r+=3)
        {
            for(int c = 0; c < 9; c+=3)
            {   unordered_set<int> seen;
                for(int i = r; i < r+3; i++)
                {
                    for(int j = c; j < c+3; j++)
                    {
                        
                        if(board[i][j] == '.')
                        {
                            continue;
                        }
                        if(seen.find(board[i][j]) != seen.end())
                        {
                            return false;
                        }   
                        seen.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
        
    }
};
