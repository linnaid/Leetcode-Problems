// int maxArea(int* height, int heightSize) {
//     int left = 0, right = heightSize - 1;
//     int room = 0;
//     while(left < right)
//     {
//         int height_ = (height[right] > height[left])?height[left]:height[right];
//         room = ((right - left)*height_  > room)?(right - left)*height_:room;
//         if(height[left] > height[right])
//         right--;
//         else
//         left++;
//     }
//     return room;
// }

#include <stdio.h>
#include <stdlib.h>

// 函数：计算盛水容器的最大水量
int maxArea(int* height, int n) {
    int left = 0, right = n - 1;
    int max_water = 0;

    while (left < right) {
        // 计算当前两个指针之间的水量
        int width = right - left;
        int min_height = (height[left] < height[right]) ? height[left] : height[right];
        int current_water = width * min_height;

        // 更新最大水量
        if (current_water > max_water) {
            max_water = current_water;
        }

        // 移动较短的线的指针
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main() {
    // 测试用例
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, n);
    printf("The maximum water the container can store is: %d\n", result);

    return 0;
}
