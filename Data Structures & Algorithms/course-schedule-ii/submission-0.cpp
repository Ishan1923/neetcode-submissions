class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlst(numCourses);
        vector<int> indeg(numCourses, 0);

        for(const auto& it : prerequisites){
            adjlst[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;

        vector<int> toposort;

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int vis = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            vis++;
            toposort.push_back(top);

            for(auto& neighbour : adjlst[top]){
                indeg[neighbour]--;
                if(indeg[neighbour] == 0) q.push(neighbour);
            }
        }

        if(vis == numCourses) return toposort;

        return {};

    }
};
