// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        int count[26] = {0};
        bool vis[26] = {false};
        for(auto x : s) count[x-'a']++;
        for(auto x : s)
        {
            count[x-'a']--;
            if(vis[x-'a']) continue;
            
            while(!ans.empty() && ans.back()>x && count[ans.back()-'a']!=0)
            {
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }
            vis[x-'a'] = true;
            ans += x;
        }
        return ans;
    }
};