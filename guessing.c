#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n\n");
    printf("                        .                                   \n");
    printf("                .                                           \n");
    printf("                         .                                  \n");
    printf("               /^\\     .                                   \n");
    printf("          /\\    V                  WELCOME TO              \n");
    printf("         /__\\   I      O  o        MY GUESSING GAME        \n");
    printf("        //..\\  I     .                                     \n");
    printf("        \\].`[/  I                                          \n");
    printf("        /l\\/j\\  (]    .  O                                \n");
    printf("       /. ~~ ,\\/I          .                               \n");
    printf("       \\L__j^\\/I       o                                  \n");
    printf("        \\/--v}  I     o   .                                \n");
    printf("        |    |  I   _________                               \n");
    printf("        |    |  I c(`       ')o                             \n");
    printf("        |    l  I   \\.     ,/                              \n");
    printf("      _/j  L l\\_!  _//^---^\\_                             \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");

    int guess;
    int win = 0;
    int attempts = 1;
    double points = 1000;

    srand(time(0));                   // Seed the random number generator with the current time
    int secret_number = rand() % 100; // Generate a random number between 0 and 99

    int difficulty;
    printf("Choose a difficulty level:\n");
    printf("1 - Easy (20 attempts)\n");
    printf("2 - Medium (15 attempts)\n");
    printf("3 - Hard (6 attempts)\n");
    printf("Enter the difficulty level: ");
    scanf("%d", &difficulty);

    int max_attempts;
    switch (difficulty)
    {
    case 1:
        max_attempts = 20;
        break;
    case 2:
        max_attempts = 15;
        break;
    case 3:
        max_attempts = 6;
        break;
    default:
        printf("Invalid difficulty level!\n");
        return 1; // Exit the program with an error code
    }

    for (int i = 1; i <= max_attempts; i++)
    {
        printf("Attempt %d of %d\n", i, max_attempts);

        printf("Enter your guess no. %d (0-99): ", attempts);
        scanf("%d", &guess);

        if (guess < 0)
        {
            printf("You entered a negative number, please try again!\n");
            continue;
        }

        printf("Your guess no. %d is %d\n", attempts, guess);

        win = guess == secret_number;
        int higher = guess > secret_number;

        if (win)
        {
            break;
        }
        else if (higher)
        {
            printf("Your guess was higher than the secret number!\n");
        }
        else
        {
            printf("Your guess was lower than the secret number!\n");
        }

        attempts++;

        double lost_points = abs(guess - secret_number) / 2.0;
        points = points - lost_points;
    }

    printf("End of game!\n");

    if (win)
    {
        printf("\n\n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Nice, you guessed the right number!\n");
        printf("You guessed the number in %d attempts!\n", attempts);
        printf("Your total score is %.2f points!\n", points);
        printf("Play again, you won't be that lucky the next time!\n\n");
    }
    else
    {
        printf("\n\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("\n\n");
        printf("Sorry, you lost!\n");
        printf("The secret number was %d\n", secret_number);
        printf("Better luck next time!\n");
    }
}
