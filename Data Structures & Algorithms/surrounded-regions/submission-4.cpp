class Solution {
public:
    void solve(vector<vector<char>>& board) {

        //mxn matrix

        // contains X and O

        //search the grid, find an O -> find adjacent O's repetitively -> if any O is on the edge, move on to search next region -> else continue -> if region ends -> turn entire region to X, so we need to track the indices of regions we visit.


        //we can use BFS for this problem,  and go to DS for BFS is a queue

        // std::queue<pair<int,int>> bfs;

        //we can use a set to track visited indices

        //4 direction bfs shortcut
        int rowD[] = {-1, 1, 0, 0};
        int colD[] = {0, 0, -1, 1};

        

        // initial grid traversal




        for(int row = 1; !board.empty() && row < board.size()-1; row++) // since border cells can't be surrounded anyway
        {
            for(int col = 1; col < board[0].size()-1; col++)
            {    
                if(board[row][col] == 'O')
                {   std::vector<pair<int,int>> visited;
                    std::queue<pair<int,int>> bfs;
                    bfs.push({row,col});
                    visited.push_back({row,col}); // so that we can reverse the change if we find later the land is connected to edge
                    board[row][col] = 'X';
                    bool surrounded = true;

                    while(!bfs.empty() && surrounded)
                    {
                        int r = bfs.front().first;
                        int c = bfs.front().second;
                        bfs.pop();

                        for(int i = 0; i < 4; i++)
                        {
                            int newR = r + rowD[i];
                            int newC = c + colD[i];

                            if(board[newR][newC] == 'O')
                            {
                                if(newR == 0 || newC == 0 || newR == board.size()-1 || newC == board[0].size()-1) // if connected O is any of edge
                                {
                                    for(auto x : visited)
                                    {
                                        board[x.first][x.second] = 'O';
                                    }
                                    surrounded = false;
                                    break; // break out of the loop
                                }
                                
                                visited.push_back({newR, newC});
                                bfs.push({newR, newC});
                                board[newR][newC] = 'X';
                            }
                        }
                    }
                }
            }
        }


        
    }
};
