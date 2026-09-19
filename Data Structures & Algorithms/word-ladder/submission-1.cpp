class Solution {
public:

    bool checkDiff(string s1, string s2){
        int ct = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                ct++;
            }
        }

        return ct == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in the list, no valid sequence exists
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        int ladder = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string word = q.front();
                q.pop();
                
                // If we reached the end word, return the current ladder length
                if (word == endWord) {
                    return ladder;
                }
                
                // Try changing each character from 'a' to 'z'
                for (int j = 0; j < word.length(); ++j) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        
                        // If the mutated word is in our set, add to queue and remove to avoid revisiting
                        if (wordSet.find(word) != wordSet.end()) {
                            wordSet.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = originalChar; // restore original character
                }
            }
            ladder++;
        }
        
        return 0;
    }
};
