# TODO
from cs50 import get_int

# get user input
while True:
    h = get_int("Height: ")
    if h > 0 and h <= 8:
        break

blank = h - 1  # To print blank spaces before #
for i in range(h):
    print(" " * blank, end="")
    blank -= 1
    print("#" * (i + 1))
