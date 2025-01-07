# flat file database usage
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        print(row["Language"])
        if row in reader:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in sorted(counts, key=lambda language: counts[language], reverse=True):
    print(f"{favorite}: {counts[favorite]}")

