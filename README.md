# CS50X-Introduction-to-Computer-Science

## This is my personal repository for all the problem sets in the CS50X course.

### Week 1 - C
##### Mario
Recreate a pyramid in C, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself will also be taller than it is wide.

       #
      ##
     ###
    ####
   #####
  ######
 #######
########

#### Cash

-Implement get_cents in such a way that the function prompts the user for a number of cents using get_int and then returns that number as an int. If the user inputs a negative int, your code should prompt the user again.
-Implement calculate_quarters in such a way that the function calculates (and returns as an int) how many quarters a customer should be given if they’re owed some number of cents. For instance, if cents is 25, then calculate_quarters should return 1. If cents is 26 or 49 (or anything in between, then calculate_quarters should also return 1. If cents is 50 or 74 (or anything in between), then calculate_quarters should return 2. And so forth.
-Implement calculate_dimes in such a way that the function calculates the same for dimes.
-Implement calculate_nickels in such a way that the function calculates the same for nickels.
-Implement calculate_pennies in such a way that the function calculates the same for pennies.


### Week 2 - Arrays
#### Readability
##### Design and implement a program, readability, that computes the Coleman-Liau index of text.

-Your program must prompt the user for a string of text using get_string.
-Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
-Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
-If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

#### Bulbs
##### Design and implement a program, bulbs, that converts text into instructions for the strip of bulbs on CS50’s stage as follows:

-Your program must first ask the user for a message using get_string.
-Your program must then convert the given string into a series of 8-bit binary numbers, one for each character of the string.
-You can use the provided print_bulb function to print a series of 0s and 1s as a series of yellow and black emoji, which represent on and off light bulbs.
-Each “byte” of 8 symbols should be printed on its own line when outputted; there should be a \n after the last “byte” of 8 symbols as well.


### Week 3 - Algorithms
#### Plurality
##### Complete the implementation of plurality.c in such a way that the program simulates a plurality vote election.

-Complete the vote function.
-vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
-If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote. The vote function in this case should return true to indicate a successful ballot.
-If name does not match the name of any of the candidates in the election, no vote totals should change, and the vote function should return false to indicate an invalid ballot.
-You may assume that no two candidates will have the same name.
-The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
-It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.

#### Runoff
##### Complete the implementation of runoff.c in such a way that it simulates a runoff election. You should complete the implementations of the vote, tabulate, print_winner, find_min, is_tie, and eliminate functions, and you should not modify anything else in runoff.c (and the inclusion of additional header files, if you’d like).

vote()
-The function takes arguments voter, rank, and name. If name is a match for the name of a valid candidate, then you should update the global preferences array to indicate that the voter voter has that candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.).
-If the preference is successfully recorded, the function should return true; the function should return false otherwise (if, for instance, name is not the name of one of the candidates).
-You may assume that no two candidates will have the same name.

tabulate()
-The function should update the number of votes each candidate has at this stage in the runoff.
-Recall that at each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.

print_winner()
-If any candidate has more than half of the vote, their name should be printed and the function should return true.
-If nobody has won the election yet, the function should return false.

find_min()
-The function should return the minimum vote total for any candidate who is still in the election.

is_tie()
-The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
-The function should return true if every candidate remaining in the election has the same number of votes, and should return false otherwise.

eliminate()
-The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
-The function should eliminate the candidate (or candidates) who have min number of votes.


### Week 4 - Memory
#### Filter
##### Implement the functions in helpers.c such that a user can apply grayscale, sepia, reflection, or blur filters to their images.

-The function grayscale should take an image and turn it into a black-and-white version of the same image.
-The function sepia should take an image and turn it into a sepia version of the same image.
-The reflect function should take an image and reflect it horizontally.
-Finally, the blur function should take an image and turn it into a box-blurred version of the same image.
-You should not modify any of the function signatures, nor should you modify any other files other than helpers.c.

