class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // std::sort(nums.begin(), nums.end());

        int maxcount = 0;

        std::unordered_set<int> seen;

        for(int x : nums)
        {
            seen.insert(x);
        }

        
        for(int x : nums)
        {
            if(seen.find(x-1) == seen.end())
            {   int count = 1;
                while(seen.find(x+1) != seen.end())
                {
                    count++;
                    x +=1;
                }
                maxcount = std::max(count, maxcount);
            }
        }

        return maxcount;
        
        
    }
};
