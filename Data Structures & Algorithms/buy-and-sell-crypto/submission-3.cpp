class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int cost = prices[0];
        int profit = 0;

        for(int x : prices)
        {
            if(cost >= x)
            {
                cost = x;
            }

            else
            {
                if(x - cost > profit)
                {
                    profit = x- cost;
                }

            }
        }

        return profit;
        
    }
};
