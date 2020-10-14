//
// Created by ASUS on 10/13/2020.
//

#include "anomaly_detection.h"
#include <cmath>
#include <iostream>
float avg(float* x, int size){
    float sum = 0;
    for (int i = 0; i<size;i++){
        sum += x[i];
    }
    return sum / size;
}
// returns the variance of X and Y
float var(float *x, int size) {
    float sum=0;
    float var=0;
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    float average = sum / size;
    for (int i = 0; i < size; i++) {
        var += pow(x[i] - average, 2) / (size);
    }
    return var;
}

// returns the covariance of X and Y
float cov(float *x, float *y, int size){
    float sumX =0;
    for (int i=0; i<size; i++){
        sumX += x[i];
    }
   float meanX = sumX / size;
    float sumY = 0;
    for (int i =0; i<size; i++){
        sumY += y[i];
    }
    float meanY = sumY/size;
    float cover = 0;
    for (int i = 0 ; i<size;i++){
      cover +=  (x[i]-meanX) * (y[i] - meanY);
    }
    return cover/size;
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float *x, float *y, int size){
    float cove = cov(x,y,size);
    float denomi = sqrtf(var(x,size)*var(y,size));
    return cove/denomi;
}

// performs a linear regression and return s the line equation
Line linear_reg(Point **points, int size){
    float xPos[size];
    float yPos[size];
    for (int i = 0 ; i < size ; i ++){
       xPos[i] = points[i]->x;
       yPos[i] = points[i]->y;
    }
    float a = cov(xPos,yPos,size) / var(xPos,size);
    float b = avg(yPos,size) - a*(avg(xPos,size));
    return Line(a,b);

}

// returns the deviation between point p and the line equation of the points
float dev(Point p, Point **points, int size);

// returns the deviation between point p and the line
float dev(Point p, Line l);

