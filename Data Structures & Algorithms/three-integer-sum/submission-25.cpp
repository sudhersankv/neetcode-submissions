class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //return a vector of triplets

        //such that, nums[i] + nums[j] + nums [k] == 0;

        // no duplicates

        // distinct indices

        //so, i think a sorted array would be really helpful

        //O(nlogn) for sort, but the loop will be O(n^2)


        std::vector<vector<int>> result;
        if(nums.empty())
        {
            return result;
        }
        std::sort(nums.begin(), nums.end());


        //now i want to take every index, and compare which other 2 indices can combine with my index, 
                // Input: nums = [-1,0,1,2,-1,-4] -> [-4, -1,-1, 0, 1, 2]

        for(int i = 0; i < nums.size(); i++)
        {   if(i>0 && nums[i] == nums[i-1])
        {
            continue;
        }
            
            int l = i+1;
            int r = nums.size()-1;

            while(l < r)
            {
                if(nums[i]+nums[l]+nums[r] == 0)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(l<r && nums[l] == nums[l-1])
                    {
                        l++;
                    }

                    while(l<r && nums[r] == nums[r+1])
                    {
                        r--;
                    }
                }
                else if(nums[i]+nums[l]+nums[r] > 0)
                {
                    r--;
                    
                }
                else
                {
                    l++;

                }
            }

        }



        return result;

        
    }
};
