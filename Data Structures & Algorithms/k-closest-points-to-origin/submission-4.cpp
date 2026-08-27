class Solution {
public:

struct compare{
    bool operator()(std::vector<int> a, std::vector<int> b)
    {
        //sqrt((x1 - x2)^2 + (y1 - y2)^2))

        int distA = a[0] * a[0] + a[1] * a[1];
        int distB = b[0] * b[0] + b[1] * b[1];

        return distA < distB;

    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


        std::priority_queue<std::vector<int>, std::vector<vector<int>>, compare> pq;


        std::vector<vector<int>> results;

        for(std::vector<int> x : points)
        {
            pq.push(x);

            if(pq.size() > k)
            {
                pq.pop();
            }
        }


        while(!pq.empty())
        {
            results.push_back(pq.top());
            pq.pop();
        }

        return results;





        //priority queue(max heap), it will store k closest by hardsetting k as the size, nad popping max anytime size > k;

        // custom comparator

        //pop all coordinates for the output.
        
    }
};
