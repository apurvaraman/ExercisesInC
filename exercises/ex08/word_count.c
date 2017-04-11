/* Program that reads a text file,
splits lines into words, and counts the frequency of each word using glib.

Apurva Raman, written for SoftSys Spring 2017.
*/

// #include <ctype.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*
Parses the data from the file and puts it into a GHashTable.

Takes in a string filepath and a pointer to a hashtable. Modifies the hashtable.
Returns: Nothing
*/
void parser (char* filepath, GHashTable* hash){
  FILE* fp;
  char word[1000];
  int i;

  fp = fopen(filepath, "r");

  if (access(filepath, F_OK) != 0){
    fprintf(stderr, "File does not exist.\n");
    exit(1);
  }

  if (fp == NULL){
    fprintf(stderr, "Couldn't open file.\n");
    exit(1);
  }

  while (fscanf(fp, "%s", word) != EOF) {
    i = GPOINTER_TO_INT(g_hash_table_lookup(hash,word));
    g_hash_table_insert(hash, strdup(word), GINT_TO_POINTER(i+1));
  }

  fclose(fp);

}

/*
GHFunc frequency iterator. Prints the frequency (data) for the given
key-value pair.
*/
void frequency_ghfunc (gpointer key, gpointer value, gpointer data) {
  printf("frequency of %s = %d\n", key, GPOINTER_TO_INT(value));
}


/*
Creates a hashtable and calls the parser with the first commandline arg and hash
table. Iterates through the hashtable and calls frequency_ghfunc for each
key-value pair.
*/
int main (int argc, char** argv) {
  GHashTable* hash;

  // if (argv != NULL){
  if (argc < 2) {
    fprintf(stderr, "Input a filename.\n");
    return 1;
  }

  hash = g_hash_table_new(g_str_hash, g_str_equal);
  parser(argv[1], hash);
  g_hash_table_foreach(hash, (GHFunc)frequency_ghfunc, NULL);
}
