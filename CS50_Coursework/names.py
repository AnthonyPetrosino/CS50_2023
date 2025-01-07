import sys
# Linear search
names = ["Charlie", "Bob", "Steve", "Sads", "Anthony"]

name = input("Name: ")

if name in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)