#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// defining a struct
struct Person {
  int age;
  char* name;
};

// another way of defining a struct 
typedef struct {
  int age;
  char* name;
} Hero;

int main(void) {
  // declaring a new struct 
  struct Person em;
  
  // declaring typedef struct 
  Hero ap;

  // set data to the struct 
  em.age = 30;
  em.name = malloc(6 * sizeof(char));
  strcpy(em.name, "Steve");

  ap.age = 30;
  ap.name = malloc(10 * sizeof(char));
  strcpy(ap.name, "captain");

  printf("age: %d\nname: %s\n\n", em.age, em.name);
  printf("age: %d\nname: %s\n\n", ap.age, ap.name);

  // creating a pointer to the stuct 
  struct Person *em_ptr = &em;

  // creating a pointer to the typedef struct 
  Hero *ap_ptr = &ap;

  // set data to the struct via pointers 
  (*em_ptr).age = 40;
  (*em_ptr).name = realloc((*em_ptr).name, 7 * sizeof(char));
  strcpy((*em_ptr).name, "Tony");
  
  (*ap_ptr).age = 40;
  (*ap_ptr).name = realloc((*ap_ptr).name, 20 * sizeof(char));
  strcpy((*ap_ptr).name, "Iron man");

  printf("age: %d\nname: %s\n\n", (*em_ptr).age, (*em_ptr).name);
  printf("age: %d\nname: %s\n\n", (*ap_ptr).age, (*ap_ptr).name);

  // setting some data again, but with better syntac for struct pointers 
  em_ptr->age = 50;
  em_ptr->name = realloc(em_ptr->name, 8 * sizeof(char));
  strcpy(em_ptr->name, "Thor");

  ap_ptr->age = 50;
  ap_ptr->name = realloc(ap_ptr->name, 20 * sizeof(char));
  strcpy(ap_ptr->name, "Almighty Thor");

  printf("age: %d\nname: %s\n\n", em_ptr->age, em_ptr->name);
  printf("age: %d\nname: %s\n\n", ap_ptr->age, ap_ptr->name);

  free(em_ptr->name);
  free(ap_ptr->name);
}
