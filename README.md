# Fast-Algo-probs

Algo-problems for fast and efficient time complexity



<details>
  <summary>Time Calculation in go </summary>
<!--START_SECTION:waka-->
	
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

<!--END_SECTION:waka-->
</details>	
