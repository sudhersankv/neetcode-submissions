class Solution {
public:
    int findMin(vector<int> &nums) {

        //start from middle, 

        // if nums.back() < nums.front(), we know which half it is in, we can find that O(1)

        
        int l = 0;
        int r = nums.size() - 1;
        int mid = l - (r-l)/2;


        while(l < r)
        {
            mid = l + (r-l)/2;

            if(nums[mid] > nums[r])
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
            
        }

        return nums[l];


        
    }
};
