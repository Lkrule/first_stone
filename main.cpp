#include <iostream>
#include "anomaly_detection.h"
int main() {
    float j[5] = {5,12,18,23,45};
    const int N=10;
    float x[]={1,2,3,4,5,6,7,8,9,10};
    float y[]={2.1,4.2,6.1,8.1,10.3,12.2,14.4,16.1,18.2,20.3};
    Point* ps[N];
    for(int i=0;i<N;i++)
        ps[i]=new Point(x[i],y[i]);
    Line l=linear_reg(ps,N);
    Point p(4,8);
    float k[5] = {2,8,18,20,28};
    std::cout << l.a << std::endl;
    std::cout << l.b << std::endl;
    return 0;
}
