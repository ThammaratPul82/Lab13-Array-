#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double A [],int N,double B[]);
    
    

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}


void stat(const double A [],int N,double B[]){
    double sum=0;
    for (int i;i<N;i++){
        sum+=A[i];
    }
    double mean=sum/N;
    
    
    double a=0;
    for (int i=0;i<N;i++){
        a+=pow(A[i],2);
    }
    double sd=sqrt((a/N)-pow(mean,2));
    
    double dsum=1;
    for (int i=0;i<N;i++){
        dsum*=A[i];
    } 
    
    double hsum=0;
    for (int i=0;i<N;i++){
        hsum+= 1/A[i];
    }
    double max=A[0];
    for (int i=0;i<N;i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    double min=A[0];
    for(int i=0;i<N;i++){
        if(min>A[i]){
            min=A[i];
        }
    }


    B[0]=mean;
    B[1]=sd;
    B[2]=powl(dsum,1/(N*1.0));
    B[3]=N/hsum;
    B[4]=max;
    B[5]=min;
    
}

    