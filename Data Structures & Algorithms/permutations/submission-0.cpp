class Solution {
public:

    void f(unordered_map<int, int>& freq, int n, vector<int>& permutation ,vector<vector<int>>& permutations){
        if(permutation.size() == n){
            permutations.push_back(permutation);
            return;
        }
        for(auto& [num, fr] : freq){
            if(fr > 0){
                permutation.push_back(num);
                freq[num]--;

                f(freq, n, permutation, permutations);

                permutation.pop_back();
                freq[num]++;

            }
        }
    }

    int fac(int n, vector<int>& memo){
        if(n == 1 || n == 0) return 1;
        if(memo[n] != -1) return memo[n];
        return memo[n] = n * fac(n - 1, memo);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(const auto& num : nums) freq[num]++;

        vector<int> memo(nums.size() + 1);
        int total_permutations = fac(nums.size(), memo);
        for(auto& [num, f] : freq){
            total_permutations = (total_permutations / fac(f, memo));
        }


        vector<int> permutation;
        vector<vector<int>> permutations;
        f(freq, nums.size(), permutation, permutations);

        return permutations;  
    }
};
