package main

import (
	"bytes"
	"fmt"
)

func main() {

	str := "1234"
	var buf bytes.Buffer

	for i := len(str); i >= 0; i-- {
		buf.WriteString(str[i:])
		str = str[:i]
	}

	fmt.Println(buf.String())
}
