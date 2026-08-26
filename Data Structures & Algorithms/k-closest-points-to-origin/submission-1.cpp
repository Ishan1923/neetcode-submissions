class Solution {
public:
    using p = pair<int, int>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, p>> pq; //max heap
        auto get_distance = [&](int x, int y){
            return pow(( pow(x, 2) + pow(y, 2) ), 0.5);
        };
        for(const auto& point : points){
            pq.push({get_distance(point[0], point[1]), {point[0], point[1]}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        return ans;
    }
};
