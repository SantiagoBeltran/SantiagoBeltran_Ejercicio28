#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void laplaceline(int iter, int nmax, string filename);

int main(){
  laplaceline(10000, 101, "intento.dat");
  return 0;
}

void laplaceline(int iter, int nmax,string filename){
    float V_old[nmax][nmax]={0};
    float V_new[nmax][nmax]={0};
    ofstream outfile;
  outfile.open(filename);
    for(int i=20;i<=80;i++){
        V_old[i][40]=-100;V_new[i][40]=-100;
        V_old[i][60]=100;V_new[i][60]=100;
        }
    
    float error=100.0;
    while(error>0.00001){
    
        for(int i=1; i<nmax-1; i++){
        for(int j=1; j<nmax-1; j++){
            if(!((20<=i&& i<=80 && j==40)||(20<=i&& i<=80 && j==60))){
            
            V_new[i][j]=0.25*(V_old[i+1][j]+V_old[i-1][j]+V_old[i][j+1]+V_old[i][j-1]);}
        }
        }
        int cont=0;  
        error=0.0;    
        for(int i=1; i<nmax-1; i++){
        for(int j=1; j<nmax-1; j++){
            error=error+abs(V_new[i][j]-V_old[i][j]);
            cont=cont+1;
        }    
    }
        error=error/cont;
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nmax; j++){
            V_old[i][j]=V_new[i][j];
        }       
}    
    }
    
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nmax; j++){
            outfile << V_old[i][j] << " ";
            if(j==nmax-1){outfile<<endl;}
        } 
}
}
