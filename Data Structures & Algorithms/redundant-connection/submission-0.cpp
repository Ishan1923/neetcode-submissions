class Solution {
public:

    int find(int x, vector<int>& parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    bool unite(int x, int y, vector<int>& parent, vector<int>& size){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y){
            return false;
        }

        if(size[parent_x] > size[parent_y]){
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
        else{
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
        }

        return true;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n+1);
        vector<int> size(n+1, 1);

        iota(parent.begin(), parent.end(), 0);

        vector<vector<int>> ans;

        for(const auto& edge : edges){
            if(!unite(edge[0], edge[1], parent, size)){
                ans.push_back({edge[0], edge[1]});
            }
        }

        return ans.back();
    }
};
