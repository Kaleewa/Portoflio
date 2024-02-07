import random

wordlist = ('ant baboon badger bat bear beaver camel cat clam cobra cougar '
         'coyote crow deer dog donkey duck eagle ferret fox frog goat '
         'goose hawk lion lizard llama mole monkey moose mouse mule newt '
         'otter owl panda parrot pigeon python rabbit ram rat raven '
         'rhino salmon seal shark sheep skunk sloth snake spider '
         'stork swan tiger toad trout turkey turtle weasel whale wolf '
         'wombat zebra ').split()


HANGMANPICS = ['''
  +---+
  |   |
      |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']

def play_hangman():

    word = random.choice(wordlist)
    hangmanword = "_" * (len(word))
    guessedletters = ""
    maxguess = 7
    numguess = 0

    print("Try to guess the animal!")
    print(hangmanword)

    while True:
        guess = input("Your guess: ")
        if guess in guessedletters:
            print("You already guessed this letter.")
            continue
        
        guessedletters += guess
        numguess += 1

        if guess in word:
            for letter in guess:
                for i in range(len(word)):
                    if word[i] == letter:
                        hangmanword = hangmanword[:i] + letter + hangmanword[i+1:]
            print(hangmanword)

            if "_" not in hangmanword:
                print("Well done you guessed the word!")
                break
            
        else:
            print("Incorrect.")
            print(HANGMANPICS[numguess -1])
        
        if numguess == maxguess:
            print(f"You have used all your guesses. The word was {word}") 
            break  
    
    play_again = input("Would you like to play again? (yes/no): ")
    return play_again.lower() == "yes"

while True:
    if not play_hangman():
        print("Thanks for playing!")
        break

            
            
        



