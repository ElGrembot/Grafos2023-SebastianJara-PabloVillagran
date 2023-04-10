#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#include <random>

using namespace std;


float grafico(float pi, int iteracion){

            float sum=3.1515926535, comp=10,graf[41][41],graf2[41][41],resta=0,total=0,graf_tabla[26][3];
            int i,j,muestra=0,a=1;
             cout << setprecision(4) << fixed;
           // if(iteracion==0){
                for(i=0;i<41;i++){
                 for(j=0;j<41;j++){
                    if(graf[i][j]!=777){

                        graf[i][j]=0; }

                 }
                }

            //}


            graf_tabla[iteracion-1][0]=iteracion;
            graf_tabla[iteracion-1][2]=pi;

            cout<<"   Iteraciones | Aproximacion de Pi"<<endl;
            cout<<"  --------------------------------"<<endl;
            for(i=0;i<26;i++){
                cout<<"         ";
                for(j=0;j<3;j++){
                    if(j==1){
                        cout<<"|";
                    }


                        else{

                        cout<<graf_tabla[i][j];}

                    }
                cout<<endl;
            }

            cout<<endl;
            //if(iteracion==0){
            for(i=0;i<41;i++){
                for(j=0;j<41;j++){
                    if(j==0){
                        graf[i][j]=sum;
                        sum=sum-0.0005;
                    }
                }
            }
           // }


                  for(i=0;i<41;i++){
                      resta=graf[i][0];
                     total=abs(resta-pi);
                     if(total<comp){
                        muestra=i;
                        comp=total;

                             }


                        }


            graf[muestra][iteracion]=777; //numero especifico para identificar el punto del grafico
            graf2[muestra][iteracion]=777;



            for(i=0;i<41;i++){
                for(j=0;j<41;j++){
                    if(graf[i][j]==777||graf2[41][41]==777){
                        cout<<"X"<<"  ";
                    }
                    else{
                        if(i==20&&j>0){
                        cout<<"-"<<"  ";
                        }
                        else{
                                if(graf[i][j]==0){
                                cout<<" "<<"  ";
                                }
                                 else {
                                cout<<graf[i][j]<<"  ";
                                }
                        }
                    }
                }
                cout<<endl;
            }

            cout<<"----------------------------------------------------------------------------------------------"<<endl;
            cout<<"     ";
            for(i=1;i<27;i++){
                if(i<10){ cout<<"  "<<i;}
                else{
                cout<<" "<<i;}
            }

    return 0;
}

void calculo_pi(int iteracion_t){
float area_cuadrado,area_circulo,Area_dentro;
    float dardos_dentro=0,dardos_fuera=0,total_dardos=100000,formula=0;
    float pi=M_PI,radio,diametro,Area_fuera,r=0;


radio=5;
area_cuadrado= pow(10,2);

area_circulo= 25*pi;

Area_fuera= area_cuadrado-area_circulo;
Area_dentro=area_cuadrado-Area_fuera;
//if(iteracion_t==1){
//cout<< "ingresa cuantos dardos lanzara: ";
//cin>>total_dardos;
    //total_dardos=total_dardos*iteracion_t;
    total_dardos=iteracion_t*iteracion_t*iteracion_t*1000;
//}
//else{total_dardos=1000*iteracion_t;}


for(int i=0;i<total_dardos;i++){
     r = 1 + static_cast<float>(rand()) * static_cast<float>(101 - 1) / RAND_MAX;
     r=r-1;
      if(r<=Area_dentro){
        dardos_dentro=dardos_dentro+1;
      }else{
          //caen en el cuadrado
      dardos_fuera=+1;
      }
}
cout<<endl;
cout << setprecision(9) << fixed;
formula= 4*(dardos_dentro/total_dardos);
cout<<endl;
  cout << formula<< " :  Ultima aproximacion de pi\n"<<endl;
 grafico(formula, iteracion_t);

}


int main()
{
    srand(time(NULL));
    for(int iteracion_t=1;iteracion_t<27;iteracion_t++){
        calculo_pi(iteracion_t);
        fflush(stdin);
    }
return 0;
}

