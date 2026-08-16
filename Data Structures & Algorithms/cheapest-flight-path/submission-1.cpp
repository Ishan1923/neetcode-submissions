class Solution {
public:

    struct comp{

        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
            
            return a.second.first > b.second.first;
        }

    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adjlst(n + 1);

        for(const auto& flight : flights){
            adjlst[flight[0]].push_back({flight[1], flight[2]});
        }

        // {stops, {cost, node}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;

        vector<int> mnStops(n + 1, INT_MAX);
        vector<int> mnCost(n + 1, INT_MAX);

        mnStops[src] = 0;
        mnCost[src] = 0;

        pq.push({0, {0, src}});

        while(!pq.empty()){
            auto it = pq.top();
            int stops = it.first;
            int c = it.second.first;
            int node = it.second.second;
            pq.pop();

            if(node == dst) return c;

            if(stops > k) continue;

            for(auto& [neighbour, c_] : adjlst[node]){
                
                if(mnStops[neighbour] > stops + 1 || mnCost[neighbour] > c + c_){
                    mnStops[neighbour] = stops + 1;
                    mnCost[neighbour] = c + c_;
                    pq.push({stops + 1, {c + c_, neighbour}});
                }
            }
        }

       return -1;

    }
};
