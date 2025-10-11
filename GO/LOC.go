package main

import "fmt"

func main() {
	var LOC, n, SIZE int
	fmt.Print("请输入基地址 LOC: ")
	fmt.Scan(&LOC)
	fmt.Print("请输入维度 n: ")
	fmt.Scan(&n)
	c := make([]int, n)
	d := make([]int, n)
	fmt.Println("请输入下界和上界: \n")
	for i := 0; i < n; i++ {
		fmt.Printf("第 %d 维的下界和上界: ", i+1)
		fmt.Scan(&c[i], &d[i])
		if c[i] > d[i] {
			fmt.Println("\033[31m错误: 下界不能超过上界！程序退出！\033[0m")
			return
		}
	}

	fmt.Println("请输入目标元素的各维下标: ")
	j := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Printf("第 %d 维下标: ", i+1)
		fmt.Scan(&j[i])
		if j[i] < c[i] || j[i] > d[i] {
			fmt.Printf("\033[31m错误：第 %d 维下标超出范围！(允许范围 %d~%d)，程序退出！\n\033[0m", i+1, c[i], d[i])
			return
		}
	}

	fmt.Print("请输入数据类型大小 SIZE: ")
	fmt.Scan(&SIZE)

	P := make([]int, n)
	P[n-1] = 1
	for i := n - 2; i >= 0; i-- {
		P[i] = P[i+1] * (d[i+1] - c[i+1] + 1)
	}

	offset := 0
	for i := 0; i < n; i++ {
		offset += (j[i] - c[i]) * P[i]
	}

	ADDR := LOC + offset*SIZE
	fmt.Printf("目标元素地址 ADDR = %d\n", ADDR)
	
}