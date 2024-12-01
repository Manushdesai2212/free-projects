
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define WORD_COUNT 5 /*this much words are there in array*/
#define no_guess 6   /*number of guesses user have*/
void display_word(const char *selected_word, int length, const int *correct_guess) /*displays charactor which guessed else blank space*/
{
  int i;
  for (i = 0; i < length; i++)
  {
    if (correct_guess[i])
    {
      printf("%c", selected_word[i]);
    }
    else
    {
      printf("_");
    }
  }
}
int check_guees(int length, const char *selected_word, char guess, int *correct_word)/*checks the charactor entered by user is correct or not*/
{
  int correct = 0, i;
  for (i = 0; i < length; i++)
  {
    if (selected_word[i] == guess && !correct_word[i])
    {
      correct_word[i] = 1;
      correct = 1;
    }
  }
  return correct;
}
void RPS_game(void)
{
  int user, rock, paper, scissor, highscore = 0;
  time_t start_time = time(NULL); /*it starts time from 0 secound*/
  int time_left = 30;             /*total time*/
  printf("\nyou have 30 secounds to play this game\n");

  while (difftime(time(NULL), start_time) < 30) /*runs till time comes to 30 secouds*/
  {
    time_left = 30 - (int)difftime(time(NULL), start_time); /*shows time left*/
    printf("Time remaining: %d seconds\n", time_left);

    if (highscore == 5)
    {
      printf("you win the game yee!");
      break;
    }
    else
    {

      printf("enter 0 for rock ,1 for paper or 2 for scissor\n");
      scanf("%d", &user);
      rock = 0;
      paper = 1;
      scissor = 2;
      srand(time(0));

      int randomNumber = rand() % 3; /*generates number between 1 to 3*/

      if (randomNumber == 0)
      {
        printf("compter selected stone\n");
      }
      else if (randomNumber == 1)
      {
        printf("compter selected paper \n");
      }
      else if (randomNumber == 2)
      {
        printf("compter selected scissor\n ");
      }

      if (user == 0 && randomNumber == 1)
      {
        printf("computer wins\n");
      }
      else if (user == 0 && randomNumber == 2)
      {
        printf("computer loose\n");
        highscore++;
      }
      else if (user == 0 && randomNumber == 0)
      {
        printf("draw\n");
      }
      else if (user == 1 && randomNumber == 0)
      {
        printf("computer loose\n");
        highscore++;
      }
      else if (user == 1 && randomNumber == 1)
      {
        printf("draw\n");
      }
      else if (user == 1 && randomNumber == 2)
      {
        printf("computer wins\n");
      }
      else if (user == 2 && randomNumber == 0)
      {
        printf("computer wins\n");
      }
      else if (user == 2 && randomNumber == 1)
      {
        printf("computer loose\n");
        highscore++;
      }
      else if (user == 2 && randomNumber == 2)
      {
        printf("draw\n");
      }
    }

    printf("your score is %d\n", highscore);
  }
  if (highscore < 5)
  {
    printf("Time's up! You lost the game.\n");
  }

  printf("\nyour score is %d\n", highscore);
}

int main()
{
  int n, word_Lenght, i;
  const char *selected_word;
  int incorrect_guess = 0;
  printf("WELCOME TO THE HANG MAN GAME!!!\n");
  printf("let's start\n");

  printf("select which type of word you want to guess:Fruits(1)\nanimal(2)\nmadam or "
         "sir names(3)\n");
  scanf("%d", &n);
/*generates random word according to users choice*/
  if (n == 1)
  {
    const char *words[WORD_COUNT] = {"apple", "banana", "cherry", "orange",
                                     "grapes"};

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random index to select a word
    int randomIndex = rand() % WORD_COUNT;

    // Print the randomly selected word
    selected_word = words[randomIndex];
    word_Lenght = strlen(selected_word);
  }

  else if (n == 2)
  {
    const char *words[WORD_COUNT] = {"lion", "dog", "rabbit", "tiger", "horse"};

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random index to select a word
    int randomIndex = rand() % WORD_COUNT;

    // Print the randomly selected word

    selected_word = words[randomIndex];
    word_Lenght = strlen(selected_word);
  }

  else if (n == 3)
  {
    const char *words[WORD_COUNT] = {"trusha", "rajesh", "ayushi", "mayuri",
                                     "parmanad"};

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random index to select a word
    int randomIndex = rand() % WORD_COUNT;

    // Print the randomly selected word
    selected_word = words[randomIndex];
    word_Lenght = strlen(selected_word);
  }
  int correct_gusees[word_Lenght];//makes integer array
  memset(correct_gusees, 0, sizeof(correct_gusees));//makes integer array with 0

  printf("The word you have to guess has length:- %d\n", word_Lenght);
  display_word(selected_word, word_Lenght, correct_gusees);//display cuurent word
  while (incorrect_guess < no_guess)
  {
    char guess;
    printf("\nguess the letter of the word\n");
    scanf(" %c", &guess);

    if (!check_guees(word_Lenght, selected_word, guess, correct_gusees))//check the user input
    {
      incorrect_guess++;
      printf("\nyou guessed incorrect you left with %d guess\n", no_guess - incorrect_guess);//tells user no. of guesses
    }

    display_word(selected_word, word_Lenght, correct_gusees);
    int all_guessed = 1;
    for (int i = 0; i < word_Lenght; i++)//check word is not gussed then it while loop starts again
    {
      if (!correct_gusees[i])
      {
        all_guessed = 0;

        break;
      }
    }
    if (all_guessed)//check word is gussed then loops break 
    {

      printf("\nCongratulations! You guessed the word correctly and the hang man is saved!!!! \n");
      break;
    }
  }
  if (incorrect_guess >= no_guess)
  {
    printf("oh! you looses the game the man is hanging you have 30 secound save him by playing rock, paper and scissor \n");

    RPS_game();//Strats rock,paper and scissor game for 30 secounds
  }
  printf("\nThe correct word was %s\n", selected_word);//prints the word which shoud be gussed 

  return 0;
}
