class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        std::vector<int> product(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            product[i] *= product[i-1] * nums[i-1];
        }

        // int suffix = 1;

        // for(int i = nums.size() - 1; i >= 0; i--)
        // {
        //     product[i] *= suffix ;
        //     suffix *= nums[i];
        // }
        
        std::vector<int> suffix(nums.size(), 1);

        for(int i = nums.size() - 2; i >=0; i--)
        {
            suffix[i] *= suffix[i+1] * nums[i+1];
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            product[i] *= suffix[i];
        }
        return product;

        

    }
};
