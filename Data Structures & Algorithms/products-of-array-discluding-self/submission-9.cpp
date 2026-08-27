class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // calculate prefix

        std::vector<int> product(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            product[i] = nums[i-1] * product[i-1];
        }

        int suffix = 1;
        
        for(int i = nums.size() - 2;  i>=0; i--)
        {
            
            suffix = suffix * nums[i+1];
            product[i] = product[i] * suffix;
            

        }
        return product;
    }
};
