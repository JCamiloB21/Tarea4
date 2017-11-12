#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define LONG 0.64
#define C 250
#define TIME 1
#define Dx 0.005
#define T 260
#define Dxt 0.005
#define Dyt 0.005



#define PI 3.14159265

double posicion[129];
double u_pas1[129];
double u_pas2[129];
double u_pas3[129];
double u_pas4[129];
double u_pas5[129];
double u_pas9[129];
double u_pas10[129];
double u_pas11[129];
double u_pas12[129];
double u_pas13[129];



double u_fut1[129];
double u_fut2[129];
double u_fut3[129];
double u_fut4[129];
double u_fut5[129];
double u_fut9[129];
double u_fut10[129];
double u_fut11[129];
double u_fut12[129];
double u_fut13[129];


double u_pres1[129];
double u_pres2[129];
double u_pres3[129];
double u_pres4[129];
double u_pres5[129];
double u_pres9[129];
double u_pres10[129];
double u_pres11[129];
double u_pres12[129];
double u_pres13[129];

char line_buffer[101];
char *split_buffer;

double matrix[101][101];
double matrix1[101][101];
double matrix2[101][101];
double matrix3[101][101];

double u_pres20[101][101];
double u_pres21[101][101];
double u_pres22[101][101];
double u_pres23[101][101];

double u_fut20[101][101];
double u_fut21[101][101];
double u_fut22[101][101];
double u_fut23[101][101];



float Dt = (0.5 * Dx)/C;
int j;
int i;
int t;
int m;
int n;
float k;
float k1;


void futuro();
void paraplot();
void presente();
void paraplotpm();

void presentetambor();
void futurotambor();
    
