class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adjlst;

        int n = words.size();

        for(int i = 1; i < n; i++){
            int l1 = words[i-1].size();
            int l2 = words[i].size();
            int j;
            for(j = 0; j < min(l1, l2); j++){
                if(words[i-1][j] != words[i][j]){
                    adjlst[words[i - 1][j]].push_back(words[i][j]);
                    break;
                }
            }
            if(j == min(l1, l2) && l1 > l2) return "";
        }

        unordered_map<char, int> indeg;

        unordered_set<char> allChars;
        for(const string& word : words) for(const char& c : word) allChars.insert(c);
        for(const char& c : allChars) indeg[c] = 0;

        // for(const auto& it : adjlst){
        //     indeg[it.first] = 0;
        //     for(const char& node : it.second){
        //         indeg[node] = 0;
        //     }
        // }

        for(const auto& it : adjlst){
            for(const char& node : it.second){
                indeg[node]++;
            }
        }

        queue<char> q;

        for(const auto& [node, indegree] : indeg){
            if(indegree == 0){
                q.push(node);
            }
        }

        string order = "";

        while(!q.empty()){
            char node = q.front();
            q.pop();

            order += node;

            for(char& neighbour : adjlst[node]){
                indeg[neighbour]--;
                if(indeg[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        if(order.size() != allChars.size()) return "";

        return order;

    }
};
