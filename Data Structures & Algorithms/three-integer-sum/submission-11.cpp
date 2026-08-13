class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

     int l = 1;
     int r = nums.size() - 1;
     std::vector<std::vector<int>> solution;

     std::sort(nums.begin(), nums.end());

     for(int i = 0; i < nums.size(); i++)

     {


        if(i>0 && nums[i] == nums[i-1])
        {
            continue;
        }
        
        l = i+1;
        r = nums.size() - 1;

        while(l<r)
        {
            if(nums[i] + nums[l] + nums[r] == 0)
            {
                solution.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;

                while(l<r && nums[l] == nums[l-1])
                {
                    l++;
                }
                while(l<r && (r+1) < nums.size() && nums[r] == nums[r+1])
                {
                    r--;
                }
            }

            else if(nums[i] + nums[l]+ nums[r] > 0)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
     }
        
        return solution;
    }
};
