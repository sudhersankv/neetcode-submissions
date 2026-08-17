class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::vector<vector<int>> solution;

        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            
            
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            
            
            
            int l = i+1;
            int r = nums.size() - 1;




            while(l<r && l>i)
            {
                int sumof = nums[i] + nums[l] + nums [r];

                
                if(sumof == 0)
                {
                    solution.push_back({nums[i],nums[l],nums[r]});
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
                
                else if(sumof > 0)
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
