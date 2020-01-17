#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// print out three arguments
void print(size_t ms, char* s, char* c) {
  printf("%zu\n", ms);
  printf("%s\n", s);
  printf("%s\n", c);
}

int main(int argh, char** argv) {

  // set variables to default values if not specified
  int num = 0;
  bool numSet = false;
  char* string = (char*)"";
  bool stringSet = false;
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
      if (stringSet) {
        printf("Cannot reset -f flag\n");
        return -1;
      }
      i++;
      string = argv[i];
      stringSet = true;
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

  print(num, string, comment);
  return 0;
}
