    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first){
        return a.first<b.first;
        }
        else return a.second<b.second;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        vector<vector<int>>merged;
        for(int i=0;i<intervals.size();i++){
            v.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        int end=v[0].second;
        int start=v[0].first;
        int i=1;
       while(i<v.size()){
           if(v[i].first<=end){
            end=max(v[i].second,end);
           }
           else {
            merged.push_back({start,end});
            start=v[i].first;
            end=v[i].second;
           }
           i++;
       }
        merged.push_back({start,end});
        return merged;
    }