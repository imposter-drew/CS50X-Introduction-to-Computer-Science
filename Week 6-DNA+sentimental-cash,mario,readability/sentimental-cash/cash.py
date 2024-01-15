# TODO
# Note: There is a float arithmetic issue displaying incorrectly the result
# so the workaround is to multiply *100 and then divide /100 in each function
from cs50 import get_float


# Define functions for each coin
def calculate_quarters(change):
    quarters = 0
    while change >= 0.25:
        change = change * 100 - 25  # workaround the float imprecision
        change = change / 100
        quarters += 1
    return quarters


def calculate_dimes(change):
    dimes = 0
    while change >= 0.10:
        change = change * 100 - 10
        change = change / 100
        dimes += 1
    return dimes


def calculate_nickels(change):
    nickels = 0
    while change >= 0.05:
        change = change * 100 - 5
        change = change / 100
        nickels += 1
    return nickels


def calculate_pennies(change):
    pennies = 0
    while change >= 0.01 and change <= 0.04:
        change = change * 100 - 1
        change = change / 100
        pennies += 1
    return pennies


def main():
    # Ask how many cents the customer is owed
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            break
    # Calculate the number of quarters to give (function)
    quarters = calculate_quarters(change)
    change = change * 100 - quarters * 25
    change = change / 100

    # Calculate the number of dimes to give (function)
    dimes = calculate_dimes(change)
    change = change * 100 - dimes * 10
    change = change / 100

    # Calculate the number of nickels to give (function)
    nickels = calculate_nickels(change)
    change = change * 100 - nickels * 5
    change = change / 100

    # Calculate the number of pennies to give (function)
    pennies = calculate_pennies(change)
    change = change * 100 - pennies * 1
    change = change / 100

    # Sum coins
    total = quarters + dimes + nickels + pennies

    # Print total number of coins
    print(total)


main()
