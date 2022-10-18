class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string s="11", str;
        for(int i=2;i<n;i++) {
            s+='*'; str="";
            int cnt=1;
            for(int j=1;j<s.size();j++) {
                if(s[j] != s[j-1]) {
                    str+=(to_string(cnt));
                    str+=s[j-1];
                    cnt=1;
                }
                else cnt++;            
            }
            s=str;
        }
        return s;
    }
};