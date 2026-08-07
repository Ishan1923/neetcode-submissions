class Solution {
public:

    struct comp {

        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        }

    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        vector<vector<pair<int, int>>> adjlst(n+1);
        vector<bool> vis(n + 1, false);
        vector<int> dist(n + 1, INT_MAX);

        for(const auto& it : times){
            adjlst[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;
            vis[node] = true;

            for(const auto& [neighbour, t] : adjlst[node]){
                if(vis[neighbour]) continue;
                if(time + t < dist[neighbour]){
                    dist[neighbour] = time + t;
                    pq.push({time + t, neighbour});
                }
            }

        }

        int minTimeToReachAllNodes = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            minTimeToReachAllNodes = max(minTimeToReachAllNodes, dist[i]);
        }

        return minTimeToReachAllNodes;
    }
};
