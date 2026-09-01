class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        //i have a vector of intervals

        // we have been given a new interval

        // let's looping through the current intervals

        // check for an overlap

        //  if current interval comes before new, push to result

        // if overlap, merge with new interval and update the new interval

        // keep doing  until there is overlap

        // if current interval is after new interval, push new interval, and then rest of all intervals

        // we will need a result array

        std::vector<vector<int>> result;

        bool inserted = false;

        for(auto& x : intervals)
        {
            if(x[1] >= newInterval[0] && x[0] <= newInterval[1])
            {
                newInterval[0] = std::min(newInterval[0], x[0]);
                newInterval[1] = std::max(newInterval[1], x[1]);
            }
            else if(x[1] < newInterval[0] )
            {
                result.push_back(x);
            }
            else
            {   if(!inserted)
                {
                    result.push_back(newInterval);
                    inserted = true;
                }

                result.push_back(x);
            }   



        }

        if (!inserted)
        {
            result.push_back(newInterval);
        }

        return result;



        
    }
};
