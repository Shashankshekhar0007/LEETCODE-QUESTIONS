class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int abc[3];
        int ans=0;
        int start=0;
        for(int i=0;i<n;i++){
            abc[s[i]-'a']++;
            while(abc[0]>=1 && abc[1]>=1 && abc[2]>=1){
                ans+=n-i;
                abc[s[start]-'a']--;
                start++;
            }
        }
        return ans;
    }
};