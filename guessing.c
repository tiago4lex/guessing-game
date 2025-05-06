#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("********************************\n");
    printf("* Welcome to my guessing game! *\n");
    printf("********************************\n");

    int guess;
    int win = 0;
    int attempts = 1;
    double points = 1000;

    srand(time(0));                   // Seed the random number generator with the current time
    int secret_number = rand() % 100; // Generate a random number between 0 and 99

    while (!win)
    {

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
            printf("Nice, you guessed the right number!\n");
            printf("Play again, you won't be that lucky the next time!\n");
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
    printf("You guessed the number in %d attempts!\n", attempts);
    printf("Your total score is %.1f points!\n", points);
}
