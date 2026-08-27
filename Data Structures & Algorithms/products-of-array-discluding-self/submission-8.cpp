class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        //return an array

        std::vector<int> product(size(nums), 1); // init with 1 since we are multiplying it.

        //product of everything around it, everything before it, and everything after it

        //prefix

        for(int i = 1; i < size(nums); i++)
        {
            product[i] = product[i-1] * nums[i-1];                    //1,2,3,4,5 //1, 1, 2, 
        }
                                                                     //1,2,3,4,5 // 

        int suffix = 1;

        for(int i = nums.size()-2; i>=0; i--)
        {
            suffix *= nums[i+1];

            product[i]*=suffix;

        }

        return product;




    }
};
