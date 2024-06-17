    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int end=intervals[0][1];
        int i=1;
        while(i<intervals.size()){
            if(intervals[i][0]<end){
                ans++;
                end = min(end, intervals[i][1]);
            }
            else{
                end=intervals[i][1];
            }
            i++;
        }
        return ans;
    }
    // By sorting the second elements of the interval
      int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        int n = intervals.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++){
            v[i].first = intervals[i][0];
            v[i].second = intervals[i][1];
        }
        sort(v.begin(), v.end(), [](auto&a,auto&b) {
            return a.second < b.second;
        });

        int end = v[0].second;
        int count = 0;

        for(int i=1; i<n; i++){
            if(v[i].first < end){
                count++;
            } else {
                end = v[i].second;
            }
        }
        
        return count;
    }