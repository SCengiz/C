/*
  C Solution :
    Access the global variables in functions.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHAR_LEN 10

// Global variables for test.
int ID = 1034125;
char name[CHAR_LEN] = "Soray";
char surname[CHAR_LEN] = "Cengiz";
extern int kk;

void glob_kk()
{
//   Gives an error when using kk without declaration.
  int kk = 1;
  printf("\n %15d \n ", kk);
}

// Basic output function for showing variables.
void output()
{
  printf(" %10s %10s \n", name, surname);
  printf(" %15d \n", ID);
  
} // output

// Change ID using its reference. 
void access_ID(int *in_ID, int new_value)
{
  *in_ID = new_value;  

} // access_ID

// Change char global variables using its first address.
// For loop used for accessing memory blocks of chars.
void access_name_surname(char *in_char, char *new_char)
{
  int kk = 0;
  for(; kk < CHAR_LEN; kk++)
    *(in_char + kk) = *(new_char + kk);

} // access_name

void access_ID_directy()
{
  ID = 2132104;  
} // access_ID_directy

int main()
{
  output();

//   Changing ID using integer pointer ptr holds ID's reference.
  int *ptr;
  ptr = &ID;  
  access_ID(ptr, 1021568);
  
  output();
    
//   strcpy is used for changing char value.
  strcpy( name, "CENGIZ" );

//   memset will clear the surname
//   surname is a first adress of surname char.
  memset( surname, '\0', CHAR_LEN*(sizeof(char)) );
  output();

//   change ID of with directly its reference.  
  access_ID( &ID, 4401264 );
  access_name_surname( surname, "SORAY" );
  output();
  
  access_ID_directy();
  output();
  
  glob_kk();
  
//   Gives an error !!!
//   int kk = 2;
//   printf(" \n %15d \n", kk);

  return 0;
} // main
