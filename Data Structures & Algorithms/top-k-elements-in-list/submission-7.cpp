class Solution {
public:

    struct compare{
        bool operator()(const std::pair<int, int>& a, const std::pair<int,int>& b) const {
            
            return a.second > b.second;
        }
    };

    std::unordered_map<int,int> freq;
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

    vector<int> topKFrequent(vector<int>& nums, int k) {


        std::vector<int> result;

        for(int x:nums)
        {
            freq[x]++;
        }

        
        
        

            for(auto& p : freq)
            {
                pq.push({p.first, p.second});

                if(pq.size() > k)
                {
                    pq.pop();
                }
            }

                    
        for(int x = 0; x < k; x++)
        {

            result.push_back(pq.top().first);
            pq.pop();

        }

        return result;

        
        
    }
};
