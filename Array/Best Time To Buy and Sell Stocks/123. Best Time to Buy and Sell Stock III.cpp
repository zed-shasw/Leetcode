// https://www.youtube.com/watch?v=wuzTpONbd-0

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dpl[n], dpr[n];
        int maxi = 0, mini = INT_MAX;
        for(int i=0; i<n; ++i)
        {
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i]-mini);
            dpl[i] = maxi;
        }
        maxi = 0;
        int maxi2 = 0;
        for(int i=n-1; i>=0; i--)
        {
            maxi = max(maxi, prices[i]);
            maxi2 = max(maxi2, maxi - prices[i]);
            dpr[i] = maxi2;
        }
        int ans = 0;
        for(int i=0; i<n; ++i) ans = max(dpl[i]+dpr[i], ans);
        return ans;
    }
};