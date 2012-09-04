#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* GLOBAL VARIABLES START */

const float LEARNING_RATE = 0.000000001;

/* GLOBAL VARIABLES END */


/* FUNCTION DEFINITIONS START */

/* -- Non-math functions -- */

float* get_datapoint(){
  static float x[10] = {0};
  
  /* first eight values are input, ninth is 1 (bias), tenth is desired value */
  
  if(scanf("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
  &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7], &x[8]) != 9){
    x[0] = -1;
  }
  else {
    x[9] = x[8];
    x[8] = 1;
  }
  return x;
}

/* -- Math functions -- */

float calc_error(float x[], float w[]){
  int i = 0;
  float real = 0;
  
  for(i = 0; i < 9; i++){
    real += (w[i] * x[i]);
  }
  
  return (x[9] - real);
}


void weight_update(float x[], float w[]){
  short i = 0;
  float step_error = calc_error(x, w);
  for(i = 0; i < 9; i++){
    w[i] += (LEARNING_RATE * step_error * x[i]);
  }
}

/* FUNCTION DEFINITIONS END */

/* MAIN START */

int main(){
  
  int count = 1;
  
  float w[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 9th weight is bias
  float* x = get_datapoint();
  
  
  while(x[0] != -1){
    printf("%i:\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
     count, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8]);
  
    weight_update(x, w);
    x = get_datapoint();
    count++;
  }
  
  printf("Final:\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
     w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8]);
  
  return 0;
}

/* MAIN END */
