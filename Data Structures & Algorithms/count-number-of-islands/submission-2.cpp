class Solution {
public:




    int numIslands(vector<vector<char>>& grid) {

        std::queue<pair<int,int>> bfs;
        int rowd[4] = {-1, 1, 0, 0};
        int cold[4] = {0, 0, -1, 1};
        int islands = 0;


        if(grid.empty())
        {
            return 0;
        }

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {      
                if(grid[row][col] == '1')
                {islands++;
                    grid[row][col] = '0';
                    bfs.push({row,col});

                    while(!bfs.empty())
                    {
                        int r = bfs.front().first;
                        int c = bfs.front().second;
                        bfs.pop();

                        for(int i = 0; i<4; i++)
                        {
                            int newR = r+rowd[i];
                            int newC = c+cold[i];

                            if((newR>=0 && newR < grid.size()) && (newC >=0 && newC < grid[0].size()) && grid[newR][newC] == '1')
                            {
                                grid[newR][newC] = '0';
                                bfs.push({newR, newC});
                            }
                        }
                    }

                




                    
                }
            }

        }
        return islands;
    }
};
