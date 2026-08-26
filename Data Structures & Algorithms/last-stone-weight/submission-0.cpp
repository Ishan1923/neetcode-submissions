class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        int res = 0;
        while(pq.size() > 1){
            auto stone1 = pq.top();
            pq.pop();
            auto stone2 = pq.top();
            pq.pop();
            if(stone1 > stone2) {
                res = stone1 - stone2;
                pq.push(res);
            }
            if(stone1 == stone2) res = 0;        
        }
        return (pq.empty()) ? 0 : pq.top();
    }
};
