class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const int& num : nums){
            freq[num]++;
            if(freq[num] > 1) return num;
        }return -1;
    }
};
