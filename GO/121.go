func maxProfit(prices []int) int {
    minPrice := prices[0]
    ans := 0
    for _, i := range prices {
        ans = max(ans, i - minPrice)
        minPrice = min(minPrice, i)
    }
    return ans
}