class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        set<string> st(wordList.begin(),wordList.end());

        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord)
            {
                return steps;
            }
            for(int i=0;i<word.size();i++)
            {
                char orginal = word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = orginal;
            }
        }

        return 0;
    }
};
