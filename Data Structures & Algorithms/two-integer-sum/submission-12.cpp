class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int,int> map1;

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if(map1.find(complement) != map1.end())
            {
                return {map1[complement], i};
            }
            else
            {
                map1[nums[i]] = i;
            }
        }

        return {};
        
    }
};
