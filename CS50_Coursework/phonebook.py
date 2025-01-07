import csv # csv = coma seperated values

with open("phonebook.csv", "a") as file:  # append mode
    name = input("Name: ")
    number = input("Number: ")

    writer = csv.DictWriter(file, fieldnames = ["name", "number"])
    writer.writerow({"name": name, "number": number})

# an empty "chart" (T), index into it with a string (kind of like a hashmap)
people = {
    "Carter": "123",
    "David": "456",
    "Anthony": "789"
}

name = input("Name: ")

# Python optimizes search for almost always constant time (O(n))
#if name in people:
    # print(f"Number: {people[name]})


