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
    
    randomlist=[]
    while (len(randomlist) <= length):
        num = random.randint(-length, length)
        if num not in randomlist:
            randomlist.append(num)
    output = ' '.join(str(e) for e in randomlist)
    print(f"./push_swap {output}") 


if __name__ == "__main__":
    main()