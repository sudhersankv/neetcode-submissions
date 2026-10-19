class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        unordered_map<int,int> freq;

        for(auto& x: nums)
        {
            freq[x]++;
        }

        for(auto& x: freq)
        {
            heap.push({x.second, x.first});

            if(heap.size() > k)
            {
                heap.pop();
            }
        }

        vector<int> result;

        for(int i = 0; i < k; i++)
        {
            result.push_back(heap.top().second);

            heap.pop();
        }

        return result;
        
    }
};
