class Solution {
public:
    int longestValidParentheses(string S) {
        stack<int> st;
        int ans = 0;
        for(int i=0; i<S.size(); ++i)
        {
            if(S[i]=='(') st.push(i);
            else {
                if(!st.empty()) st.pop();
                else S[i] = '*';
            }
        }
        while(!st.empty()) 
        {
            S[st.top()] = '*';
            st.pop();
        }
        int temp = 0;
        for(auto x: S)
        {
            if(x != '*') 
            {
                temp++;
                ans = max(ans,temp);
            } else temp = 0;
        }
        return ans;
    }
};