class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        std::stack<vector<int>> st;

        std::vector<vector<int>> result;

        std::sort(intervals.begin(), intervals.end());

        st.push(intervals[0]);

        for(int i = 1; i<intervals.size(); i++)
        {


            if(st.top()[1] >= intervals[i][0])
            {
                st.top()[1] = std::max(st.top()[1], intervals[i][1]);
            }
            else
            {
                st.push(intervals[i]);
            }


        }

        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
        


        
    }
};
