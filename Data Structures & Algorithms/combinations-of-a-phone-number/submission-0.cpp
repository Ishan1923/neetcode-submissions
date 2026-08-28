class Solution {
public:


    void f(int ind, const string& digits, string& buffer, vector<string>& permutations,  unordered_map<char, vector<char>>& letters){
        if(ind == digits.size()){
            if(buffer != "")
                permutations.push_back(buffer);
            return;
        }

        for(const char& letter : letters[digits[ind]]){
            buffer.push_back(letter);
            f(ind + 1, digits, buffer, permutations, letters);
            buffer.pop_back();
        }

    }


    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> letters;
        string buffer;
        vector<string> permutations;

        letters['0'] = {};
        letters['1'] = {};
        letters['2'] = {'a', 'b', 'c'};
        letters['3'] = {'d', 'e', 'f'};
        letters['4'] = {'g', 'h', 'i'};
        letters['5'] = {'j', 'k', 'l'};
        letters['6'] = {'m', 'n', 'o'};
        letters['7'] = {'p', 'q', 'r', 's'};
        letters['8'] = {'t', 'u', 'v'};
        letters['9'] = {'w', 'x', 'y', 'z'};


        f(0,digits, buffer, permutations, letters);


        return permutations;   
    }
};
