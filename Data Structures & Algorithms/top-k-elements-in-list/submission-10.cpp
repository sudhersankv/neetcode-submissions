class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //count the frequency of the numbers

        //and then i sort the frequencies and return  and print top k

        //sorting would give us nlogn time, but if we can only maintain a max heap of size k, we can do it in nlogk time

        std::unordered_map<int,int> freq;

        std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //we want freq,num so a min heap can sort it right since we want top k.

        //need a result array

        std::vector<int> result;

        for(auto& x :nums)
        {
            freq[x]++;
        }

        for(auto item:freq)
        {
            pq.push({item.second, item.first});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        for(int i = 0; i < k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;


        
    }
};
