class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end()); //nlogn

        // loop through and see overlapping intervals

        // new vector to store result

        vector<vector<int>> mergedIntervals;

        mergedIntervals.push_back(intervals[0]);

        for(auto& interval: intervals)
        {
            if(mergedIntervals.back()[1] >= interval[0])
            {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
            else
            {
                mergedIntervals.push_back(interval);
            }
        }

        return mergedIntervals;

        
        
    }
};
