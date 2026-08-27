class Solution {
public:


    void f(int l, int r, string& permutation, vector<string>& permutations){
        if(l > r) return;
        if(l < 0 || r < 0) return;
        if(l == 0 && r == 0) {
            permutations.push_back(permutation);
            return;
        }

        permutation.push_back('(');
        f(l - 1, r, permutation, permutations);
        permutation.pop_back();

        permutation.push_back(')');
        f(l, r - 1, permutation, permutations);
        permutation.pop_back();

    }


    vector<string> generateParenthesis(int n) {

        string permutation;
        vector<string> permutations;

        f(n, n, permutation, permutations);

        return permutations;

    }
};
