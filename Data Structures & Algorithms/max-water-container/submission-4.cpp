class Solution {
public:
    int maxArea(vector<int>& heights) {

        //height is mins(heights[r], heights[l])
        //width is r-l

        int l = 0;
        int r = heights.size()-1;
        int maxArea = 0;

        if(heights.size() < 2)
        {
            return 0;
        }

        while(l<r)
        {
            int area = std::min(heights[l], heights[r]) * (r-l);
            maxArea = std::max(maxArea, area);
            if(heights[r] > heights[l])
            {
                l++;
                continue;
            }
            else
            {
                r--;
                continue;
            }




        }
        

        return maxArea;







        
    }
};
