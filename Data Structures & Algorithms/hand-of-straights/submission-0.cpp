class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        map<int, int> freq;
        for(int num : hand){
            freq[num]++;
        }
        
        for(auto [n, f] : freq){
            if(f == 0) continue;
            for(int i = 0; i < groupSize; i++){

                int nxt_card = n + i;
                if(freq[nxt_card] < f){
                    return false;
                }
                freq[nxt_card]-=f;

            }
        }

        return true;
    }
};
