class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        std::priority_queue<int> maxStone;

        for(auto& x: stones)
        {
            maxStone.push(x);
        }

        while(maxStone.size() > 1)
        {
            int x = maxStone.top();
            maxStone.pop();
            int y = maxStone.top();
            maxStone.pop();

            if(x==y)
            {
                continue;
            }
            else if(x > y)
            {
                maxStone.push(x-y);
            }
            else
            {
                maxStone.push((y-x));
            }
        }

        if(maxStone.empty())
        {
            return 0;
        }

        return maxStone.top();


        
    }
};
