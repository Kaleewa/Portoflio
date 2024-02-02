#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WRONG_GUESSES 6

char* words[] = {"PROGRAMMING", "COMPUTER", "PYTHON", "CODING", "ALGORITHM", 
                 "DEBUGGING", "CONTROLLER", "SAILOR", "ELIMINATE", "ULTIMATE",
                 "ENGINEER", "DATABASE", "INTERFACE", "OPERATING", "NETWORK", 
                 "SECURITY", "DEVELOPER", "APPLICATION", "FRAMEWORK", "LANGUAGE",
                 "INTELLIGENCE", "SOFTWARE", "HARDWARE", "ELECTRONIC", "INFORMATION"};

void displayHangman(int wrongGuesses) {
    switch (wrongGuesses) {
        case 0:
            printf("\n\n");
            break;
        case 1:
            printf("\n\n   O\n");
            break;
        case 2:
            printf("\n\n   O\n   |\n");
            break;
        case 3:
            printf("\n\n   O\n  /|\n");
            break;
        case 4:
            printf("\n\n   O\n  /|\\\n");
            break;
        case 5:
            printf("\n\n   O\n  /|\\\n  /\n");
            break;
        case 6:
            printf("\n\n   O\n  /|\\\n  / \\\n");
            break;
        default:
            break;
    }
}
int main() {
    srand(time(NULL));
    char word[50];
    char playAgain;
    do {
        strcpy(word, words[rand() % (sizeof(words) / sizeof(words[0]))]); // randomly choose a word from the list
        int wordLength = strlen(word);
        char guessedLetters[26] = {'\0'};
        int wrongGuesses = 0;

        printf("Welcome to Hangman!\n");
        printf("Try to guess the word. You can make up to %d wrong guesses.\n", MAX_WRONG_GUESSES);
        
        while (1) {
            printf("\nWord: ");
            int allLettersGuessed = 1; // assume all letters are guessed until proven otherwise
            for (int i = 0; i < wordLength; i++) {
                if (strchr(guessedLetters, word[i])) { // go through each letter to see which are guessed
                    printf("%c ", word[i]);
                } else {
                    printf("_ ");
                    allLettersGuessed = 0; // at least one letter is not guessed
                }
            }
            printf("\n");

            if (allLettersGuessed) {
                printf("Congratulations! You guessed the word: %s\n", word);
                break;
            }

            if (wrongGuesses == MAX_WRONG_GUESSES) {
                printf("You lost! The word was: %s\n", word);
                break;
            }

            printf("Enter a letter: ");
            char guess;
            scanf(" %c", &guess);
            guess = toupper(guess);

            if (!strchr(word, guess) && !strchr(guessedLetters, guess)) { // checks if guess is in word and if its in guessed letters
                wrongGuesses++;
                printf("Wrong guess! You have %d guesses left.\n", MAX_WRONG_GUESSES - wrongGuesses);
                displayHangman(wrongGuesses);
            }
            if (strchr(guessedLetters, guess)) { //if the letter is in guessed letters it will delete it and tell you about it
                printf("You already guessed that!");
                guessedLetters[strlen(guessedLetters) - 1] = '\0';
            }
            guessedLetters[strlen(guessedLetters)] = guess;
            guessedLetters[strlen(guessedLetters) + 1] = '\0';
        }
        printf("Do you want to play again? (Y/N);\n ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);

    
    } while (playAgain == 'Y');
    
    printf("Thanks for playing!\n");
    return 0;
}

