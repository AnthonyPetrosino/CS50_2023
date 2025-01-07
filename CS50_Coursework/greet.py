import sys

if len(sys.argv) < 2:
    print("Missing command-line arguement")
    sys.exit(1)

if len(sys.argv) == 2:
    print(f"Hello, {sys.argv[1]}")
else:
    print("Hello, world")

for arg in sys.argv[1:len(sys.argv)]:       # skips 0, goes through 1-length; [1:] also works
    print(arg)

