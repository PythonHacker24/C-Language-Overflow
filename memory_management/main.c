#include <stdio.h>
#include <stdlib.h>

// returns the size of the array
int int_array_len(int* array) {
  return sizeof(array) / sizeof(array[0]);
}

// this functions output the data in the memory location with the memory address
void print_array(int* array) {
  int array_bound = int_array_len(array);
  for (int i = 0; i < array_bound; i++) {
    printf("%p: %d\n", &array[i], array[i]);
  }
}

int main() {

  // pointing an integer pointer name dyanmicArray which would pointing
  // to the heap memory allocated by malloc()
  //
  // malloc() does not initiated the memory location and contains garbage
  // values
  int* mallocArray = (int*)malloc(sizeof(int) * 12);

  // calloc() initiates the allocated memory locations with 0
  int* callocArray = (int*)calloc(12, sizeof(int));

  
  for(int i = 0; i < int_array_len(mallocArray); i++) {
    mallocArray[i] = i * 2;
  }

  for(int i = 0; i < int_array_len(callocArray); i++) {
    callocArray[i] = i * 2;
  }
  
  // realloc is used to reallocate memory locations and can be used to 
  // resize the array
  int* init_array = (int*)malloc(sizeof(int) * 12);
  for (int i = 0; i < int_array_len(init_array); i++) {
    init_array[i] = i * 2;
  }

  printf("printing array before realloc: \n");
  print_array(init_array);
  printf("\n");

  int* updated_array = (int*)realloc(init_array, sizeof(int) * 24);
  for (int i = 0; i < int_array_len(updated_array); i++) {
    updated_array[i] = i * 2;
  }

  printf("\nprinting array after realloc: \n");
  print_array(updated_array);

  printf("\n");
  print_array(mallocArray);
  printf("\n");
  print_array(callocArray);
  
  // free the memory locations of the allocated memory in the heap
  free(mallocArray);
  // setting the pointer to NULL to ensure clearing the allocated memory
  // location initiated
  mallocArray = NULL;

  free(callocArray);
  callocArray = NULL;

  return 0;
}
