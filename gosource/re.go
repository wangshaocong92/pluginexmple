// re.go
package main

import "C"
import (
	"regexp"
)

//export StringList
func StringList(reg string, source string) string {
	regex := regexp.MustCompile(reg)
	returnString := regex.FindAllStringSubmatch(source, -1)
	var reString []byte
	for _, value := range returnString {
		for _, b1 := range []byte(string(" ")) {
			reString = append(reString, b1)
		}
		for _, v := range value {
			for _, b := range []byte(v) {
				reString = append(reString, b)
			}
		}
	}
	return string(reString)
}

func main() {
}