#### Reverse
##### Write a program called called reverse that reverse a WAV file given by the user and create a new WAV file that contains the resulting reversed audio. At the time the user executes the program, they should provide, using two command-line arguments, the name of the input file to be read and reversed, and the name of the output file they would like to save the resulting audio in. A successfully executed program should not output any text, and should create a WAV file with the user-specified name that plays the audio of the input WAV file in reverse. For example:

-You should ensure the program accepts two command-line arguments: the name of the input WAV file and the name of the output WAV file. If the program does not meet these conditions, you should print an appropriate error message and return 1, ending the program.
-You should open your input file. We’ll need to open the input file in “read-only” mode, since we’ll only read data from the input file. It may be wise to check that the file has been opened successfully. Otherwise, you should print an appropriate error message and return 1, exiting the program. We should hold off on opening the output file, though, lest we create a new WAV file before knowing the input file is valid!
-You should read the header from the input file. Recall that, in wav.h, we’ve already implemented a struct that can store a WAV file’s header. Since we’ve written #include "wav.h" at the top of reverse.c, you, too, can use the WAVHEADER struct.
-You should complete the check_format function. check_format takes a single argument, a WAVHEADER called header, representing a struct containing the input file’s header. If header indicates the file is indeed a WAV file, the check_format function should return true. If not, check_format should return false. To check if a file is of the WAV format, we can compare the elements from the input file header to those we would expect from a WAV file. It suffices to show the “WAVE” marker characters are found in the format member of the WAVHEADER struct (see Background for more detail on WAV file headers).
-Write the header to the output file. The reversed WAV file will still have the same underlying file structure as the input file (same size, number of channels, bits per sample, etc.).
-You should implement the get_block_size function. get_block_size, like check_format, takes a single argument: this is a WAVHEADER called header, representing the struct containing the input file’s header. get_block_size should return an integer representing the block size of the given WAV file, in bytes.
-We need to read in each block of auditory data starting from the very end of the input file and moving backwards, simultaneously writing each block to the output file so they are written in reverse order. First, we should declare an array to store each block we read in. Then, it’s up to you to iterate through the input file audio data. You’ll want to be sure you read through all of the audio, but don’t erroneously copy any of the data from the header! Additionally, for testing purposes, we would like to maintain the order of the channels for each audio block. For example, in a WAV file with two channels (stereophonic sound), we want to make sure that the first channel of the last audio block in the input becomes the first channel of the first audio block in the output.
-Finally, be sure to close any files you’ve opened!

### Week 5 - Data Structures
#### Speller
##### Implement, in order, load, hash, size, check, and unload functions as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. To be sure, it’s not obvious what it even means to be minimized, inasmuch as these benchmarks will certainly vary as you feed speller different values for dictionary and for text. But therein lies the challenge, if not the fun, of this problem. This problem is your chance to design. Although we invite you to minimize space, your ultimate enemy is time. But before you dive in, some specifications from us.

-You may not alter speller.c or Makefile.
-You may alter dictionary.c (and, in fact, must in order to complete the implementations of load, hash, size, check, and unload), but you may not alter the declarations (i.e., prototypes) of load, hash, size, check, or unload. You may, though, add new functions and (local or global) variables to dictionary.c.
-You may change the value of N in dictionary.c, so that your hash table can have more buckets.
-You may alter dictionary.h, but you may not alter the declarations of load, hash, size, check, or unload.
-Your implementation of check must be case-insensitive. In other words, if foo is in dictionary, then check should return true given any capitalization thereof; none of foo, foO, fOo, fOO, fOO, Foo, FoO, FOo, and FOO should be considered misspelled.
-Capitalization aside, your implementation of check should only return true for words actually in dictionary. Beware hard-coding common words (e.g., the), lest we pass your implementation a dictionary without those same words. Moreover, the only possessives allowed are those actually in dictionary. In other words, even if foo is in dictionary, check should return false given foo's if foo's is not also in dictionary.
-You may assume that any dictionary passed to your program will be structured exactly like ours, alphabetically sorted from top to bottom with one word per line, each of which ends with \n. You may also assume that dictionary will contain at least one word, that no word will be longer than LENGTH (a constant defined in dictionary.h) characters, that no word will appear more than once, that each word will contain only lowercase alphabetical characters and possibly apostrophes, and that no word will start with an apostrophe.
-You may assume that check will only be passed words that contain (uppercase or lowercase) alphabetical characters and possibly apostrophes.
-Your spell checker may only take text and, optionally, dictionary as input. Although you might be inclined (particularly if among those more comfortable) to “pre-process” our default dictionary in order to derive an “ideal hash function” for it, you may not save the output of any such pre-processing to disk in order to load it back into memory on subsequent runs of your spell checker in order to gain an advantage.
-Your spell checker must not leak any memory. Be sure to check for leaks with valgrind.
-The hash function you write should ultimately be your own, not one you search for online. There are many ways to implement a hash function beyond using the first character (or characters) of a word. Consider a hash function that uses a sum of ASCII values or the length of a word. A good hash function tends to reduce “collisions” and has a fairly even distribution across hash table “buckets”.

