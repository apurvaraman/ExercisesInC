/* Code for Exercise 1 in Head First C for Softsys Spring 2017.
Apurva Raman
*/

#include <stdio.h>
#include <stdlib.h>

/*
input: Takes in a char array as a buffer and gets the user input for the card
name and puts it in the array.

inputs
card_name: char array for storing card names

return: none
*/
void input(char *input_array) {
  puts("Enter the card name: ");
  scanf("%2s", input_array);
}

/*
getVal: Takes in a card name and gets the corresponding card value.

inputs
card_name: current card name

return: card value
*/
int getVal(char *card_name) {

  int val = 0;

  switch (card_name[0]) {
  case 'K':
  case 'Q':
  case 'J':
    val = 10;
    break;
  case 'A':
    val = 11;
    break;
  case 'X':
    val = -1;
    break;
  default:
    val = atoi(card_name);
    if ((val < 1) || (val > 10)) {
      puts("I don't understand that value!");
      val = -1;
      break;
    }
  }
  return val;
}

/*
cardCount: Takes in a count and card value and updates the count based on the
card value.

inputs
count: current card count
val: current card value

return: updated card count
*/
int cardCount(int count, int val) {
  if ((val > 2) && (val < 7)) {
    count++;
  } else if (val == 10) {
    count--;
  }
  return count;
}
/*
main: Prompts user for card value until the user enters X.

inputs
none

return: exit code
*/
int main() {
  char card_name[3];
  int count = 0;
  int val = 0;

  while (card_name[0] != 'X') {
    input(card_name);
    val = getVal(card_name);
    if (val == -1) { /* doesn't print card count invalid val */
      continue;
    }

    count = cardCount(count, val);
    printf("Current count: %i\n", count);
  }

  return 0;
}
