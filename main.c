#include <math.h>
#include <stdatomic.h>
#include <stdio.h>
#include <threads.h>

struct players {
  char player_name[16];
  char player_symbol;
} player1, player2;

void define_players() {
  printf("Enter the player1's name: ");
  scanf("%s\n", player1.player_name);
  printf("enter player1's symbol(x or o): ");
  scanf("%c\n", &player1.player_symbol);
  if (player1.player_symbol == 'x') {
    player2.player_symbol = 'o';
  } else {
    player2.player_symbol = 'x';
  }
  printf("Enter the player2's name: ");
  scanf("%s\n", player2.player_name);
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
      symbol = tableArray[i][0];
      if (check == 0)
        check++;
      break;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (tableArray[0][i] == tableArray[1][i] == tableArray[2][i]) {
      symbol = tableArray[i][0];
      if (check == 0)
        check++;
      break;
    }
  }
  if (tableArray[0][0] == tableArray[1][1] == tableArray[2][2] ||
      tableArray[2][0] == tableArray[1][1] == tableArray[0][2]) {
    symbol = tableArray[1][1];
    if (check == 0)
      check++;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tableArray[i][j] != 'x' && tableArray[i][j] != 'o') {
        continue;
      }
      if (check == 0) {
        check++;
        break;
      }
    }
  }

  if (check == 1 && symbol == player1.player_symbol) {
    printf("game_over and the winner is %s", player1.player_name);
    return 1;
  } else if (check == 1 && symbol == player2.player_symbol) {
    printf("game_over and the winner is %s", player2.player_name);
    return 1;
  } else {
    return 0;
  }
}

void play_tictactoe(int tableArray[3][3], char current_symbol) {
  int position;
  printf("enter the position of %c: ", current_symbol);
  scanf("%d", &position);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tableArray[i][j] == position) {
        tableArray[i][j] = current_symbol;
      }
    }
  }
}

int main() {
  int tableArray[3][3] = {1, 2, 3, 4, 5, 6, 6, 7, 8};
  int current_symbol = 'x';
  define_players();
  display_tictactoe(tableArray);
  return 0;
  while (!game_over(tableArray)) {
    display_tictactoe(tableArray);
    current_symbol = current_symbol == 'o' ? 'x' : 'o';
    play_tictactoe(tableArray, current_symbol);
  }
  return 0;
}
