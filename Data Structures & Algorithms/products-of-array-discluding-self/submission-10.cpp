class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //array nums

        //output array

        std::vector<int> product(nums.size(), 1);

        //naive solution would be to have a loop through each character one by one and then travel to both sides, but that would be O(n^2)

        //if we know what is the product before a number and then after a number, we can just multiply them to get the product except self.

        //let's say we can have the list of suffix products and a list of prefix products



        for(int i = 1; i < nums.size(); i++)
        {
            product[i] = product[i-1] * nums[i-1];
        }


        //will need a var to store suffix cuz we are not going to use a diff array for suffix
        int suffix = 1;


        for(int i = nums.size()-2; i >=0; i--)
        {
            suffix *= nums[i+1];
            product[i] *= suffix;

        }

        return product;


    }
};
