class Solution {
public:


    void f(int ind, vector<int>& subset, const vector<int>& nums, vector<vector<int>>& subsets){
        if(ind >= nums.size()){
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[ind]);
        f(ind + 1, subset, nums, subsets);
        subset.pop_back();

        f(ind + 1, subset, nums, subsets);


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;
        vector<vector<int>> subsets;

        f(0, subset, nums, subsets);

        return subsets;

    }
};
