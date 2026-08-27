class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        std::priority_queue<int> pq;

        if(nums.size() == 0)
        {
            return 0;
        }


        for(int x: nums)
        {
            pq.push(x);
        }

        for(int i = 0; i<k-1; i++)
        {
            pq.pop();
        }

        return pq.top();


        
    }
};
