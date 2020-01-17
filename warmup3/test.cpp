#include <stdlib.h>
#include <stdio.h>
#include "sorted.h"

void test1() {
  printf("\nTEST 1 STARTING\n");
  const char* text = "This young gentlewoman had a father--O, that \"had,\" how sad a passage 'tis!--whose skill young";
  SortedStrList * l = new SortedStrList();
  l->count_words(text);
  l->clear_created_words();
  printf("TEST 1 PASSED\n");
}

void test2() {
  printf("\nTEST 2 STARTING\n");

  FILE *f = fopen("doc.txt", "rb");
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
    printf("TEST 2 PASSED\n");
  } else {
    printf("TEST 2 FAILED\n");
    exit(-1);
  }
}

// hello 100 world 100
void test3() {
  printf("\nTEST 3 STARTING\n");

  FILE *f = fopen("helloworld.txt", "rb");
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
    printf("TEST 3 PASSED\n\n");
  } else {
    printf("TEST 3 FAILED\n\n");
    exit(-1);
  }
}

int main() {
  test1();
  test2();
  test3();
  exit(0);
}