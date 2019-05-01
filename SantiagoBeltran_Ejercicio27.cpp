#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void laplaceline(int iter, int nmax, string filename);

int main(){
  laplaceline(70, 101, "intento.dat");
  return 0;
}

void laplaceline(int iter, int nmax,string filename){
    float *V_old;
    float *V_new;
    ofstream outfile;
  outfile.open(filename);
    V_old= new float[nmax,nmax];
    V_new= new float[nmax,nmax];
    for(int i=0;i<nmax;i++){
        for(int j=0;j<nmax;j++){
        if(20<=i<=80 && j==40){V_old[i,j]=-100;}
        if(20<=i<=80 && j==60){V_old[i,j]=100;}}
        }
    float error=100.0;
    while(error>0.01){
    
        for(int i=1; i<nmax-1; i++){
        for(int j=1; j<nmax-1; j++){
            if((20<=i<=80 && j==40)||(20<=i<=80 && j==60)){}
            else{
            V_new[i,j]=0.25*(V_old[i+1,j]+V_old[i-1,j]+V_old[i,j+1]+V_old[i,j-1]);}
        }
        }
        float error_o=100;  
        error=0.0;    
        for(int i=1; i<nmax-1; i++){
        for(int j=1; j<nmax-1; j++){
            error_o=abs(V_new[i,j]-V_old[i,j]);
            if(error_o>error){error=error_o;}
        } 
    }
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nmax; j++){
            V_old[i,j]=V_new[i,j];
        }       
}    
    }
    
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nmax; j++){
            outfile << V_new[i,j] << " ";
            if(j==nmax-1){outfile<<endl;}
        }       
}}