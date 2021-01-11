package main

// 尝试有一个协程写int，而其他协程获取这个int值，我们测试是否会出现不符合预期之内的值
import (
	"fmt"
	"time"
)

func main() {
	var index int

	go func() {
		for {
			index = 1 - index
			time.Sleep(time.Duration(1) * time.Second)
		}
	}()

	go func() {
		for {
			c := index
			if c != 0 && c != 1 {
				fmt.Printf("the c is invalid %d\n", c)
			}
			time.Sleep(time.Duration(10) * time.Microsecond)
		}
	}()

	for {
		time.Sleep(time.Duration(100) * time.Second)
	}
}
