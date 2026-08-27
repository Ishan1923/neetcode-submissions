class Solution {
public:

    void f(int ind, int target, vector<int>& sets, const vector<int>& candidates, vector<vector<int>>& subsets){
        
        if(target == 0) {
            subsets.push_back(sets);
            return;
        }

        if(ind >= candidates.size()){
            return;
        }


        for(int i = ind; i < candidates.size(); i++){

            if(i > ind && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i] > target) break;

            sets.push_back(candidates[i]);
            f(i + 1, target - candidates[i], sets, candidates, subsets);
            sets.pop_back();

        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sets;
        vector<vector<int>> subsets;
        f(0, target, sets, candidates, subsets);
        return subsets;
    }
};
