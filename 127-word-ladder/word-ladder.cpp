class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st;
        st.insert(wordList.begin(), wordList.end());
        st.erase(beginWord);
        q.push({beginWord, 1});
        while(!q.empty()){
          string word = q.front().first;
          int step = q.front().second;
          q.pop();
          if(word == endWord) return step;
          for(int i = 0; i < word.size(); i++){
            char orig = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
              word[i] = ch;
              if(st.find(word) != st.end()){
                q.push({word, step+1});
                st.erase(word);
              }

            }
            word[i] = orig;
          }
        }
        return 0;
    }
};