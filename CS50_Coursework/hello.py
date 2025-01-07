from cs50 import get_string, get_int

print("Hello, world")

answer = get_string("What's your name? ")
# print("hello, " + answer) # concatenate
# print("hello,", answer) works as well
print(f"hello, {answer}") # answer is interpolated/substituted/best

# data types: int, float, bool, str
# no limit on int/float size
# range, list (replaces array), tuple, dict (has table), set (gets rid of duplicates)

words = set()

def check(word): # indentation represents what is where
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dicitonary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    clsoe(file)
    return True

def size():
    return len(words)

def unload():
    return True

# YOU CAN IMPORT FACE RECOGNITION
# import face_recognition

# from cs50 import get_int, get_float, get_string

# variables:
x = 0
y = 0

x += 1 # NO ++
y = y + 1

# conditionals:
if x < y:
    x = x
elif x > y:
    x = x
else:
    x = x

# loops:
i = 0
while i < 3:
    print("yuh")
    i += 1

# for i in [0, 1, 2]:     [] denotes a list, iterates through loop three times
    # print("hello, world")

for i in range(3):      # range is a data type, lets you iterate how many times you put in, EFFICIENT
    print("hello, world")

# while True:   # infinite loop
    # print("...")

# calculator:

x = get_int("x: ")
y = get_int("y: ")

# real world programming:
# x = int(input("x: "))   typecasting char to an int
# y = int(input("y: "))

print(x + y)

z = x / y # does not truncate the int, converts int z to a float automatically

print(z)
print(f"{z:.50f}") # FLOATING POINT IMPRCESION issue

if x < y:
    print("x < y")
elif x > y:
    print("x > y")
else:
    print("x = y")

# bool comparisons
s = input("Do you agree? ")

# s is a str OBJECT (OOP)

if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")

# str objects cannot be changed at char locations, only coppies can be returned (s.lower() returns copy of s)

if s.lower() in ["y", "yes"]:
    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")

# use seperate function meow
# use of main function
def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

# main is called at the end of the program so all used functions are
# initialized before it is called
main()