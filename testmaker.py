#!/usr/bin/env python3

import random;
import sys
import random
def main():
    length = 10
    if len(sys.argv) == 1:
        length = 10
    elif len(sys.argv) == 2:
        try:
            length = int(sys.argv[1])
        except Exception as e:
            print(e)
    
    randomlist = list(range(1, length+1))
    random.shuffle(randomlist)
    output = ' '.join(str(e) for e in randomlist)
    print(f"ARGS=\"{output}\";")
    print("./push_swap $ARGS | ./checker_linux $ARGS")
    print("./push_swap $ARGS | wc -l")

if __name__ == "__main__":
    main()