### Week 6 - Python
#### Sentimental-Mario
##### Write, in a file called mario.py, a program that recreates the half-pyramid using hashes (#) for blocks, exactly as you did in Problem Set 1, except that your program this time should be written in Python.

-To make things more interesting, first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive.
-If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again.
-Then, generate (with the help of print and one or more loops) the desired half-pyramid.
-Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.

#### Sentimental-Cash
##### Write, in a file called cash.py, a program that first asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made. You can do this exactly as you did in Problem Set 1, except that your program this time should be written in Python, and you should assume that the user will input their change in dollars (e.g., 0.50 dollars instead of 50 cents).

-Use get_float from the CS50 Library to get the user’s input and print to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
-We ask that you use get_float so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be 9.75 and not $9.75 or 975. However, if some customer is owed $9 exactly, assume that your program’s input will be 9.00 or just 9 but, again, not $9 or 900. Of course, by nature of floating-point values, your program will likely work with inputs like 9.0 and 9.000 as well; you need not worry about checking whether the user’s input is “formatted” like money should be.
-If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.

#### Sentimental-Readability
##### Write, in a file called readability.py, a program that first asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula, exactly as you did in Problem Set 2, except that your program this time should be written in Python.

-Recall that the Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8, where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
-Use get_string from the CS50 Library to get the user’s input, and print to output your answer.
-Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and -that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
-Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
-If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

#### DNA
##### In a file called dna.py, implement a program that identifies to whom a sequence of DNA belongs.

-The program should require as its first command-line argument the name of a CSV file containing the STR counts for a list of individuals and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.
-If your program is executed with the incorrect number of command-line arguments, your program should print an error message of your choice (with print). If the correct number of arguments are provided, you may assume that the first argument is indeed the filename of a valid CSV file and that the second argument is the filename of a valid text file.
-Your program should open the CSV file and read its contents into memory.
-You may assume that the first row of the CSV file will be the column names. The first column will be the word name and the remaining columns will be the STR sequences themselves.
-Your program should open the DNA sequence and read its contents into memory.
-For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats of the STR in the DNA sequence to identify. Notice that we’ve defined a helper function for you, longest_match, which will do just that!
-If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
-You may assume that the STR counts will not match more than one individual.
-If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print No match.

### Week 7 - SQL
#### Movies
##### For each of the following problems, you should write a single SQL query that outputs the results specified by each problem. Your response must take the form of a single SQL query, though you may nest other queries inside of your query. You should not assume anything about the ids of any particular movies or people: your queries should be accurate even if the id of any particular movie or person were different. Finally, each query should return only the data necessary to answer the question: if the problem only asks you to output the names of movies, for example, then your query should not also output each movie’s release year.

-In 1.sql, write a SQL query to list the titles of all movies released in 2008.
Your query should output a table with a single column for the title of each movie.

