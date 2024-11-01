#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// NOTE: Declare the Go function (ensure it matches the signature)
extern void GoProgressBar(float number);

int updateBalance(int result, int *game, int *balance) {
  // result 1 = failure
  // result 0 = success
  if (result) {
    *balance -= 1;
  } else {
    *balance += 1;
  }

  printf("Current balance : %d\n", *balance);

  if (*balance > 5) {
    // win
    printf("You won !");
    return *game = 0;
  } else if (*balance < -5) {
    // lose
    printf("You lost !");
    return *game = 0;
  }

  return 0;
}

int checkUserAnswer(int result) {

  int userAnswer;

  printf("Your guess : \n");

  // Get and save the number the user types
  scanf("%d", &userAnswer);

  if (userAnswer != result) {
    printf("Wrong answer ! : %d\n", result);
    return 1;
  } else {
    printf("Correct ! : %d\n", result);
    return 0;
  }
  return 1;
}

int randomNumber(int min, int max) {

  int value = rand() % (max - min + 1) + min;

  return value;
}

int multiplication() {

  int x = randomNumber(2, 20);
  int y = randomNumber(2, 20);

  int result = x * y;

  printf("CHEAT result: %d\n", result);

  printf("%d * %d = ?\n", x, y);

  if (checkUserAnswer(result) == 1) {
    return 1;
  }

  return 0;
}

// NOTE: Define the goProgressBar function to call the Go function
int goProgressBar(float number) {
  // Call the Go function
  GoProgressBar(number);
  return 0;
}

int main() {
  // test
  goProgressBar(10.0);

  srand(time(NULL));

  int game = 1;

  // Balance : 0 middle ; -6 = lose ; 6 = win
  int balance = 0;

  while (game == 1) {
    int result = multiplication();
    updateBalance(result, &game, &balance);
  }

  return 1;
}
