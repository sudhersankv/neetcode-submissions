class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // sort the intervals in an ascending order, start fron first interval and check if it is overlapping, if yes, move on to next and count++

        int count = 0;

        std::vector<vector<int>> bin;
        std::sort(intervals.begin(), intervals.end());
        bin.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < bin.back()[1])
            {
                count++;
                
                if(intervals[i][1] < bin.back()[1])
                {
                    bin.back() = intervals[i];
                }
            }
            else
            {
                bin.push_back(intervals[i]);
            }
        }
        
        return count;
    }
};
