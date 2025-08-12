const static string zimu[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> a;
        for(auto &word : words) {
            string b;
            for(auto& c : word) {
                b.append(zimu[c - 'a']);
            }
            a.emplace(b);
        }
        return a.size();
    }
};