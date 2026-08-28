class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        //grid[0], grid[1]
        //grid[0][0]

        //we want to first search for land

        // short cut to travel 4 dir using a for loop

        int rowD[] = {-1, 1, 0, 0};
        int colD[] = {0, 0, -1, 1};

        int islands = 0;
                    //will need a queue for the bfs
        std::queue<pair<int,int>> bfs;

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                //look for 1
                if(grid[row][col] == '1')
                {

                    //oh, we also need to track land that has been already visited else we might get a infinite loop

                    grid[row][col] = '0';
                    //start my bfs for connected land





                    bfs.push({row, col});

                    while(!bfs.empty())
                    {
                        int r = bfs.front().first;
                        int c = bfs.front().second;

                        bfs.pop();

                        for (int i = 0; i < 4; i++)
                        {
                            int newR = r + rowD[i];
                            int newC = c + colD[i];

                            if(newR >=0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && grid[newR][newC] == '1')
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
