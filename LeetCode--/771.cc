class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsize = jewels.length();
        int stonesize = stones.length();
        int ans = 0;
        for(int i = 0; i < jewelsize; i++) {
            char type = jewels[i];
            for(int j = 0; j < stonesize; j++) {
                if(stones[j] == type) {
                    ans++;
                }
            }
        }
        return ans;
    }
};