class Solution {
public:


    void f(int ind, vector<int>& subset, const vector<int>& nums, vector<vector<int>>& subsets){

        subsets.push_back(subset);

        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[i - 1]) continue;
            
            subset.push_back(nums[i]);
            f(i + 1, subset, nums, subsets);
            subset.pop_back();
        }
        


    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> subsets;
        f(0, subset, nums, subsets);
        return subsets;
    }
};
