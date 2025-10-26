func removeDuplicates(nums []int) int {
    left, right := 0, 1
    num := 1
    len := len(nums)
    if len == 0 {
        return 0
    } else if len == 1 {
        return 1
    }
    for right < len {
        if nums[left] == nums[right] {
            right++
        } else {
            left++
            nums[left] = nums[right]
            right++
            num++
        }
    }
    return num
}