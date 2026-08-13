class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int profit = 0;
        int cost = prices[0];

        for(int i : prices)
        {
            if(i < cost)
            {
                cost = i;
            }

            else if((i > cost) && ((i - cost) > profit))
            {
                profit = i - cost;
            }
        }
        return profit;
    }
};
