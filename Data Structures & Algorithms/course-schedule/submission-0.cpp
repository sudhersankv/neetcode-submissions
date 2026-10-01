class Solution {
public:

    unordered_set<int> visited;
    unordered_map<int,vector<int>> pre;

    bool dfs(int course)
        {
            if(visited.find(course) != visited.end())
            {
                return false;
            }

            if(pre[course].empty())
            {
                return true;
            }

            visited.insert(course);
            //process course now
            for(auto &x : pre[course])
            {
                if(!dfs(x))
                {
                    return false;
                }

            }
                visited.erase(course);
                pre[course].clear();
                return true;



        }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {




        for(auto& x : prerequisites)
        {
            pre[x[0]].push_back(x[1]);
        }





        
        for(int i = 0; i < numCourses; i++)
            {
                if(!dfs(i))
                {
                    return false;
                }
            }

            return true;


        
    }
};
