class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //3 index trackers
        // sum of them == 0
        // no duplicates -> skip them while iter


        std::sort(nums.begin(), nums.end()); //logn

        std::vector<vector<int>> output;

        for(int i = 0; i < nums.size(); i++)
        {
            int l = i+1;
            int r = nums.size() - 1;
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

            while(l < r)
            {   

                if(l>i+1 && nums[l] == nums[l-1])
                {
                    l++;
                    continue;
                }

                if(r<(nums.size() - 1) && nums[r] == nums[r+1])
                {
                    r--;
                    continue;
                }


                if(nums[i] + nums[l] + nums[r] == 0)
                {
                    output.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    continue;
                }

                else if(nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                    continue;
                }
                else
                {
                    l++;
                    continue;
                }
            }
        }

        return output;
    }
};
