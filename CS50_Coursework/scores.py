scores = [72, 73, 33]

# len == length of list
average = sum(scores) / len(scores)
print(f"Average: {average}")

scores2 = []
count = 0
while count != 3:
    try:
        score = int(input("Score: "))
        if score > 0:
            count = count + 1
            scores2.append(score)  ## or scores2 += [score]
    except ValueError:
        print("Not an integer")

average2 = sum(scores2) / len(scores2)
print(f"Average 2: {average2}")

before = input("Before: ")
print("After: ", end = "")
for c in before:
    print(c.upper(), end = "")
print()

