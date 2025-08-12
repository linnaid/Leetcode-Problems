class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int size = piles.size();
        int count = size / 3;
        int ans = 0;
        int index = size - 2;
        for(int i = 0; i < count; i++) {
            ans += piles[index];
            index -= 2;
        }
        return ans;
    }
};