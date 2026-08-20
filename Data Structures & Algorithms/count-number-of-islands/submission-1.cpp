class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if(grid.size() == 0)
        {
            return 0;
        } //ok

        int islands = 0;

        int rowd[4] = {-1,1,0,0};
        int cold[4] = {0,0,-1,1};

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                std::queue<pair<int,int>> bfs;

                if(grid[row][col] == '1')
                {   

                    islands++;
                    grid[row][col] = '0';
                    bfs.push({row,col});

                    //while queue empty, keep searching and adding to queue and pop processed nodes
                    while(!bfs.empty())
                    {
                        int r = bfs.front().first;
                        int c = bfs.front().second;

                        bfs.pop();

                        for(int i = 0; i < 4; i++)
                        {   
                            int newR = r+rowd[i];
                            int newC = c+cold[i];

                            if(newR >= 0 && newC >=0 && newR < grid.size() && newC < grid[0].size() && grid[newR][newC] == '1')
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
