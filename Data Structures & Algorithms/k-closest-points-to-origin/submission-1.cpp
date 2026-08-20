class Solution {
public:



    struct compare{
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) const{
        int distA = a[0] * a[0] + a[1] * a[1];
        int distB = b[1] * b[1] + b[0] * b[0];

        return distA < distB;
        }
    };



    std::priority_queue<std::vector<int>, std::vector<vector<int>>, compare> pq;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> result;

        for(vector<int>& x : points)
        {
            pq.push(x);

            if(pq.size() > k)
            {
                pq.pop();
            }

        }

        while(!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;



        
    }
};
