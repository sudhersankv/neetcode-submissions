class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //for loop to check is row is valid

        for(int i = 0; i < 9; i++)
        {std::unordered_set<char> seen;
            for(int j = 0; j < 9; j++)
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
        


        //for loop to check if col is valid

            for(int j = 0; j < 9; j++)
        {std::unordered_set<char> seen;
            for(int i = 0; i < 9; i++)
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


        //for loop to check if block is valid ( might need nested loops)

        for(int i = 0; i < 9; i+=3)
        {
            for(int j = 0; j < 9; j+=3)
            {std::unordered_set<char> seen;
                for(int k = i; k<i+3; k++)
                {
                    for(int l = j; l < j+3; l++)
                    {
                        
                        if(board[k][l] == '.')
                        {
                            continue;
                        }
                        if(seen.find(board[k][l]) != seen.end())
                        {
                            return false;
                        }
                        seen.insert(board[k][l]);
                    }
                }
            }
        }

        return true;


    }
};
