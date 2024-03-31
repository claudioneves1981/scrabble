#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 == score2){
        printf("%s\n","Tie!");
    }else if(score1 < score2){
        printf("%s\n","Player 2 wins!");
    }else{
        printf("%s\n","Player 1 wins!");
    }

    // TODO: Print the winner
}

int compute_score(string word)
{
    int sum = 0;
    int index = 0;

    for(int i = 0, n = strlen(word); i < n; i++){

        if(islower(word[i])){

            index = (char)word[i] - 97;
            sum = sum + POINTS[index];

        }else if(isupper(word[i])){

            index = (char)word[i] - 65;
            sum = sum + POINTS[index];

        }else{
            
            sum = sum + 0;
        }
    }

    return sum;
    // TODO: Compute and return score for string
}
