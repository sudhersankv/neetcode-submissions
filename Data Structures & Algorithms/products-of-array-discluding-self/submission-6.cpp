class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // std::vector<int> suffix(nums.size(), 1);
        // std::vector<int> prefix(nums.size(), 1);

        std::vector<int> solution(nums.size(), 1);


        // prefix[0] = 1;
        // suffix[nums.size() - 1] = 1;

        for(int i = 1; i < nums.size(); i++) //PREFIX
        {
            
            solution[i] = solution[i-1] * nums[i-1];
        }


        int suffixprod = 1;
        for(int i = nums.size() - 1; i>=0; i--) //SUFFIX
        {
            solution[i] *= suffixprod;
            suffixprod *= nums[i];

        }


        // for(int i = 0; i < nums.size(); i++)
        // {
        //     solution[i] = prefix[i] * suffix[i];
        // }

        return solution;

    }
};
