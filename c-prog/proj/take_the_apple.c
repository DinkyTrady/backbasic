#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

// define the size of the game MxN
#define SIZE 11

// defining if the key (W, A, S, D) is pressed using bitwise
#define MOVE_UP (1 << 0)
#define MOVE_LEFT (1 << 1)
#define MOVE_DOWN (1 << 2)
#define MOVE_RIGHT (1 << 3)
#define RESTART (1 << 4)

int main() {
  // to made random number
  srand(time(NULL));

  struct termios oldt, newt;
  int scores = 0;
  char input;
  unsigned char inputState = 0;

  /*
   * always randomize position of 
   * the player and fruit when first time play
   */
  int playerX = rand() % SIZE;
  int playerY = rand() % SIZE;
  int fruitY = rand() % SIZE;
  int fruitX = rand() % SIZE;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  while (1) {
    inputState = 0;
    // Clear the terminal buffers
    // UNIX
    system("clear");

    // Windows uncomment this
    // system("cls");

    /*
     * Drawing the MxN for the games
     * Drawing the player position
     * Drawing the food position
     *
     * Using loop with defined size of MxN
     * SIZE so we can change the MxN like what we want
     * WARNING: REMEMBER, THAT ROWS ARE Y AND COLS ARE Y IN PROGRAMMING
     */
    for (int row = 0; row < SIZE; row++) {
      for (int col = 0; col < SIZE; col++) {
        if (row == playerY && col == playerX) printf(" ");
        else if (row == fruitY && col == fruitX) printf(" ");
        else printf(". ");
      }
      printf("\n");
    }

    printf("Posisi: (%d, %d)\nScore: (%d)\n", playerX, playerY, scores);
    printf("WASD untuk bergerak (q untuk exit dan r untuk reset): " );
    
    input = getchar();

    // exit the game if input `q`
    if (input == 'q') break;

    /*
     *  Doing the bitwise operations
     *  with AND `&` to check if the key pressed
     *  and activate the checking so we know the user input
     */
    if (input == 'd') inputState |= MOVE_RIGHT;
    if (input == 'a') inputState |= MOVE_LEFT;
    if (input == 'w') inputState |= MOVE_UP;
    if (input == 's') inputState |= MOVE_DOWN;

    if (input == 'r') inputState |= RESTART;

    /*
     * Doing the movement for user
     * with a bitwise operations and logical operations
     * checking the size of the `x` and `y`
     */
    if (inputState & MOVE_UP && playerY > 0) playerY--;
    if (inputState & MOVE_LEFT && playerX > 0) playerX--;
    if (inputState & MOVE_DOWN && playerY < SIZE - 1) playerY++;
    if (inputState & MOVE_RIGHT && playerX < SIZE - 1) playerX++;

    if (inputState & RESTART) scores = 0;

    // get the new position of the food and increases scores
    if (playerX == fruitX && playerY == fruitY) {
      do {
        fruitX = rand() % SIZE;
        fruitY = rand() % SIZE;
      } while (playerX == fruitX && playerY == fruitY);

      scores++;
    }

  }

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return 0;
}
