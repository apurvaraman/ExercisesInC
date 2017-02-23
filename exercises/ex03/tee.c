/* Exercise 3: Implementing the unix tee command
Apurva Raman
SoftSys spring 2017

Outputs user input from stdin to stdout and to a given file.
Can append to an existing file with the -a argument

*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char ch;
  char *mode;
  int i;
  while ((ch = getopt(argc, argv, "a")) != EOF) {
    switch (ch) {
    // append mode
    case 'a':
      mode = "a";
      break;

    default:
      fprintf(stderr, "Error: Option not supported '%s'", optarg);
      return 1;
    }
  }

  int c;

  argc -= optind;
  argv += optind;

  FILE *files[argc];

  // Open files
  for (i = 0; i < argc; i++) {
    files[i] = fopen(argv[i], mode);
  }

  // Echoes input
  while ((c = getchar()) != EOF) {
    putchar(c);

    // Writes to file
    if (mode == "a") {
      for (i = 0; i < argc; i++) {
        fputc(c, files[i]);
      }
    }
  }

  // close files
  for (i = 0; i < argc; i++) {
    fclose(files[i]);
  }
}

/*
3) Reflect: what worked, what slowed you down?  What would you do
differently next time?

I had some issues with figuring out whether to get things by line or character,
and also took some time figuring out a few syntax errors that took me a while to
track down.

4) Compare your solution to the real thing.  What do you see in
professional code that is not in your solution?

There is a lot more error handling and support of various flags that I did not
include.



*/
