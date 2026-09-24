class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set1;


        for(auto& x : nums)
        {
            set1.insert(x);
        }

        int maxFreq = 0;
        
        for(auto x : nums)
        {
            if(set1.find(x-1) == set1.end())
            {   
                int count = 1;
                while(set1.find(x+1) != set1.end())
                {
                    count++;
                    x+=1;
                }

                maxFreq = max(maxFreq, count);
            }
        }

        return maxFreq;
        
    }
};
