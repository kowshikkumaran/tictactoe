#include <stdio.h>

struct players {
  char player_name[16];
  char player_symbol;
} playerX, playerO;

void define_players() {
  playerX.player_symbol = 'x';
  playerO.player_symbol = 'o';
  printf("Enter the X player's name: ");
  scanf("%s", playerX.player_name);
  printf("Enter the O player's name: ");
  scanf("%s", playerO.player_name);
}

void display_tictactoe(int tableArray[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tableArray[i][j] != 'x' && tableArray[i][j] != 'o') {
        printf("%d ", tableArray[i][j]);
      } else {
        printf("%c ", tableArray[i][j]);
      }
    }
    printf("\n");
  }
}

int game_over(int tableArray[3][3]) {
  char symbol;
  int check = 0;
  for (int i = 0; i < 3; i++) {
    if (tableArray[i][0] == tableArray[i][1] == tableArray[i][2]) {
      if (check == 0) {
        symbol = tableArray[i][0];
        check++;
        break;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (tableArray[0][i] == tableArray[1][i] == tableArray[2][i]) {
      if (check == 0) {
        symbol = tableArray[i][0];
        check++;
        break;
      }
    }
  }
  if (tableArray[0][0] == tableArray[1][1] == tableArray[2][2] ||
      tableArray[2][0] == tableArray[1][1] == tableArray[0][2]) {
    if (check == 0) {
      symbol = tableArray[1][1];
      check++;
    }
  }

  if (check == 1 && symbol == playerX.player_symbol) {
    printf("game_over and the winner is %s", playerX.player_name);
    return 1;
  }
  if (check == 1 && symbol == playerO.player_symbol) {
    printf("game_over and the winner is %s", playerO.player_name);
    return 1;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tableArray[i][j] != 'x' && tableArray[i][j] != 'o') {
        return 0;
      }
    }
  }
  printf("nt! Match Tie :D");
  return 1;
}

void play_tictactoe(int tableArray[3][3], char current_symbol) {
  int position;
  printf("enter the position of %c: ", current_symbol);
  scanf("%d", &position);
  if (position < 1 || position > 9) {
    printf("Enter the valid position\n");
    play_tictactoe(tableArray, current_symbol);
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tableArray[i][j] != 'x' && tableArray[i][j] != 'o') {
        if (tableArray[i][j] == position) {
          tableArray[i][j] = current_symbol;
          return;
        }
      }
    }
  }
  printf("Oops! its already taken like the girl you have crush on\n");
  play_tictactoe(tableArray, current_symbol);
}
void play_game(int tableArray[3][3], char current_symbol) {
  while (!game_over(tableArray)) {
    display_tictactoe(tableArray);
    current_symbol = current_symbol == 'o' ? 'x' : 'o';
    play_tictactoe(tableArray, current_symbol);
  }
  printf("Wanna play one more(y or n): ");
  char checker = 'n';
  scanf("%c", &checker);
  if (checker)
    play_game(tableArray, current_symbol);
  else {
    printf("until then :D");
    return;
  }
}
int main() {
  int tableArray[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int current_symbol = 'x';
  define_players();
  play_game(tableArray, current_symbol);
  return 0;
}
