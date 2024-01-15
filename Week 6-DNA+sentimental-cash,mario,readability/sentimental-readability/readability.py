# TODO
from cs50 import get_string


def main():
    # prompt user for text
    text = get_string("Text: ")

    # detect how many letters
    letters = count_letters(text)

    # detect how many words
    words = count_words(text)

    # detect how many sentences
    sentences = count_sentences(text)

    # Apply Coleman-Liau index, rounding to closest
    index = calculate_grade(letters, words, sentences)

    # Print grade. If >= 16 is "Grade 16", if < 1 is "Before Grade 1"
    if index < 1:
        print("Before Grade 1")

    elif index >= 16:
        print("Grade 16+")

    else:
        print(f"Grade {index}")


def count_letters(text):
    letters = 0
    for x in text:
        if x.isalpha():
            letters += 1
    return letters


def count_words(text):
    words = 1  # for the last word in the text is not counted
    for x in text:
        if x.isspace():
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for x in text:
        if x == "." or x == "!" or x == "?":
            sentences += 1
    return sentences


def calculate_grade(letters, words, sentences):
    l = letters / words * 100
    s = sentences / words * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    index = round(index)
    return index


main()
