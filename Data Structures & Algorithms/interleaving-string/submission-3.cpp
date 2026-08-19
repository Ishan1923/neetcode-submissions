class Solution {
public:

    bool f(int i1, int i2, const string& s1, const string& s2, const string& s3, vector<vector<int>>& memo){

        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if(i1 + i2 == n3) return i1 == n1 && i2 == n2;

        if(memo[i1][i2] != -1) return memo[i1][i2] == 1 ? true : false; 

        int ind = i1 + i2;

        bool from_s1 = false, from_s2 = false;

        if(s3[ind] == s1[i1]){
            from_s1 |= f(i1 + 1, i2, s1, s2, s3, memo);
        }
        if(s3[ind] == s2[i2]){
            from_s2 |= f(i1, i2 + 1, s1, s2, s3, memo);
        }


        return memo[i1][i2] = (from_s1 | from_s2) ? 1 : 0;
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if (n1 + n2 != n3) return false;

        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));        

        return f(0, 0, s1, s2, s3, memo);


    }
};
