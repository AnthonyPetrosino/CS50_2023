from cs50 import get_int


def main():
    height = get_height()
    for i in range(height):
        print((" " * (height - i - 1)) + ("#" * (i + 1)), end="")
        print()


def get_height():
    while True:
        n = get_int("Height: ")  # or int(input("Height: "))
        if n > 0 and n < 9:
            return n
        # try: except: else:  blocks->look at scores.py


main()
