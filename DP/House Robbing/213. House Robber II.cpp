// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> d1(n), d2(n);
        d1[0] = 0;
        d2[0] = 0;
        d1[1] = nums[0];
        d2[1] = nums[1];
        for(int i=2; i<=n-1;++i)
        {
            d1[i] = max(d1[i-2]+nums[i-1], d1[i-1]);
        }
        for(int i=3; i<=n;++i)
        {
            d2[i-1] = max(d2[i-3]+nums[i-1], d2[i-2]);
        }
        return max(d1[n-1],d2[n-1]);
    }
};