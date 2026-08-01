class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int m = strs.size();
        map<vector<int>, vector<string>> mp;
        for(int i = 0; i < m; i++){
            vector<int> hashmap(26, 0);
            for(int j = 0; j < strs[i].size(); j++){
                hashmap[strs[i][j] - 'a']++;
            }
            mp[hashmap].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(const auto& it : mp){
            ans.push_back(it.second);
        }

        return ans;


    }
};
