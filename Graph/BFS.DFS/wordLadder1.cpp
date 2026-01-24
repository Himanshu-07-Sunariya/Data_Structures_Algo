// bfs traversal:- saari shortest sequence milenge kyunki har level par saari choices hongi

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 1;
        // edge case
        bool found=false;
        for(int i=0; i<wordList.size(); i++){
            if(wordList[i]==endWord){
                found=true;
            }
        }

        if(found==false) return 0;

        // brute force says that make the graph connect the node and then do the shortest traversal

        // shyd longest connected component they r asking
        // push elements to set to get their track and frequency
        unordered_set <string> st;
        for(int i=0; i<wordList.size(); i++){
            st.insert(wordList[i]);
        }

        // bfs work
        // word,no of words sts
        queue <pair<string,int>> q;

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            // curr node
            pair<string,int> p=q.front();
            q.pop();

            string currword=p.first;
            int steps=p.second;

            // prefer neighbour
            for(int i=0; i<currword.length(); i++){
                string temp=currword;
                for(char c='a'; c<='z';c++){

                    if(temp[i]==c) continue;
                    temp[i]=c;

                    if(temp==endWord){
                        return steps+1;
                    }

                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,steps+1});
                        // erase from set
                    }
                }
            }
        }
        return 0;
    }
};