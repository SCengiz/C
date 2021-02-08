#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SZ 10

struct Container_{
  int item;
  char c_str[SZ];
  struct Container_* next;
  
}; // struct

typedef struct Container_ Container;

void basic_test()
{
  printf("\n *** BASIC_TEST *** \n");
  
  Container *first, *second, *third;
  
  first = malloc(sizeof(Container));
  second = malloc(sizeof(Container));
  third = malloc(sizeof(Container));

  first->item = 1;
  strcpy(first->c_str, "one");
  first->next = second;
  
  second->item = 2;
  strcpy(second->c_str, "two");
  second->next = third;

  third->item = 3;
  strcpy(third->c_str, "three");
  third->next = NULL;
  
  printf("first->next->item  : %d \n"
         "first->next->c_str : %s \n", 
          first->next->item , first->next->c_str);

} // func

void better_test()
{
  printf("\n *** BETTER_TEST *** \n");

  typedef Container* intArray;  
  intArray arr[SZ];
  
//   Allocation
  int kk = 0;
  for(; kk < SZ ; ++kk)
  {
    arr[kk] = malloc(sizeof(Container));
    arr[kk]->item  = kk+1;
    strcpy(arr[kk]->c_str, "none");
  } 
  
  for(kk = 0; kk < SZ - 1; ++kk)
    arr[kk]->next = arr[kk+1];
  arr[SZ-1]->next = NULL;
  
//   NOTE: index != str meaning
  strcpy(arr[2]->c_str, "three"); 
  strcpy(arr[4]->c_str, "five"); 

  printf(" ---FIRST METHOD FOR OUTPUT--- \n");
//   NOTE: Carefull for maximum index.
  for(kk = 0; kk < SZ-1; ++kk)
  {
    printf("%d : ", kk+1);
    printf("  item : %d  ->", arr[kk]->item);
    printf("  next item : %3d  ->", arr[kk]->next->item);
    printf("  next c_str : %s \n",  arr[kk]->next->c_str);
  }

//   Second method for output.
  intArray copy_Container;
  copy_Container = arr[0];
  copy_Container->item = copy_Container->item * 10; 

  strcpy(arr[1]->c_str, "two"); 
  strcpy(arr[8]->c_str, "nine"); 
  
  printf(" ---SECOND METHOD FOR OUTPUT--- \n");
  
  for(kk = 0; kk < SZ-1; ++kk)
  {
    copy_Container->next->item = copy_Container->next->item * 10;
    
    printf("%d : ", kk+1);
    printf("  item : %d  ->", copy_Container->item);
    printf("  next item : %4d\n", copy_Container->next->item);
//     printf("  next c_str : %s \n",  copy_Container->next->c_str);
    
    copy_Container = copy_Container->next;
  }
  
//   Deallocation
  for(kk = 0; kk < SZ ; ++kk)
    free(arr[kk]);
  
} // func

int main()
{
  
  basic_test();
  better_test();
  
  return 0;
}
