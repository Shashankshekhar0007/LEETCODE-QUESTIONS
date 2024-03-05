// Minimum Length of String After Deleting Similar Ends
int minimumLength(string s) {
        int n=s.size();
        if(n==1 || n==0) return n;
        int j=n-2;
        int i=1;
        int ans=n;
        char prefix=s[i];
        char suffix=s[j];
        if(prefix==suffix){
            while(i<j){
                if(s[i]==prefix) i++;
                if(s[j]==suffix)j--;
            }
        }
        else{
            i++;
        }
        ans=min(ans,j-i+1);
        return ans;
    }