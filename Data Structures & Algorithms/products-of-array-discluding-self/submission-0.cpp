class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        int prod = 1;
        int zeroCount = 0;
        for(const auto& num : nums) {
            if (num != 0) prod *= num;
            else zeroCount++;
        }

        vector<int> prods(n, 0);
        for(int i = 0; i < n; i++){
            if (zeroCount == 0) prods[i] = prod / nums[i];
            else if (zeroCount == 1 && nums[i] == 0) prods[i] = prod;
            else prods[i] = 0;
        }

        return prods;
    }
};
