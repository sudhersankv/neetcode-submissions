class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        std::vector<int> suffix(nums.size(), 1);
        std::vector<int> prefix(nums.size(), 1);

        std::vector<int> solution(nums.size());


        prefix[0] = 1;
        suffix[nums.size() - 1] = 1;

        for(int i = 1; i < nums.size(); i++) //PREFIX
        {
            
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i = nums.size() - 2; i>=0; i--) //SUFFIX
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }


        for(int i = 0; i < nums.size(); i++)
        {
            solution[i] = prefix[i] * suffix[i];
        }

        return solution;

    }
};
