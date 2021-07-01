/*
  Answer of 
    " https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem "
  01.07.2021 
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

// Basic struct type for triangles. It contains lengths and some other datas.
typedef struct Triangle { 
  int a,b,c;
  double area;  
  
}triangle;

// Here we make a fake pass by reference example.
void calculate_area(triangle *tri) {
  double p 
    = (tri->a + tri->b + tri->c) / 2;

// This formula has been given us in problem statement.
  tri->area 
    = sqrt(p * (p - tri->a) * (p - tri->b) * (p - tri->c) );
  
} // calculate_area

void check_sides(triangle *tri) {
// Using Assert is dangerous.
//   FIRST CHECK
  assert
    ( 
      tri->a >= 1 && tri->a <= 70 && 
      tri->b >= 1 && tri->b <= 70 && 
      tri->c >= 1 && tri->c <= 70 
    );
//   SECOND CHECK
  assert
    ( 
      (tri->a + tri->b) > tri->c && 
      (tri->a + tri->c) > tri->b &&
      (tri->b + tri->c) > tri->a
    );
} // check_sides

// We are sorting the triangle instances by looking its areas.
void sort_by_area(triangle tri[], int n) {
//   HERE SELECTION SHORT ALGORITHM USED
  int kk = 0, jj = 0;
  for(; kk < n-1; ++kk) {
    int min_index = kk;
    for(jj = kk+1; jj < n; ++jj) {
      if(tri[jj].area < tri[min_index].area){
        min_index = jj;
      }
    }
// SWAPPING THE INSTANCES 
    triangle temp = tri[min_index];
    tri[min_index] = tri[kk];
    tri[kk] = temp;  
  }
} // sort_by_area

void output(triangle tri[], int n) {
  printf(" \n OUTPUT \n");
  int kk = 0;
  for(; kk < n; ++kk) 
    printf("%d %d %d \n", tri[kk].a, tri[kk].b, tri[kk].c);
    
} // output

void basic_test() {
  int n;
  scanf("%d", &n);
  
//   checking the constraint
  assert( n >= 1 && n <= 100);
  
  triangle *t_obj
     = calloc(n, sizeof(triangle));
   
  int kk = 0;
  for(; kk < n; ++kk) {
    scanf("%d%d%d", &t_obj[kk].a, &t_obj[kk].b, &t_obj[kk].c);
    check_sides(&t_obj[kk]);
    calculate_area(&t_obj[kk]);
  }   
  
  sort_by_area(t_obj, n);
  output(t_obj, n);

  free(t_obj);
  
} // basic_test

int main(){
    
  basic_test();
  
  return 0;  
  
} // main
