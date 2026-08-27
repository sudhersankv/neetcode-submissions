class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        std::priority_queue<int> weights;

        for(int x : stones)
        {
            weights.push(x);
        }

        while(weights.size()>1)
        {

                int s1 = weights.top();
                weights.pop();
                int s2 = weights.top();
                weights.pop();

                if(s1>s2)
                {
                    s1 = s1-s2;
                    weights.push(s1);
                }
                else if(s2>s1)
                {
                    s2 = s2-s1;
                    weights.push(s2);
                }
                else
                {
                    continue;
                }
            
        }

        if(weights.empty())
        {
            return 0;
        }

        return weights.top();
        
    }
};
