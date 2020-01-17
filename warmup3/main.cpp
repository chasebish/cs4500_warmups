#include <stdlib.h>
#include <stdio.h>
#include "sorted.h"

int main(int argh, char** argv) {

  // set variables to default values if not specified
  int num = 0;
  bool numSet = false;
  char* file = (char*)"";
  bool fileSet = false;
  char* comment = (char*)"";
  bool commentSet = false;

  // loop through arguments
  for (int i = 1; i < argh; i++) {
    char* arg = argv[i];

    // -i flag must be valid positive integer
    if (strcmp(arg, "-i") == 0) {
      if (numSet) {
        printf("Cannot reset -i flag\n");
        return -1;
      }
      i++;
      num = atoi(argv[i]);
      numSet = true;
      continue;
    }

    // -f flag can be any string
    if (strcmp(arg, "-f") == 0) {
      if (fileSet) {
        printf("Cannot reset -f flag\n");
        return -1;
      }
      i++;
      file = argv[i];
      fileSet = true;
      continue;
    }

    // if no flag given, set new comment
    if (!commentSet) {
      comment = arg;
      commentSet = true;
    } else {
      printf("Cannot have more than one comment\n");
      return -1;
    }
  }
  
  // error if given -i flag is not positive
  if (numSet && num <= 0) {
    printf("-i flag must have a valid positive integer value\n");
    return -1;
  }

  if (strcmp(file, "") == 0) {
    printf("No file given.\n");
    exit(-1);
  }

  // file reading inspired from stack overflow
  FILE *f = fopen(file, "rb");
  if (f) {
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *fileString = new char[fsize + 1];
    fread(fileString, 1, fsize, f);
    fclose(f);

    fileString[fsize] = '\0';

    SortedStrList * l = new SortedStrList();
    l->count_words(fileString);
    l->clear_created_words();
  } else {
    printf("File not found.\n");
    exit(-1);
  }

  return 0;
}