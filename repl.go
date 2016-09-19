package main

import (
  "fmt"
  "bufio"
  "os"
)

func main() {
  reader := bufio.NewReader(os.Stdin)
  for {
    fmt.Print("> ")
    text, _ := reader.ReadString('\n')
    fmt.Print(text)
  }
}

