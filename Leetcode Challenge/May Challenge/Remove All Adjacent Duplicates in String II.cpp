class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i=0;i<s.size();i++){
            if(st.size() && st.top().first == s[i] && st.top().second + 1 == k) st.pop();
            else if(st.size() && st.top().first == s[i]) st.top().second += 1;
            else st.push({s[i], 1});
        }
        string ans = "";
        while(st.size()) {
            int val = st.top().second;
            while(val--) {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};