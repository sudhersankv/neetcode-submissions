class Solution {
   public:
    unordered_map<int, vector<int>> prereq;
    unordered_set<int> visited;

    bool dfs(int course)
    {
        if(visited.find(course) != visited.end())
        {
            return false;
        }

        if(prereq[course].empty())
        {
            return true;
        }
        visited.insert(course);

        //process course now

        for(auto& x: prereq[course])
        {
            if(!dfs(x))
            {
                return false;
            }
        }

        visited.erase(course);
        prereq[course].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& x : prerequisites) 
        {
            prereq[x[0]].push_back(x[1]);
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
