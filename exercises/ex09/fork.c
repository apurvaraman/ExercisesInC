/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

// errno is an external global variable that contains
// error information
extern int errno;

static int static_check = 30;
// has to be global to be stored in data(static) segment

// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
  struct timeval tv[1];

  gettimeofday(tv, NULL);
  return tv->tv_sec + tv->tv_usec / 1e6;
}

void child_code(int i) {
  sleep(i);

  int *heap_check = malloc(sizeof(int)); // malloc allocates to the heap
  // static int static_check = 30;
  // int stack_check = 42;
  // checking for curiosity -> All children share same stack memory location
  printf("Hello from child %d.\n", i);
  printf("Child %d: heap segment at pointer address %p, static segment at "
         "pointer address %p \n",
         i, heap_check, &static_check);
  exit(i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[]) {
  int status;
  pid_t pid;
  double start, stop;
  int i, num_children;

  // the first command-line argument is the name of the executable.
  // if there is a second, it is the number of children to create.
  if (argc == 2) {
    num_children = atoi(argv[1]);
  } else {
    num_children = 1;
  }

  // get the start time
  start = get_seconds();

  for (i = 0; i < num_children; i++) {

    // create a child process
    printf("Creating child %d.\n", i);
    pid = fork();

    /* check for an error */
    if (pid == -1) {
      fprintf(stderr, "fork failed: %s\n", strerror(errno));
      perror(argv[0]);
      exit(1);
    }

    /* see if we're the parent or the child */
    if (pid == 0) {
      child_code(i);
    }
  }

  /* parent continues */

  int *heap_check = malloc(sizeof(int)); // malloc allocates to the heap

  // int stack_check = 42; //checking for curiosity
  printf("Hello from the parent.\n");
  printf(
      "Parent: heap segment at pointer address %p, static segment at pointer "
      "address %p \n",
      heap_check, &static_check);

  for (i = 0; i < num_children; i++) {
    pid = wait(&status);

    if (pid == -1) {
      fprintf(stderr, "wait failed: %s\n", strerror(errno));
      perror(argv[0]);
      exit(1);
    }

    // check the exit status of the child
    status = WEXITSTATUS(status);
    printf("Child %d exited with error code %d.\n", pid, status);
  }
  // compute the elapsed time
  stop = get_seconds();
  printf("Elapsed time = %f seconds.\n", stop - start);

  exit(0);
}

/*

1.
Output for ./fork 1 :
Creating child 0.
Hello from the parent.
Hello from child 0.
Child 4303 exited with error code 0.

Output for ./fork 3 :
Creating child 0.
Creating child 1.
Creating child 2.
Hello from child 0.
Hello from the parent.
Child 4310 exited with error code 0.
Hello from child 1.
Child 4311 exited with error code 1.
Hello from child 2.
Child 4312 exited with error code 2.
Elapsed time = 2.000998 seconds.

The argument is the number of child processes launched.
First, the first child process is created.
The parent process runs its code first.
It then waits, so each child can run its code, one child at a time.
When each child is done, the PID and status of the child are displayed.
The elapsed time is displayed last. ./fork 3 takes longer because the parent has
to wait for all the child processes to be complete before exiting.


2.
Output for ./fork 2 :
Creating child 0.
Creating child 1.
Hello from the parent.
Parent: heap segment at pointer address 0x1fec010, static segment at pointer
address 0x6020a0
Hello from child 0.
Child 0: heap segment at pointer address 0x1fec010, static segment at pointer
address 0x6020a0
Child 5528 exited with error code 0.
Hello from child 1.
Child 1: heap segment at pointer address 0x1fec010, static segment at pointer
address 0x6020a0
Child 5529 exited with error code 1.
Elapsed time = 1.000910 seconds.

This demonstrates that the static (data) segment and heap segment are shared by
the parent and child. This makes sense because the forking for child processes
copies the parent completely.

*/
