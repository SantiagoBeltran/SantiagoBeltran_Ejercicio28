#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void laplaceline(int nmax, int nt,string filename);

int main(){
  laplaceline(100, 4000, "intento.dat");
  return 0;
}

void laplaceline(int nmax, int nt,string filename){
    float T_old[nmax][nt]={0};
    float T_new[nmax][nt]={0};
    const float dx=0.01;
    const float dt=0.01;
    const float K=237;
    const float C=900;
    const float r=2700;
    float n;
    ofstream outfile;
  outfile.open(filename);
    for (int i=0; i<nmax;i++){
        T_old[i][0]=100;T_new[i][0]=100;}
    
    n=K*dt/(C*r*dx*dx);
    float error=100.0;
    while(error>0.00001){
    
        for(int i=1; i<nmax-1; i++){
        for(int j=0; j<nt-1; j++){
            if(i!=0&&i!=nmax-1){
            
            T_new[i][j+1]=T_old[i][j]+n*(T_old[i+1][j]+T_old[i-1][j]-2*T_old[i][j]);}
        }
        }
        int cont=0;  
        error=0.0;    
        for(int i=1; i<nmax-1; i++){
        for(int j=0; j<nt-1; j++){
            error=error+abs(T_new[i][j]-T_old[i][j]);
            cont=cont+1;
        }    
    }
        error=error/cont;
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nt; j++){
            T_old[i][j]=T_new[i][j];
        }       
}    
    }
    
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nt; j++){
            outfile << T_new[i][j] << " ";
            if(j==nt-1){outfile<<endl;}
        } 
}
}
