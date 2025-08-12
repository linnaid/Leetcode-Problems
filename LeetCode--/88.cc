class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int fin[m + n];
        int num;
        while(p1 < m || p2 < n){
            if(p1 == m) num = nums2[p2++];
            else if(p2 == n) num = nums1[p1++];
            else if(nums1[p1] < nums2[p2]){
                num = nums1[p1++];
            } else{
                num = nums2[p2++];
            }

            fin[p1 + p2 - 1] = num;
        }
        for(int i = 0; i < m + n; i++){
            nums1[i] = fin[i];
        }
    }
};