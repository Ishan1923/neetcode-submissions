class Solution {
public:

    void dfs(const string& node, unordered_map<string, multiset<string>>& adjlst, vector<string>& eulerian_path){


        while(!adjlst[node].empty()){
            auto it = adjlst[node].begin();

            string neighbour = *it;

            adjlst[node].erase(it);

            dfs(neighbour, adjlst, eulerian_path);

        }


        eulerian_path.push_back(node);


    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
       unordered_map<string, multiset<string>> adjlst;

       for(const auto& edge : tickets){
        adjlst[edge[0]].insert(edge[1]);
       }


       vector<string> eulerian_path;


       dfs("JFK", adjlst, eulerian_path);

       reverse(eulerian_path.begin(), eulerian_path.end());

       return eulerian_path;

    }
};
