from cs50 import get_float


while True:
    cents = get_float("Change: ")
    if cents > 0:
        break

cents = round(cents * 100)
num = 0

while cents >= 25:
    cents = cents - 25
    num += 1

while cents >= 10:
    cents = cents - 10
    num += 1

while cents >= 5:
    cents = cents - 5
    num += 1

while cents >= 1:
    cents = cents - 1
    num += 1

print("Coins total:", num)
