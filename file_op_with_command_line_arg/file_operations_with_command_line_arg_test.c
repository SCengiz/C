/*
  C File operations with command line argument.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

// A basic struct definition for our items.
typedef struct Container_{
  int num_;
  int *arr_;  
  
} Container;

// Cumulative summation for our arrays variables.
int* cumulative_sum(int num, int* in_arr)
{
  int i = 0, val = 0;
// We need a dynamic array for return value.
  int* arr = calloc(num, sizeof(int));  
// Iteratively we calculate cum_sum.
  for(; i < num; ++i)
  {
    arr[i] = val +  in_arr[i];
    val = arr[i];
  }
  
  return arr;
} // cumulative_sum

// Update array with random numbers.
void update_array(Container* c)
{
//NOTE: Sets the seed based on the current time.
  srand(time(NULL));
  int i = 0 ;
  float rand_num;
// Generate random numbers 0 to 1.
// And update like times 10 etc. Don't forget c type cast.  
  for(; i < c->num_ ; i++) 
  {  
    rand_num = rand();
    rand_num = (int)((rand_num/RAND_MAX) * 10) % 3;
    c->arr_[i] = rand_num;    
  }
  
} // update_array

void create_empty_array(Container* c)
{
  int num = c->num_;
  int i = 0;

//   Using calloc for stack.
  c->arr_ = calloc(num, sizeof(int));
// Empty array allocation.  
  for(; i < num; i++)
    c->arr_[i] = 0;
    
}  // create_empty_array

void write_test(Container* obj)
{
// If directory is not created then create it.
  system("echo Check Directory !!!");

// Variables for our directory and file name.
  char in_command[20] = "mkdir -p " ;
  char dir_name[20]   = "c_dir";  
  char *file_name     = "c_file.txt";
  char path_name[50];

// Char concatination with sprintf and strcat.
  sprintf(path_name, "%s/%s", dir_name, file_name);
  strcat(in_command, dir_name);
  system(in_command);

// File pointer we do some operations with this.
  FILE *w_file;
// Open the file. "w" mode means writing.
  w_file = fopen(path_name, "w");
  
// Control for file.
  if(!w_file) 
  {
    puts(" File cannot be opened !!");  
    exit(1);
  }
  
// Write to the file using fprintf.
  fprintf(w_file, "\n << New Test Data >>%20s", "\nOriginal array       : ");

// Obj is a pointer instance for Container.
  int i;
  for(i = 0; i < obj->num_; i++)
    fprintf(w_file, "%d ", obj->arr_[i]);

  fprintf(w_file, "%20s", "\nUpdated array        : ");

// Here Update obj's arr_
  update_array(obj);
  for(i = 0; i < obj->num_; i++)
    fprintf(w_file, "%d ", obj->arr_[i]);

  fprintf(w_file, "%20s", "\nCumulative Summation : ");

// Here find obj's cummulative summation.
  obj->arr_ 
    = cumulative_sum(obj->num_, obj->arr_);
  for(i = 0; i < obj->num_; i++)
    fprintf(w_file, "%d ", obj->arr_[i]);

  fprintf(w_file, "\n");

  fclose(w_file);
  
} // write_test

void read_test()
{
  FILE *r_file;

// Basic data read from the file.  
  char path_name[100] = "c_dir/c_file.txt";
  r_file = fopen(path_name, "r");
  
  if(!r_file) // Control for file.
  {
    puts(" File cannot be opened !!");  
    exit(1);
  }

  char in_c;

//  while(!EOF)
//  {
//   c = getc(r_file);
//   printf("%c",c)
//  }  

  while((in_c = getc(r_file)) != EOF)
    printf("%c", in_c);
  
  fclose(r_file);
  
} // read_test

void append_test()
{
  char path_name[100] = "c_dir/c_file.txt";

  FILE *a_file;
  a_file = fopen(path_name, "a");
  
  if(!a_file) // Control for file.
  {
    puts(" File cannot be opened !!");  
    exit(1);
  }

  fprintf(a_file, "\nAppending Something!!!\n");
  
} // append_test

void clean_file()
{
  printf(" ** CLEAN MODE **\n");
  system("echo Cleaning txt file!!!");
  system("cd c_dir && rm c_file.txt");
  
} // clean_file

void usage()
{
  printf("\n *** USAGE *** \n");
  printf(" First argument is\n      Modes  \nWrite  ->   w \nRead   ->   r \nAppend ->   a\n"
    "Clean  ->   c\n");
  printf("\n Second argument is\nNumber of stored item \n");
  
} // usage

int main(int argc, char* argv[])
{  
  usage();
  
  char *in_mode  = argv[1];
//   strcpy(in_mode, argv[1]);
    
//   Check equality for modes.
  if( !(strcmp(in_mode, "w")) )   // if equals strcmp returns 0
  {
//   Cast const pointer to int  
//WARNING:   int in_num_of_store = (int)argv[2];
    int in_num_of_store;
    sscanf(argv[2], "%d", &in_num_of_store);
    
    Container* test_obj; 
    test_obj = malloc(sizeof(Container));
    
    test_obj->num_ = in_num_of_store;
//   Allocate number of in_num_of_store times 0 to arr_
    create_empty_array(test_obj); 

    write_test(test_obj);

    free(test_obj);
  }
  else if( !(strcmp(in_mode, "r")) )
    read_test();
  else if( !(strcmp(in_mode, "a")) )
    append_test();
  else if( !(strcmp(in_mode, "c")) )
    clean_file();
  else
    printf("No such a choice !!!");
  
  return 0;
}
