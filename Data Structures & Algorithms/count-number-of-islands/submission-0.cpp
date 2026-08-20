class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col<grid[0].size(); col++)
            {
                if(grid[row][col] == '1')
                {
                    islands++;

                    std::queue<pair<int,int>> bfs;
                    bfs.push({row,col});
                    grid[row][col] = '0';

                    int rowd[] = {-1,1,0,0};
                    int cold[] = {0,0,-1,1};

                    while(!bfs.empty())
                    {
                        auto current = bfs.front();
                        bfs.pop();

                        int r = current.first;
                        int c = current.second;

                        for(int i = 0; i<4; i++)
                        {
                            int newR = r+rowd[i];
                            int newC = c+cold[i];

                            if((newR >= 0 && newR < grid.size()) && (newC >= 0 && newC < grid[0].size()) && grid[newR][newC] == '1')
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
