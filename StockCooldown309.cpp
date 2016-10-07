class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num = (int)prices.size();
        if (num < 2) {
            return 0;
        } 
        int count, buy_pre = -prices[0], sell_pre = 0, buy = 0, sell = 0;
        for (count = 1; count < num; count++) {
            int current = prices[count], a = sell_pre - current, b = buy_pre + current;
            sell_pre = sell;
            buy = max(a, buy_pre);
            sell = max(b, sell_pre);
            buy_pre = buy;
        }
        return sell;
    }
};