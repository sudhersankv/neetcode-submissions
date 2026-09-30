class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rowD[4] = {-1,1,0,0};
        int colD[4] = {0,0,-1,1};
        

        int rows = grid.size();
        int cols = grid[0].size();


        int islands = 0;
        queue<pair<int,int>> bfs;

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == '1')
                {
                    grid[row][col] = '0';
                    bfs.push({row, col});

                    while(!bfs.empty())
                    {
                        int r = bfs.front().first;
                        int c = bfs.front().second;
                        bfs.pop();

                        for(int i = 0; i < 4; i++)
                        {
                            int newR = r + rowD[i];
                            int newC = c + colD[i];

                            if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == '1')
                            {
                                grid[newR][newC] = '0';
                                bfs.push({newR, newC});
                            }


                        }
                    }

                    islands++;
                }


            }
        }


        
    return islands;
    }

};
