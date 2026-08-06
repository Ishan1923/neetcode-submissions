class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlst(numCourses);

        vector<int> indeg(numCourses, 0);

        for(const auto& it : prerequisites){
            adjlst[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int vis = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            vis++;

            for(auto& neighbour : adjlst[node]){
                indeg[neighbour]--;
                if(indeg[neighbour] == 0){
                    q.push(neighbour);
                }
            }

        }


        return vis == numCourses;
    }
};
