#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define LEARNFILE "/home/Bobby/git/adaline-intro/learning-set.txt"

/* TYPE DEFINITIONS START */

typedef struct weights_type{
  float bias;
  float w[8];
} weights_type;

typedef struct datapoint{
  float x[8];
  float desired;
} datapoint;

const datapoint DATAPOINT_ZERO = {0, 0};

/* TYPE DEFINITIONS END */

/* GLOBAL VARIABLES START */

const char ETA = 1;


/* GLOBAL VARIABLES END */


/* FUNCTION DEFINITIONS START */

/* -- Non-math functions -- */

datapoint read_datapoint(FILE *stream){
  datapoint data = {0, 0};
  
  if(fscanf(stream, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t",
      &data.x[0], &data.x[1],
      &data.x[2], &data.x[3],
      &data.x[4], &data.x[5],
      &data.x[6], &data.x[7],
      &data.desired) != 8){
    data.x[0] = -1;
  }
  return data;
}

/* -- Math functions -- */

float eval(datapoint data, weights_type weights){
  short i = 0;
  float result = weights.bias;
  
  for(i = 0; i < 8; i++){
    result += (weights.w[i] * data.x[i]);
  }
  
  return result;
}

float calc_error(datapoint data, weights_type weights){
  return (data.desired - eval(data, weights));
}

void weight_update(datapoint data, weights_type &weights){
  short i = 0;
  for(i = 0; i < 8; i++){
    weights.w[i] = weights.w[i] + (ETA * calc_error(data, weights) * data.x[i]);
  }
}

/* FUNCTION DEFINITIONS END */

/* MAIN START */

int main(){
  
  FILE *dataset = fopen(LEARNFILE, "r");
  
  weights_type w = {0, 1, 1, 1, 1, 1, 1, 1, 1};
  datapoint data = read_datapoint(dataset);
  
  while(data.x[0] != -1){
    break;
  }
  
  
  
  fclose(dataset);
  
  return 0;
}

/* MAIN END */
