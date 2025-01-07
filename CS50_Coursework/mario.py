from cs50 import get_int

def main():
    height = get_height()
    for i in range(height):
        print("#")

    for i in range(4):
        print("?", end = "")   # Named arguement: default end makes print go to next line
    print()

    print("?" * 4)      # repeats 4 times

    # next two are same
    for i in range (3):
        for j in range (3):
            print("#", end = "")
        print()

    for i in range (3):
        print("#" * 3)

def get_height():
    while True:
        n = get_int("Height: ")       # or int(input("Height: "))
        if n > 0:
            return n
        #try: except: else:  blocks->look at scores.py

main()