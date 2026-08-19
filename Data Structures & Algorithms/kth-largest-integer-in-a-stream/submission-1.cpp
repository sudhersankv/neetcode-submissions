class KthLargest {
public:

    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {


        this -> k = k;

        for(int x: nums)
        {
            pq.push(x);
        
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {

        pq.push(val);

        if(pq.size() > k)
        {
            pq.pop();
        }

        return pq.top();
        
    }
};
