 static bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second; 
}
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            pair<int,int>p=make_pair(points[i][0],points[i][1]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        int count=1;
        int end=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>end){
                count++;
                end=v[i].second;
            }
        }
        return count; 
    }