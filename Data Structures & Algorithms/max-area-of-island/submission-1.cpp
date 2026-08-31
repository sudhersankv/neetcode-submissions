class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        //return an interger
        int maxArea = 0;


        //travel through the grid->find land -> explore all connected land->calculate area-> compare with maximum area-> update max area-> when land ends, search for next land in the grid (basically repeat)

        // i think i will use a BFS approach for this.


        //shortcut to check 4 dir in grid
        int rowD[] = {-1, 1, 0, 0};
        int colD[] = {0, 0, -1, 1};

        //go to DS for BFS is a queue
        std::queue<pair<int,int>> bfs;

        // core loop to traverse

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {   
                int area = 0;
                if(grid[row][col] == 1)
                {
                    bfs.push({row,col});
                    grid[row][col] = 0;

                    while(!bfs.empty())
                    {
                        int r = bfs.front().first;
                        int c = bfs.front().second;
                        area++;
                        bfs.pop();

                        for(int i = 0; i < 4; i++)
                        {
                            int newR = r + rowD[i];
                            int newC = c + colD[i];

                            if(newR >=0 && newR < grid.size() && newC >=0 && newC < grid[0].size() && grid[newR][newC] == 1)
                            {
                                grid[newR][newC] = 0;
                                bfs.push({newR, newC});
                            }
                        }

                    }

                    maxArea = std::max(maxArea, area);
                }
            }
        }

        return maxArea;
        
    }
};
