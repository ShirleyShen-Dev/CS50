from cs50 import get_string

text = get_string("Text: ")

letters = 0
spaces = 0
sentences = 0

for c in text:
    # Count letters
    if c.isalpha():
        letters += 1

    # Count spaces
    if c == " ":
        spaces += 1

    # Count ".", "?", "!"
    if c in [".", "!", "?"]:
        sentences += 1

words = spaces + 1

# Calculate CL index inputs
l = letters / (words / 100)
s = sentences / (words / 100)

# Calculate and return CL index
cl_index = round(0.0588 * l - 0.296 * s - 15.8)

# Print grade level
if cl_index < 1:
    print("Before Grade 1")
elif cl_index > 16:
    print("Grade 16+")
else:
    print(f"Grade {cl_index}")