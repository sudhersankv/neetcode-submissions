class Solution {
public:

    std::unordered_map<int,int> freq;

    vector<int> topKFrequent(vector<int>& nums, int k) {


        std::vector<int> result;

        for(int x:nums)
        {
            freq[x]++;
        }

        
        
        
        
        for(int x = 0; x < k; x++)
        {
            int maxFreq = 0;
            int maxKey;
            for(auto& p : freq)
            {
               if(p.second > maxFreq)
               {
                maxFreq = p.second;
                maxKey = p.first;
               }
            }
            result.push_back(maxKey);
            freq.erase(maxKey);
        }

        return result;

        
        
    }
};
