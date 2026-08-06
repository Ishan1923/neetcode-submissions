class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return true;
        if(edges.size() != n - 1) return false;

        vector<vector<int>> adjlst(n);
        vector<int> indeg(n , 0);

        for(const auto& it : edges){
            adjlst[it[0]].push_back(it[1]);
            adjlst[it[1]].push_back(it[0]);
            indeg[it[1]]++;
            indeg[it[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indeg[i] == 1) q.push(i);
        }

        int vis = 0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            vis++;

            for(auto& neighbour : adjlst[top]){
                indeg[neighbour]--;
                if(indeg[neighbour] == 1) q.push(neighbour);
            }
        }

        return vis == n;

    }
};
