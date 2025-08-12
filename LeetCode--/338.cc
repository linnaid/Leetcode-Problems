class Solution {
public:
int Nums(int x) {
    int a = 0;
    while(x > 0) {
        x &= (x - 1);
        a++;
    }
    return a;
}
    vector<int> countBits(int n) {
        vector<int> nums(n + 1);
        for(int i = 0; i <= n; i++) {
            nums[i] = Nums(i);
        }
        return nums;
    }
};