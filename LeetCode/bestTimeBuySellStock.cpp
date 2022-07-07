class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int buy_low = INT_MAX, sell_high = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buy_low = min(buy_low, prices[i]);
            sell_high = max(sell_high, prices[i] - buy_low);
        }
        return sell_high;
    }
};