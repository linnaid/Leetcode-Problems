func removeDuplicates(nums []int) int {
    left, right := 0, 1
    num := 1
    len := len(nums)
    if len == 0 {
        return 0
    } else if len == 1 {
        return 1
    }
    n := 0
    for right < len {
        if nums[left] == nums[right] && n >= 1{
            right++
            n++
        } else if nums[left] == nums[right] && n == 0 {
            left++
            nums[left] = nums[right]
            right++
            n = 1
            num++
        } else {
            left++
            nums[left] = nums[right]
            n = 0
            right++
            num++
        }
    }
    return num
}