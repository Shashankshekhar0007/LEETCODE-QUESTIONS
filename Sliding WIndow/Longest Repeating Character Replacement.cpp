class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxcount=0;
        int ans=0;
        vector<int>charcount(26,0);
        int start=0;
        for(int i=0;i<n;i++){
            charcount[s[i]-'A']++;
            maxcount=max(maxcount,charcount[s[i]-'A']);
            while(i-start+1-maxcount>k){
                charcount[s[start]-'A']--;
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
}
};