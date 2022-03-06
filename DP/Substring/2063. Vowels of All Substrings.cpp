// https://leetcode.com/problems/vowels-of-all-substrings/

// Number of substrings = n*(n+1)/2

class Solution {
public:
    long long countVowels(string word) {
        long ans = 0, n = word.size();
        for(int i=0; i<n; ++i)
        {
            if (string("aeiou").find(word[i]) != string::npos)
            {
                ans += (i+1)*(n-i);
            }
        }
        return ans;
    }
};