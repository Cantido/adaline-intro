#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TYPE DEFINITIONS START */

typedef struct weights_type{
  float w[8];
} weights_type;

typedef struct datapoint{
  float x[8];
  float desired;
} datapoint;


/* TYPE DEFINITIONS END */

/* GLOBAL VARIABLES START */

const float ETA = 0.000001;


/* GLOBAL VARIABLES END */


/* FUNCTION DEFINITIONS START */

/* -- Non-math functions -- */

datapoint get_datapoint(){
  datapoint data = {0, 0};
  
  if(scanf("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f \n",
      &data.x[0], &data.x[1],
      &data.x[2], &data.x[3],
      &data.x[4], &data.x[5],
      &data.x[6], &data.x[7],
      &data.desired) != 9){
    data.x[0] = -1;
  }
  return data;
}

/* -- Math functions -- */

float eval(datapoint data, weights_type weights){
  short i = 0;
  float result = 0;
  
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

int main(int argc, char* argv[]){
  
  int count = 1;
  float total_error = 0;
  float step_error = 0;
  
  char print_curve = 0;
  char print_weights = 0;
  
  weights_type w = {0, 0, 0, 0, 0, 0, 0, 0};
  datapoint data = get_datapoint();
  
  if((strcmp(argv[1], "curve") == 0) || (strcmp(argv[2], "curve") == 0))
    print_curve = 1;
  if((strcmp(argv[1], "weights") == 0) || (strcmp(argv[2], "weights") == 0))
    print_weights = 1;
  
  
  while(data.x[0] != -1){
    if(print_curve == 1){
      step_error = calc_error(data, w);
    
      total_error += step_error * step_error;
      total_error /= 2 * count;
    
      printf("%i\t%f\n", count, total_error);
    }
    
    weight_update(data, w);
    
    data = get_datapoint();
    count++;
  }
  
  if(print_weights == 1){
    printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t \n",
      w.w[0], w.w[1], w.w[2], w.w[3], w.w[4], w.w[5], w.w[6], w.w[7]);
  }
  
  return 0;
}

/* MAIN END */
