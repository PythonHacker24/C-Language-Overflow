#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declaring the stack frame
	char buf2[16] = "overwriteme";
  char buf1[16];

	// using strcpy 
	strcpy(buf1, "AAAAAAAAAAAAAAAA");
	
	// printing the information
	printf("buf1 val: %s\n", buf1);
	printf("buf2 val: %s\n", buf2);
	printf("buf1 addr: %p\n", (void *)buf1);
	printf("buf2 addr: %p\n", (void *)buf2);

  printf("\n----------------------------\n\n");
  // heap corruption
  char *buf3 = malloc(12 * sizeof(char));
  char *buf4 = malloc(12 * sizeof(char));

  strcpy(buf4, "mywordshere");
  strcpy(buf3, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

  printf("buf3: %s\n", buf3);
  printf("buf4: %s\n", buf4);
  printf("buf3 addr: %p\n", (void *)buf3);
  printf("buf4 addr: %p\n", (void *)buf4);

}
