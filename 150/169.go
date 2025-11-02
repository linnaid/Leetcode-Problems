// Boyer-Moore 投票算法

func majorityElement(nums []int) int {
    max_num := 0
    count := 0
    for _, num := range nums {
        if count == 0 {
            max_num = num
        }
        if num == max_num {
            count++
        } else {
            count--
        }
    }
    return max_num
}