#include <stdatomic.h>
#include <stdio.h>

void define_players() {
  char player1_symbol, player2_symbol;
  printf("enter player1's symbol(x or o): ");
  scanf("%c", &player1_symbol);
  if (player1_symbol == 'x') {
    player2_symbol = 'o';
  } else {
    player2_symbol = 'x';
  }
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

int main() {
  int tableArray[3][3] = {1, 2, 3, 4, 5, 6, 6, 7, 8};
  define_players();
  display_tictactoe(tableArray);
  return 0;
}
