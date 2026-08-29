class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //given a grid of fruits, if there is a rotting fruit, every next min, it's nearby fruit rots.

        // there can be multiple rotten oranges at the same time.

        // so we need to first find all rotten oranges.

        //i think doing a breadth first search/ level order traversal is the best, since we are tracking the rotting per unit time. can travel a level each unit time.

        //naturally for a bfs we can use a queue

        std::queue<std::pair<int,int>> bfs;

        // we need to track how many mins before there is no fresh fruit, it it's not possible, then -1

        // first let's count total fresh and total rotten, we need to rotten position too, so we can start our search from there
        int mins = 0;
        int fresh = 0;

        //shortcut to travel in 4 dif in for loop

        int rowD[4] = {-1, 1, 0, 0};
        int colD[4] = {0, 0, -1, 1};

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == 1)
                {
                    fresh++;
                }
                else if(grid[row][col] == 2)
                {
                    bfs.push({row, col});
                }
                else
                {
                    continue;
                }
            }
        }

        //now we have total fresh fruits and all rotten fruits positions

        //time complexity rn is O(mn) m = rowsize, n = colsize
        //space complexity = O(1) until now. or actually O(total rotten fruits in initiial state)
  
        //if 0 fresh already, return 0

        if(fresh == 0)
        {
            return 0;
        }

        //if no rotten fruit, target state is not possible
        if(bfs.empty())
        {
            return -1;
        }


        //now let's start bfs

        while(!bfs.empty() && fresh > 0)
        {
            int size = bfs.size();
            for(int i = 0; i < size; i++)
            {
                int r = bfs.front().first;
                int c = bfs.front().second;

                bfs.pop();

                for(int j = 0; j < 4; j++)
                {
                    int newR = r + rowD[j];
                    int newC = c + colD[j];

                    if(newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && grid[newR][newC] == 1)
                    {
                        grid[newR][newC] = 2;
                        bfs.push({newR, newC});
                        fresh--;
                    }
                }
            }
            mins++;
        }

        if(fresh!=0)
        {
            return -1;
        }
        
        return mins;
        
    }
};
