import re
from cs50 import get_string


def main():
    # Prompt the user for some text
    text = get_string("Text: ")
    index = Coleman_Liau(text)

    # Print the grade level
    if (index < 1):
        print("Before Grade 1")
    elif (index > 16):
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")


def Coleman_Liau(text):
    index = l_count = w_count = s_count = 0

    # Count the number of letters, words, and sentences in the text
    l_count = len(re.findall(r'[a-zA-Z]', text))

    w_count = len(re.findall(r'[a-zA-Z\'\-]*[^"* 0-9_.,?!]', text))

    s_count = len(re.findall(r'[.!?]', text))

    # Compute the Coleman-Lia index
    index = 0.0588 * ((l_count / w_count) * 100) - 0.296 * ((s_count / w_count) * 100) - 15.8
    return index


main()
