from cs50 import get_int

# Prompts the user for the pyramid's height
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Prints the pyramid
for i in range(height):

    # Prints the left spaces
    print(" " * (height - (i + 1)), end="")

    # Prints the left bricks
    for j in range(i + 1):
        print("#", end="")

    # Prints the middle spaces
    print("  ", end="")

    # Prints the right bricks
    for j in range(i + 1):
        print("#", end="")
    print()
