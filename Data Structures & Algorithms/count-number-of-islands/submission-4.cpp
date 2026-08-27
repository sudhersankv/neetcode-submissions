class Solution {
public:


    void dfs(vector<vector<char>>& grid, int r, int c)
        {

            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            {
                return;
            }
            
            grid[r][c] = '0';

            dfs(grid, r-1, c);
            dfs(grid, r+1, c);
            dfs(grid, r, c-1);
            dfs(grid, r, c+1);

            
        }



    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty())
        {
            return 0;
        }
        int islands = 0;


        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col ++)
            {
                if(grid[row][col] == '1')
                {
                    //start counting island,
                    islands++;
                    //check all connected land
                    // grid[row][col] = '0';

                    dfs(grid, row, col);
                }
                else
                {
                    continue;
                }
            }
        }

        return islands;


        
    }
};
