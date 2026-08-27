class Solution {
public:

    struct compare
    {
        bool operator()(vector<int> a, vector<int> b)
        {
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];

            return distA < distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        std::priority_queue<vector<int>, vector<vector<int>>, compare> heap;

        std::vector<vector<int>> results;


        for(auto &x : points)
        {
            heap.push(x);

            if(heap.size() > k)
            {
                heap.pop();
            }
        }


        for(int i = 0; i < k; i++)
        {
            results.push_back(heap.top());
            heap.pop();
        }
        

        return results;

    }
};
