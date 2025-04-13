from cs50 import get_string


# Prompt the user to enter the credit card number
def main():
    while True:
        card_number = get_string("Number: ")
        length = len(card_number)
        if sum_check(card_number):

            # Determine the type of credit card
            if card_number.isnumeric() and (length == 13 or length == 15 or length == 16):
                if card_number[0] == "4":
                    print("VISA")
                elif card_number[0:2] in ["34", "37"]:
                    print("AMEX")
                elif card_number[0:2] in ["51", "52", "53", "54", "55"]:
                    print("MASTERCARD")
                else:
                    print("INVALID")
                break
            else:
                print("INVALID")
                break
        else:
            print("INVALID")
            break


# Determine if the number is valid
def sum_check(card_number):
    digits = 0
    odd_sum = 0
    even_sum = 0
    card_number = card_number[::-1]  # reverse the card number
    for i in range(len(card_number)):

        # Part 1: Adds the digits that are multiplied by 2
        if ((i + 1) % 2) == 0:
            digits = (int(card_number[i]) * 2)
            if digits / 10 > 0:
                digits = round((digits % 10), 1) + (digits // 10)
            even_sum = even_sum + digits

        # Part 2: Add the remaining digits that are not multiplied by 2
        else:
            odd_sum = odd_sum + int(card_number[i])

    # Part 3: Add Part 1 & Part 2 and check if the last digit is zero
    if (even_sum + odd_sum) % 10 == 0:
        return True


main()
