```go
package main

import (
	"fmt"
	"time"
)

func elapsed(what string) func() {
	start := time.Now()
	return func() {
		fmt.Printf("%s took %v\n", what, time.Since(start))
	}
}

func main() {
	defer elapsed("page")() // <-- The trailing () is the deferred call
	time.Sleep(time.Second * 2)
}
```
