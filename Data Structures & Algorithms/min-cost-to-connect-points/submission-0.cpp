class Solution {
public:

    using ll = long long;

    struct pairHash{

        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const{
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);

            return h1^(h2 + 0x9e33779b9 + (h1 << 6) + (h1 >> 2));
        }
    };

    pair<int, int> find(const pair<int, int>& node, unordered_map<pair<int, int>, pair<int, int>, pairHash>& parent){
        if(parent.at(node) == node){
            return parent.at(node);
        }

        return parent[node] = find(parent.at(node), parent);
    }

    bool unite(
        pair<int, int>& node1, 
        pair<int, int>& node2,
        unordered_map<pair<int, int>, pair<int, int>, pairHash>& parent){
        auto parent_node1 = find(node1, parent);
        auto parent_node2 = find(node2, parent);

        if(parent_node1 == parent_node2) return false;

        parent[parent_node1] = parent[parent_node2];

        return true;

    }


    int minCostConnectPoints(vector<vector<int>>& points) {

        unordered_map<pair<int, int>, pair<int, int>, pairHash> parent;
        
        vector<pair<ll, pair<pair<int, int>, pair<int, int>>>> edges;

        int N = points.size();

        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){

                ll manhDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(
                    {
                        manhDist, 
                        {
                            {points[i][0], points[i][1]}, 
                            
                            
                            {points[j][0], points[j][1]}
                        
                        }
                    }
                );
            }


            parent[{points[i][0], points[i][1]}] = {points[i][0], points[i][1]};
        }

        sort(edges.begin(), edges.end());

        ll mstWtSum = 0;

        int edgeUsed = 0;

        for(auto& edge : edges){
            if(edgeUsed == N - 1) break;
            ll wt = edge.first;
            auto u = edge.second.first;
            auto v = edge.second.second;

            if(unite(u, v, parent)){
                mstWtSum += wt;
                edgeUsed++;
            }
        }

        return static_cast<int>(mstWtSum);


    }
};
