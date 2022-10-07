class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    int book(int start, int end) {
        mp[start]++; mp[end]--;
        int ans=0, cnt=0;
        for(auto x: mp) {
            cnt+=x.second;
            ans=max(ans, cnt);
        }
        return ans;
    }
};