-In 2.sql, write a SQL query to determine the birth year of Emma Stone.
Your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
You may assume that there is only one person in the database with the name Emma Stone.

-In 3.sql, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
Your query should output a table with a single column for the title of each movie.
Movies released in 2018 should be included, as should movies with release dates in the future.

-In 4.sql, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
Your query should output a table with a single column and a single row (not counting the header) containing the number of movies with a 10.0 rating.

-In 5.sql, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.

-In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
Your query should output a table with a single column and a single row (not counting the header) containing the average rating.

-In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
Movies that do not have ratings should not be included in the result.

-In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
Your query should output a table with a single column for the name of each person.
You may assume that there is only one movie in the database with the title Toy Story.

-In 9.sql, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
Your query should output a table with a single column for the name of each person.
People with the same birth year may be listed in any order.
No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
If a person appeared in more than one movie in 2004, they should only appear in your results once.

-In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
Your query should output a table with a single column for the name of each person.
If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.

-In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Chadwick Boseman.

-In 12.sql, write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Bradley Cooper.
You may assume that there is only one person in the database with the name Jennifer Lawrence.

-In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.

#### Fiftyville
##### For this problem, equally as important as solving the mystery itself is the process that you use to solve the mystery. In log.sql, keep a log of all SQL queries that you run on the database. Above each query, label each with a comment (in SQL, comments are any lines that begin with --) describing why you’re running the query and/or what information you’re hoping to get out of that particular query. You can use comments in the log file to add additional notes about your thought process as you solve the mystery: ultimately, this file should serve as evidence of the process you used to identify the thief!

Once you solve the mystery, complete each of the lines in answers.txt by filling in the name of the thief, the city that the thief escaped to, and the name of the thief’s accomplice who helped them escape town. (Be sure not to change any of the existing text in the file or to add any other lines to the file!)


### Week 8 - HTML, CSS, JavaScript
#### Homepage

Implement in your homepage directory a website that must:
-Contain at least four different .html pages, at least one of which is index.html (the main page of your website), and it should be possible to get from any page on your website to any other page by following one or more hyperlinks.

-Use at least ten (10) distinct HTML tags besides <html>, <head>, <body>, and <title>. Using some tag (e.g., <p>) multiple times still counts as just one (1) of those ten!

-Integrate one or more features from Bootstrap into your site. Bootstrap is a popular library (that comes with lots of CSS classes and more) via which you can beautify your site. See Bootstrap’s documentation to get started. In particular, you might find some of Bootstrap’s components of interest.

-Have at least one stylesheet file of your own creation, styles.css, which uses at least five (5) different CSS selectors (e.g. tag (example), class (.example), or ID (#example)), and within which you use a total of at least five (5) different CSS properties, such as font-size, or margin; and
-Integrate one or more features of JavaScript into your site to make your site more interactive. For example, you can use JavaScript to add alerts, to have an effect at a recurring interval, or to add interactivity to buttons, dropdowns, or forms. Feel free to be creative!

-Ensure that your site looks nice on browsers both on mobile devices as well as laptops and desktops.


### Week 9 - Flask
#### Birthdays
##### Complete the implementation of a web application to let users store and keep track of birthdays.

-When the / route is requested via GET, your web application should display, in a table, all of the people in your database along with their birthdays.
-First, in app.py, add logic in your GET request handling to query the birthdays.db database for all birthdays. Pass all of that data to your index.html template.
-Then, in index.html, add logic to render each birthday as a row in the table. Each row should have two columns: one column for the person’s name and another column for the person’s birthday.
-When the / route is requested via POST, your web application should add a new birthday to your database and then re-render the index page.
-First, in index.html, add an HTML form. The form should let users type in a name, a birthday month, and a birthday day. Be sure the form submits to / (its “action”) with a method of post.
-Then, in app.py, add logic in your POST request handling to INSERT a new row into the birthdays table based on the data supplied by the user.

Optionally, you may also:
-Add the ability to delete and/or edit birthday entries.
-Add any additional features of your choosing!
