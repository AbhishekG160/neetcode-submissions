class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = INT_MAX;
        int profit = INT_MIN;
        for(int& p:prices){
            minm = min(minm, p);
            profit = max(profit, p-minm);
        }
        return profit;
    }
};
