class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        std::unordered_set<int> set1;
        int maxcount = 0;

        for(int x:nums)
        {
            set1.insert(x);
        }

        for(int x: nums)
        {  if(set1.find(x-1) == set1.end())
        {
            
            int count = 1;
            int a = x;

            

            while(set1.find(a+1) != set1.end())
            {
                count++;
                a++;
            }
            maxcount = std::max(maxcount, count);
        
        }}

        return maxcount;
        
    }
};
