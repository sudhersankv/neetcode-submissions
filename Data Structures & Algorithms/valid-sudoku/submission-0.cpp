class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        //check if row is valid
        
        
        for(int i = 0; i < 9; i++)
        {   std::unordered_set<char> num;
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(num.find(board[i][j]) != num.end())
                    {
                        return false;
                    }
                    else
                    {
                        num.insert(board[i][j]);
                    }
                }
            }
        }
        



        //check if col is valid

            for(int j = 0; j < 9; j++)
        {   std::unordered_set<char> num;
            for(int i = 0; i < 9; i++)
            {
                if(board[i][j] != '.')
                {
                    if(num.find(board[i][j]) != num.end())
                    {
                        return false;
                    }
                    else
                    {
                        num.insert(board[i][j]);
                    }
                }
            }
        }



        //check if block is valid
        for(int i = 0; i < 9; i+=3)
        {
            for(int j = 0; j < 9; j+=3)
            {std::unordered_set<char> num;
                for(int k = j; k < j+3; k++)
                {
                    for(int l = i; l < i+3; l++)
                    {
                    if(board[k][l] != '.')
                {
                    if(num.find(board[k][l]) != num.end())
                    {
                        return false;
                    }
                    else
                    {
                        num.insert(board[k][l]);
                    }
                }}
                }
            }
        }

        return true;

        
    }
};
