class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = prices[0];
        int maxProfit = 0;
        

        for(auto a : prices)
        {
            cost = min(cost, a);

            int profit = a - cost;

            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
        
    }
};
