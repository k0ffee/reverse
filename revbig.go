package main

import (
	"bytes"
	"fmt"
)

func main() {

	str := "1234"
	mul := 1000000
	var buf bytes.Buffer

	for n := 1; n <= mul; n++ {
		buf.WriteString(str)
	}

	str = buf.String()
	buf.Reset()

	for i := len(str); i >= 0; i-- {
		buf.WriteString(str[i:])
		str = str[:i]
	}

	fmt.Println(buf.String())
}
