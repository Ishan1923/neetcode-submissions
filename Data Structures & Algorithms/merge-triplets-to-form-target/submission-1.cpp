class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        int exist = 0;

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < 3; j++){
                if(target[j] >= triplets[i][j]) count++;  
            }
            if(count != 3) continue;

            for(int j = 0; j < 3; j++){
                if(target[j] == triplets[i][j]){
                    exist |= (1 << j);
                }
            }

            if(exist == 7) return true;
        }

        return  exist == 7;

    }
};
