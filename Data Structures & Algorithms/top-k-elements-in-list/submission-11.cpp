class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> topk;


        for(auto& x : nums)
        {
            freq[x]++;
        }

        for(auto& x : freq)
        {
            topk.push({x.second, x.first});

            if(topk.size() > k)
            {
                topk.pop();
            }
        }

        vector<int> result;

        while(!topk.empty())
        {
            result.push_back(topk.top().second);

            topk.pop();
        }

        return result;
        
    }
};
