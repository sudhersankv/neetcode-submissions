class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //count fresh oranges
        
        //find all rotten and add them to queue

        //min = 0

        //for each in queue, find neighbors and rot them, add them to queue, make sure there is fresh oranges left. track them as you rot them. min++ for each level

        //if fresh > 0 still, return -1

        // return min

        int fresh = 0;
        std::queue<pair<int,int>> bfs;
        int min = 0;

        int rowd[] = {-1,1,0,0};
        int cold[] = {0,0,-1,1};


        for (int row = 0; row< grid.size(); row++)
        {
            for(int col =0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == 1)
                {
                    fresh++;
                }
                else if(grid[row][col] == 2)
                {
                    bfs.push({row,col});               }
                }
        }


        while(!bfs.empty() && fresh > 0)
        {
        int qsize = bfs.size();
        for(int i = 0; i < qsize; i++)
        {
            int r = bfs.front().first;
            int c = bfs.front().second;
            bfs.pop();

            for(int j = 0; j< 4; j++)
            {
                int newR = r+rowd[j];
                int newC = c+cold[j];
                
                if((newR >=0 && newR < grid.size()) && (newC >=0 && newC < grid[0].size()) && grid[newR][newC] == 1)
                {
                    grid[newR][newC] = 2;
                    fresh--;
                    bfs.push({newR,newC});

                }
            }
                

        }
        min++;
        }


        if(fresh>0)
        {
            return -1;
        }

        return min;
    

        
    }
};
