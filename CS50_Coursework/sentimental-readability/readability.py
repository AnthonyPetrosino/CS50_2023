from cs50 import get_string

text = get_string("Text: ")

letterCount = 0

for chars in text:
    if chars.isalpha():
        letterCount += 1

wordCount = len(text.split())
sentenceCount = text.count(".") + text.count("!") + text.count("?")

# formula: 0.0588 * L - 0.296 * S - 15.8

L = letterCount / wordCount * 100
S = sentenceCount / wordCount * 100

gradeLevel = 0.0588 * L - 0.296 * S - 15.8

if gradeLevel >= 16:
    print("Grade 16+")
elif gradeLevel < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(gradeLevel)}")
