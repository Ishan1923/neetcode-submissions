class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, len] = q.front();
            q.pop();

            if(word == endWord) return len;

            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(words.find(word) != words.end()){
                        words.erase(word);
                        q.push({word, len + 1});
                    }
                    word[i] = org;
                }
            }

        }

        return 0;
    }
};
