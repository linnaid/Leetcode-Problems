class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int ans = 0;
        int size = capacity;
        for(int i = 0; i < n; i++) {
            if(size >= plants[i]) {
                ans++;
                size -= plants[i];
            } else {
                ans += (i * 2 + 1);
                size = capacity - plants[i];
            }
        }
        return ans;
    }
};