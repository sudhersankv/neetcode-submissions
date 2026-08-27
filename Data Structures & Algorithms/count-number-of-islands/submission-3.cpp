class Solution {
public:



    int rowD[4] = {-1,1,0,0};
    int colD[4] = {0,0,-1,1};

    int numIslands(vector<vector<char>>& grid) {



        int islands = 0;

        if(grid.empty())
        {
            return 0;
        }
        // ["0","1","1","1","0"]
        // ["0","1","0","1","0"]
        // ["1","1","0","0","0"]
        // ["0","0","0","0","0"]

        std::queue<std::pair<int,int>> bfs;                                 

        // move until i find 1

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == '0')
                {
                    continue;
                }
                
                
                if(grid[row][col] == '1')
                {
                    bfs.push({row,col});
                    grid[row][col] = '0';


                    while(!bfs.empty())
                    {
                        int r = (bfs.front()).first;
                        int c = (bfs.front()).second;

                        bfs.pop();

                        for(int i = 0; i < 4; i++)
                        {
                            int newR = r + rowD[i];
                            int newC = c + colD[i];

                            if(newR >= 0 && newR < grid.size() && newC >=0 & newC < grid[0].size() && grid[newR][newC] == '1')
                            {
                                grid[newR][newC] = '0';
                                bfs.push({newR, newC});
                            }

                        }
                    }                    
                }
                islands++;

                
            }
        } 
        return islands;
    }
};



