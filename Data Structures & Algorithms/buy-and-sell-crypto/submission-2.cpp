class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int cost = prices[0];
        int profit = 0;

        for(int price : prices)
        {
            if(price < cost)
            {
                cost = price;
            }

            if(profit < (price - cost))
            {
                profit = price - cost;
            }

        }

        return profit;
        
    }
};
