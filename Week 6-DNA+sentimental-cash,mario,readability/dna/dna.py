import csv
import sys


def main():
    # TODO: Check for command-line usage
    # the first argument is the filename of a valid CSV file
    # and the second argument is the filename of a valid text file.
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    # the first row of the CSV file will be the column names.
    # The first column will be the word name and the remaining columns will be the STR sequences themselves.
    database = []
    # Create a list of possible subsequences from database.
    subsequence = []
    with open(sys.argv[1]) as file:
        datareader = csv.DictReader(file)
        for line in datareader:
            for i in line:
                if i != "name":
                    # Add value to the subsequence list
                    if i not in subsequence:
                        subsequence.append(i)
                    line[i] = int(line[i])  # conversion to int
            # Insert in database with proper data values
            database.append(line)

    # TODO: Read DNA sequence file into a variable
    # For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats
    # of the STR in the DNA sequence to identify. Notice that we’ve defined a helper function for you, longest_match, which will do just that!
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # For each STR (subsequence?) compute the longest run of consecutive repeats in the DNA sequence given
    # create a list of the repeat counts for each STR. EX: AGAT : 14, TTCT: 25
    # Compare STR counts against each row of the csv file (database)
    # go to the specific STR entry in the database dictionary

    longestmatch = {}  # dictionary to store the results for each sequence
    for i in subsequence:
        longestmatch[i] = longest_match(sequence, i)

    # TODO: Check database for matching profiles
    # Check if the number of repetitions returned from the function matches the number of any of the dictionary members
    # If the STR counts match exactly with any of the individuals in the CSV file,
    # your program should print out the name of the matching individual and stop.
    # else, print no match

    name = "empty"  # To save the name of the match
    # Compare keys in both dictionaries (database and results), then go to their values and compare
    for row in database:
        for key in longestmatch.keys():
            if key in row.keys():
                if row[key] != longestmatch[key]:
                    check = False
                    break
                else:
                    check = True

        if check == True:
            name = row["name"]  # Save the nameof the match
            break

    if name == "empty":
        print("No match")
    else:
        print(name)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
