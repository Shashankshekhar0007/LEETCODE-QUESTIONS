class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> hash;
        int l = 0;
        int r = 0;
        int start = -1;
        int cnt = 0;
        int minlen = INT_MAX;
        for(char c : t) {
            hash[c]++;
        }
        while(r < n) {
            if(hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == m) {
                if((r - l + 1) < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return start == -1 ? "" : s.substr(start, minlen);
    }
};
