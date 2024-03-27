class compare{
    public:
      bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.first>b.first;
      }// For MIN Heap
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        unordered_map<int,int>mp;
        for(int it:hand){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto &entry:mp){
            pq.push(make_pair(entry.first,entry.second));
        }

          while (!pq.empty()) {
            int start = pq.top().first;
            for (int i = 0; i < groupSize; ++i) {
                if (mp[start + i] == 0)
                    return false;
                mp[start + i]--;
            }
            while (!pq.empty() && mp[start] == 0) {
                pq.pop();
                if (!pq.empty())
                    start = pq.top().first;
            }
        }
        return true;
    }
};