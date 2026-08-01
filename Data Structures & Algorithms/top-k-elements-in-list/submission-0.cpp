class Solution {
public:

    struct comp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first ? true : false;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(const auto& num : nums){
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<int> topK;

        for(const auto& [num, freq] : mp){
            pq.push({freq, num});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            topK.push_back(top.second);
        }

        return topK;


    }
};
