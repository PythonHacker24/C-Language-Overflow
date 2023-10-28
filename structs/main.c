#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// defining a struct
struct Person {
  int age;
  char* name;
};

int main(void) {
  // declaring a new struct 
  struct Person em;

  // set data to the struct 
  em.age = 30;
  em.name = malloc(6 * sizeof(char));
  strcpy(em.name, "Steve");

  printf("age: %d\nname: %s\n\n", em.age, em.name);

  // creating a pointer to the stuct 
  struct Person *em_ptr = &em;

  // set data to the struct via pointers 
  (*em_ptr).age = 40;
  (*em_ptr).name = realloc((*em_ptr).name, 7 * sizeof(char));
  strcpy((*em_ptr).name, "Tony");

  printf("age: %d\nname: %s\n\n", (*em_ptr).age, (*em_ptr).name);

  // setting some data again, but with better syntac for struct pointers 
  em_ptr->age = 50;
  em_ptr->name = realloc(em_ptr->name, 8 * sizeof(char));
  strcpy(em_ptr->name, "Thor");

  printf("age: %d\nname: %s\n", em_ptr->age, em_ptr->name);
}