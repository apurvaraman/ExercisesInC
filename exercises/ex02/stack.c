/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
  int i;
  int array[SIZE];

  // printf("%p\n", array);

  for (i = 0; i < SIZE; i++) {
    array[i] = 42;
  }
  return array;
}

void bar() {
  int i;
  int array[SIZE];

  // printf("%p\n", array);

  for (i = 0; i < SIZE; i++) {
    array[i] = i;
  }
}

int main() {
  int i;
  int *array = foo();
  bar();

  for (i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}

/*
1. This program should an array of length 5 filled with 42s and iterate and set
the values to the index i, then print the values. The output should be addresses
for the foo and bar array and then the numbers 0-4.

2. When compiling, this is the warning:
stack.c: In function ‘foo’:
stack.c:22:3: warning: function returns address of local variable
[-Wreturn-local-addr]
return array;
^
This means that foo returns the address in memory of the array, not the array
itself. This is giving a warning because the array is created in foo.

3. The program prints the addresses for the array and the numbers 0-4, as
expected.

4. We now get this output:
0
0
65961600
32715
66049376

This is because the data in the stack got overwritten and allocated to something
else since it wasn't necessary to keep for the print statement.


*/
