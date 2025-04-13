from cs50 import get_float


def main():  # Prompt the user to input the change owed
    while True:
        change = get_float("Change: ")
        if change > 0:
            break
    coins(change)


def coins(change):  # Calculate & print the minimum number of coins
    quarters = 0
    while change >= 0.25:
        quarters += 1
        change = change - 0.25
        change = round(change, 2)

    dimes = 0
    while change >= 0.10:
        dimes += 1
        change = change - 0.10
        change = round(change, 2)

    nickels = 0
    while change >= 0.05:
        nickels += 1
        change = change - 0.05
        change = round(change, 2)

    pennies = 0
    while change >= 0.01:
        pennies += 1
        change = change - 0.01
        change = round(change, 2)

    coins = 0
    coins = quarters + dimes + nickels + pennies

    print(f"{coins}")


main()
