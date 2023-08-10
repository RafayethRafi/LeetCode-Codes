class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int mn = INT_MAX;
         int gap = 0;
         int profit =0;

         for(int i=0;i<prices.size();i++)
         {
            if(prices[i]<mn) mn = prices[i];

            gap = prices[i]- mn;

            if(gap > profit) profit = gap;
         }

         return profit;
    }
};
