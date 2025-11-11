#include<stdio.h>
#include<math.h>
int main(){
    int n=3,i;
    double x[]={0,1,2};
    double y[]={1,6,17};
    double sum_x=0,sum_y=0,sum_x2=0,sum_x3=0,sum_x4=0,sum_xy=0,sum_x2y=0;
    for(int i=0;i<n;i++){
        sum_x+=x[i];
        sum_y+=y[i];
        sum_x2+=pow(x[i],2);
        sum_x3+=pow(x[i],3);
        sum_x4+=pow(x[i],4);
        sum_xy+=x[i]*y[i];
        sum_x2y+=pow(x[i],2)*y[i];
    }
    double A[3][3]={{n,sum_x,sum_x2},{sum_x,sum_x2,sum_x3},{sum_x2,sum_x3,sum_x4}};
    double B[3]={sum_y,sum_xy,sum_x2y};
    double det_A=A[0][0](A[1][1]*A[2][2]-A[1][2]*A[2][1])+A[0][1](A[1][2]A[2][0]-A[1][0]*A[2][2])+A[0][2](A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    double det_A0=B[0](A[1][1]*A[2][2]-A[1][2]*A[2][1])+A[0][1](A[1][2]B[2]-B[1]*A[2][2])+A[0][2](B[1]*A[2][1]-A[1][1]*B[2]);
    double det_A1=A[0][0](B[1]*A[2][2]-A[1][2]*B[2])+B[0](A[1][2]A[2][0]-A[1][0]*A[2][2])+A[0][2](A[1][0]*B[2]-B[1]*A[2][0]);
    double det_A2=A[0][0](A[1][1]*B[2]-B[1]*A[2][1])+A[0][1](B[1]A[2][0]-A[1][0]*B[2])+B[0](A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    if(det_A==0){
        printf("The system has no unique soln\n");
        return 1;
    }
    double a0=det_A0/det_A;
    double a1=det_A1/det_A;
    double a2=det_A2/det_A;
    printf("f(x)=%.2f+%.2f x+%.2f x^2 \n",a0,a1,a2);
    return 0;

}
