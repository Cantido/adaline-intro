#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEARNING_FILE "/home/Bobby/git/adaline-intro/learning-set.txt"

/* GLOBAL VARIABLES START */

const float LEARNING_RATE = 0.5;
const float NORMALIZERS[] = {540.0, 359.4, 174.7, 288.0, 32.2, 1145.0, 992.6, 365.0, 82.6};

FILE* input_file;

/* GLOBAL VARIABLES END */


/* FUNCTION DEFINITIONS START */

/* -- Non-math functions -- */

float* get_datapoint(){
  static float x[10] = {0};
  
  /* first eight values are input, ninth is 1 (bias), tenth is desired value */
  
  if(fscanf(input_file, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
  &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7], &x[8]) != 9){
    x[0] = -1;
  }
  else {
    for(int i = 0; i < 9; i++){
      x[i] /= NORMALIZERS[i];
    }
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

void learn(){
  int iterations = 1;
  
  float w[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 9th weight is bias
  
  
  for(iterations = 1; iterations <= 500; iterations ++){
  
    float sumsqr_error = 0;
    float sumsqr = 0;
    int count = 1;
    fseek(input_file, 0, SEEK_SET);
    float* x = get_datapoint();
    
    while(x[0] != -1){
      sumsqr += calc_error(x, w) * calc_error(x, w);
      sumsqr_error = sumsqr / (2 * count);
      weight_update(x, w);
      x = get_datapoint();
      count++;
    }
    
    printf("%i\t%f\n", iterations, sumsqr_error);
  }
  printf("Weights:\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
     w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8]);
  
  return;
}

void test(){
  
  float w[9] = {0.313159, 0.301605,  0.916192, 0.513296, 1.003430,
                  -0.209391 , 0.012439, 0.074814, 0.998135}; // 9th weight is bias
  float* x = get_datapoint();
  
  
  printf("Testing with:\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
     w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8]);
  
  
  
  float sumsqr_error = 0;
  int count = 1;
  fseek(stdin, SEEK_SET, 0);
  
  while(x[0] != -1){
    sumsqr_error += calc_error(x, w) * calc_error(x, w);
    x = get_datapoint();
    count++;
  }
    
  sumsqr_error /= 2 * count;
    
  printf("Error on test set:\t%f\n", sumsqr_error);
  
  return;
}


/* FUNCTION DEFINITIONS END */

/* MAIN START */

int main(){
  
  input_file = fopen(LEARNING_FILE, "r");
  
  learn();
  
  return 0;
}

/* MAIN END */
