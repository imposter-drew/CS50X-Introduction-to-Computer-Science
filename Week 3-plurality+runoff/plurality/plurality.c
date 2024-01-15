#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    //take "name" and check if it matches oneof the names of the candidate.name (for loop through candidate[i].name) return true
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //repeat x numbner of times according to candidate count
    for (int x = 0; x < candidate_count; x++)
    {
        //bubble sort candidates[i].votes in descending order
        for (int i = 0; i < (candidate_count - 1); i++)
        {
            if (candidates[i].votes < candidates[i + 1].votes)
            {
                candidate swap = candidates[i + 1];
                candidates[i + 1] = candidates[i];
                candidates[i] = swap;
            }
        }
    }

    //one winner - print only 1st name in candidates[0].votes
    printf("%s\n", candidates[0].name);

    //two or more winners - loop to check if candidates[0+i] is equal to previous. if so print it in a new line
    for (int i = 0; candidates[i].votes == candidates[i + 1].votes; i++)
    {
        printf("%s\n", candidates[i + 1].name);
    }
    return;
}