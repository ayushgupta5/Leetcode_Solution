class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int i,n = a.size(), val = -1e9;
        stack<int> st;
        for(i = n-1; i >= 0; i--) {
            if(a[i] < val) return 1;
            else {
                while(st.size() && a[i] > st.top())  {
                    val = st.top(); st.pop();
                }
            }
            st.push(a[i]);
        }
        return 0;
    }
};