int main(void){
    FILE *in;
    int i;
    double var1;
    double var2;
    int test;
    char filename[150]="cond_ini_cuerda.dat";
    printf("writing to file: %s\n",filename);

    in=fopen(filename,"r");
    if(!in){
        printf("problems opening the file %s\n",filename);
        exit(1);
    }
    printf("Now I am reading\n");
    for (i=0;i<129;i++){
        fscanf(in,"%lf %lf \n", &var1, &var2);
        posicion[i]= var1;
        u_pas1[i]= var2;
        u_pas2[i]= var2;
        u_pas3[i]= var2;
        u_pas4[i]= var2;
        u_pas5[i]= var2;
        u_pas9[i]= 0;
        u_pas10[i]= 0;
        u_pas11[i]= 0;
        u_pas12[i]= 0;





       
    }
    
    fclose(in);
    presente();
    futuro();
    paraplot();
    paraplotpm();
    
    FILE *tam;
    int j;
    char filename1[101]="cond_ini_tambor.dat";
    printf("writing to file: %s\n",filename1);

    tam=fopen(filename1,"r");
    if(!tam){
        printf("problems opening the file %s\n",filename1);
        exit(1);
    }
    printf("Now I am reading\n ");
    for(i=0;i<101;i++){
        fgets(line_buffer,101,tam);
        split_buffer= strtok(line_buffer," ");
        for (j=0;j<100;j++){
            matrix[i][j]=atof(split_buffer);
            matrix1[i][j]=atof(split_buffer);
            matrix2[i][j]=atof(split_buffer);
            matrix3[i][j]=atof(split_buffer);


        }
        split_buffer= strtok(NULL," ");


    }
    fclose(in);
    presentetambor();
    futurotambor();

        
    
}
void presente(){
    for(i=1;i<130;i++){
        u_pres1[i]= u_pas1[i] + k/2*(u_pas1[i+1] - 2*u_pas1[i] + u_pas1[i-1]);
        u_pres2[i]= u_pas2[i] + k/2*(u_pas2[i+1] - 2*u_pas2[i] + u_pas2[i-1]);
        u_pres3[i]= u_pas3[i] + k/2*(u_pas3[i+1] - 2*u_pas3[i] + u_pas3[i-1]);
        u_pres4[i]= u_pas4[i] + k/2*(u_pas4[i+1] - 2*u_pas4[i] + u_pas4[i-1]);
        u_pres5[i]= u_pas5[i] + k/2*(u_pas5[i+1] - 2*u_pas5[i] + u_pas5[i-1]);
        u_pres9[i]= u_pas9[i] + k/2*(u_pas9[i+1] - 2*u_pas9[i] + u_pas9[i-1]);
        u_pres10[i]= u_pas10[i] + k/2*(u_pas10[i+1] - 2*u_pas10[i] + u_pas10[i-1]);
        u_pres11[i]= u_pas11[i] + k/2*(u_pas11[i+1] - 2*u_pas11[i] + u_pas11[i-1]);
        u_pres12[i]= u_pas12[i] + k/2*(u_pas12[i+1] - 2*u_pas12[i] + u_pas12[i-1]);
    }
}
void futuro()
{
    k = (C*C*Dt*Dt)/(Dx*Dx);
    for(j=1;j<=TIME/Dt;j++){
        for(i=1;i<130;i++){
            u_fut1[i]= 2*(1-k)*u_pres1[i] - u_pas1[i] + k*(u_pres1[i+1] + u_pres1[i-1]);
            u_fut1[128]=0.0;
            

            }
        for(m=1;m<130;m++){
            u_pas1[m]=u_pres1[m];
            u_pres1[m]=u_fut1[m];
         }
    }
    for(j=1;j<=1;j++){
        for(i=1;i<130;i++){
            u_fut2[i]= 2*(1-k)*u_pres2[i] - u_pas2[i] + k*(u_pres2[i+1] + u_pres2[i-1]);  
            u_fut2[128]=0.0;
            }
        for(m=1;m<130;m++){
            u_pas2[m]=u_pres2[m];
            u_pres2[m]=u_fut2[m];
        }
    }
    for(j=1;j<=T/8;j++){
        for(i=1;i<130;i++){
            u_fut3[i]= 2*(1-k)*u_pres3[i] - u_pas3[i] + k*(u_pres3[i+1] + u_pres3[i-1]);  
            u_fut3[128]=0.0;

            }
        for(m=1;m<130;m++){
            u_pas3[m]=u_pres3[m];
            u_pres3[m]=u_fut3[m];
            }
    }
    for(j=1;j<=T/4;j++){
        for(i=1;i<130;i++){
            u_fut4[i]= 2*(1-k)*u_pres4[i] - u_pas4[i] + k*(u_pres4[i+1] + u_pres4[i-1]);  
            u_fut4[128]=0.0;

            }
        for(m=1;m<130;m++){
            u_pas4[m]=u_pres4[m];
            u_pres4[m]=u_fut4[m];
            }
    }
    for(j=1;j<=T/2;j++){
        for(i=1;i<130;i++){
            u_fut5[i]= 2*(1-k)*u_pres5[i] - u_pas5[i] + k*(u_pres5[i+1] + u_pres5[i-1]);  
            u_fut5[128]=0.0;

            }
        for(m=1;m<130;m++){
            u_pas5[m]=u_pres5[m];
            u_pres5[m]=u_fut5[m];
            }
    }
   
    for(j=0;j<=0;j++){
        for(i=1;i<130;i++){
            u_fut9[i]= 2*(1-k)*u_pres9[i] - u_pas9[i] + k*(u_pres9[i+1] + u_pres9[i-1]);  
            u_fut9[128]=sin((2*C*PI/LONG)*j*Dt);

            }
        for(m=1;m<130;m++){
            u_pas9[m]=u_pres9[m];
            u_pres9[m]=u_fut9[m];
            }
    }
    for(j=0;j<=T/8;j++){
        for(i=1;i<130;i++){
            u_fut10[i]= 2*(1-k)*u_pres10[i] - u_pas10[i] + k*(u_pres10[i+1] + u_pres10[i-1]);  
            u_fut10[128]=sin((2*C*PI/LONG)*j*Dt);

            }
        for(m=1;m<130;m++){
            u_pas10[m]=u_pres10[m];
            u_pres10[m]=u_fut10[m];
            }
    }
    for(j=0;j<=T/4;j++){
        for(i=1;i<130;i++){
            u_fut11[i]= 2*(1-k)*u_pres11[i] - u_pas11[i] + k*(u_pres11[i+1] + u_pres11[i-1]);  
            u_fut11[128]=sin((2*C*PI/LONG)*j*Dt);

            }
        for(m=1;m<130;m++){
            u_pas11[m]=u_pres11[m];
            u_pres11[m]=u_fut11[m];
            }
    }
    for(j=0;j<=T/2;j++){
        for(i=1;i<130;i++){
            u_fut12[i]= 2*(1-k)*u_pres12[i] - u_pas12[i] + k*(u_pres12[i+1] + u_pres12[i-1]);  
            u_fut12[128]=sin((2*C*PI/LONG)*j*Dt);

            }
        for(m=1;m<130;m++){
            u_pas12[m]=u_pres12[m];
            u_pres12[m]=u_fut12[m];
            }
    }
}        




