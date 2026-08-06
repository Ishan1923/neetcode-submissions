class Solution {
public:

    void dfs(int node, const vector<vector<int>>& adjlst, unordered_set<int>& vis){
        if(node >= adjlst.size() || node < 0) return;

        vis.insert(node);

        for(const auto& neighbour : adjlst[node]){
            if(vis.find(neighbour) == vis.end()){
                dfs(neighbour, adjlst, vis);
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjlst(n);

        for(const auto& edge : edges){
            adjlst[edge[0]].push_back(edge[1]);
            adjlst[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;

        int connected_components = 0;

        for(int i = 0; i < n; i++){
            if(vis.find(i) == vis.end()){
                vis.insert(i);
                connected_components++;
                dfs(i, adjlst, vis);
            }
        }

        return connected_components;

    }
};
