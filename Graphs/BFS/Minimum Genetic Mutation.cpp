 int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endGene)return count;
            for(int i=0;i<word.size();i++){
                char c=word[i];
                word[i]='A';
                if(st.find(word)!=st.end()){
                    q.push({word,count+1});
                    st.erase(word);
                }
                word[i]='C';
                if(st.find(word)!=st.end()){
                    q.push({word,count+1});
                    st.erase(word);
                }
                word[i]='G';
                if(st.find(word)!=st.end()){
                    q.push({word,count+1});
                    st.erase(word);
                }
                word[i]='T';
                if(st.find(word)!=st.end()){
                    q.push({word,count+1});
                    st.erase(word);
                }
                word[i]=c;
            }
        }
        return -1;
    }