void paraplotpm(){
    FILE *audio=fopen("audio.dat","w");
    for(j=1;j<=TIME/Dt;j++){
        for(i=1;i<130;i++){
            u_fut1[i]= 2*(1-k)*u_pres1[i] - u_pas1[i] + k*(u_pres1[i+1] + u_pres1[i-1]);
            u_fut1[128]=0.0;
            fprintf(audio, "%f\n",u_fut1[65]);


            }
        for(m=1;m<130;m++){
            u_pas1[m]=u_pres1[m];
            u_pres1[m]=u_fut1[m];
         }
    }
    
}


void presentetambor(){
    for(i=0;i<101;i++){
        for(j=0;j<101;i++){
            u_pres20[i][j]=matrix[i][j];
        }
    }
}

void futurotambor(){
    k1 = (C*C*Dt*Dt)/(Dxt*Dxt);
    for(t=1;t<=1;t++){
        for(i=1;i<101;i++){
            for(j=1;j<101;j++){
                u_fut20[i][j]=k1*(u_pres20[i+1][j] + matrix[i-1][j] - 2*u_pres20[i][j]) + k1*(u_pres20[i][j+1] + matrix[i][j-1] - 2*u_pres20[i][j]) + 2*u_pres20[i][j] - matrix[i][j];
            }
            for(m=1;m<101;m++){
                for(n=1;n<101;n++){
                    matrix[m][n]=u_pres20[m][n];
                    u_pres20[m][n]=u_fut20[n][m]; 
                }
            
         }
        }
    }
    for(t=1;t<=T/8;t++){
        for(i=1;i<101;i++){
            for(j=1;j<101;j++){
                u_fut21[i][j]=k1*(u_pres21[i+1][j] + matrix1[i-1][j] - 2*u_pres21[i][j]) + k1*(u_pres21[i][j+1] + matrix1[i][j-1] - 2*u_pres21[i][j]) + 2*u_pres21[i][j] - matrix1[i][j];
            }
            for(m=1;m<101;m++){
                for(n=1;n<101;n++){
                    matrix1[m][n]=u_pres21[m][n];
                    u_pres21[m][n]=u_fut21[n][m]; 
                }
            }
        }
    }
    for(t=1;t<=T/4;t++){
        for(i=1;i<101;i++){
            for(j=1;j<101;j++){
                u_fut22[i][j]=k1*(u_pres22[i+1][j] + matrix2[i-1][j] - 2*u_pres22[i][j]) + k1*(u_pres22[i][j+1] + matrix2[i][j-1] - 2*u_pres22[i][j]) + 2*u_pres22[i][j] - matrix2[i][j];
            }
            for(m=1;m<101;m++){
                for(n=1;n<101;n++){
                    matrix2[m][n]=u_pres22[m][n];
                    u_pres22[m][n]=u_fut22[n][m]; 
                }
            }
        }
    }
    for(t=1;t<=T/2;t++){
        for(i=1;i<101;i++){
            for(j=1;j<101;j++){
                u_fut23[i][j]=k1*(u_pres23[i+1][j] + matrix3[i-1][j] - 2*u_pres23[i][j]) + k1*(u_pres23[i][j+1] + matrix3[i][j-1] - 2*u_pres23[i][j]) + 2*u_pres23[i][j] - matrix3[i][j];
            }
            for(m=1;m<101;m++){
                for(n=1;n<101;n++){
                    matrix3[m][n]=u_pres23[m][n];
                    u_pres23[m][n]=u_fut23[n][m]; 
                }
            }
        }
    }
    
}

void paraplot(){
    FILE *mifile= fopen("Resultados_hw4.tex", "w");
    for(i=0;i<129;i++){
        fprintf(mifile, "format: %f %f %f %f %f %f %f %f %f %f\n", posicion[i],u_fut1[i],u_fut2[i],u_fut3[i],u_fut4[i],u_fut5[i],u_fut9[i],u_fut10[i],u_fut11[i],u_fut12[i]);
    }
}


