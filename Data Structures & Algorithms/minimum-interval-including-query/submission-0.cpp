class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int m = queries.size();
        vector<int> ans(m, -1);

        vector<pair<int, int>> sorted_queries;
        for(int i = 0; i < m; i++){
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int i = 0;
        for(const auto& [query , idx] : sorted_queries){

            while(i < n && query >= intervals[i][0]){

                
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                
                i++;

            }

            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }

            if(!pq.empty()){
                ans[idx] = pq.top().first;
            }

        }
        


        return ans;

    }
};
