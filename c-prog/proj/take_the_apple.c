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

int main() {
  // to made random number
  srand(time(NULL));

  struct termios oldt, newt;
  int scores = 0;
  int x = 5;
  int y = 5;
  char input;
  unsigned char inputState = 0;

  // always randomize position of the food
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
        if (row == y && col == x) printf(" ");
        else if (row == fruitY && col == fruitX) printf(" ");
        else printf(". ");
      }
      printf("\n");
    }

    printf("Posisi: (%d, %d)\nScore: (%d)\n", x, y, scores);
    printf("WASD untuk bergerak (q untuk exit): " );
    
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

    /*
     * Doing the movement for user
     * with a bitwise operations and logical operations
     * checking the size of the `x` and `y`
     */
    if (inputState & MOVE_UP && y > 0) y--;
    if (inputState & MOVE_LEFT && x > 0) x--;
    if (inputState & MOVE_DOWN && y < SIZE - 1) y++;
    if (inputState & MOVE_RIGHT && x < SIZE - 1) x++;

    // get the new position of the food and increases scores
    if (x == fruitX && y == fruitY) {
      fruitX = rand() % SIZE;
      fruitY = rand() % SIZE;

      scores++;
    }

  }

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return 0;
}
