class Solution {
public:

    void f(int ind, int target, vector<int>& sets, const vector<int>& nums, vector<vector<int>>& subsets){
        
        if(target == 0) {
            subsets.push_back(sets);
            return;
        }

        if(ind < 0){
            return;
        }


        if(target >= nums[ind]){
            sets.push_back(nums[ind]);
            f(ind, target - nums[ind], sets, nums, subsets);
            sets.pop_back();
        }
        
        f(ind - 1, target, sets, nums, subsets);

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> sets;
        vector<vector<int>> subsets;
        f(nums.size() - 1, target, sets, nums, subsets);
        return subsets;
    }
};
