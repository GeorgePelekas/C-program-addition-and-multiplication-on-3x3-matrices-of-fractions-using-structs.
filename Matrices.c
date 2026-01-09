#include <stdio.h>
#include <stdlib.h>
struct klasma
{
    int arithmitis;
    int paronomastis;

};

void fillmatrixes(struct klasma arithmoy[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arithmoy[i][j].arithmitis=(rand()%5+1)*2;
            arithmoy[i][j].paronomastis=(rand()%5*2)+11;
        }
    }
}

int MKD(int a ,int b)
{
    while (b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int EKP(int a,int b)
{ 
   return (a*b)/MKD(a,b); 
}

void addmatrixes(struct klasma arithmoyA[3][3],struct klasma arithmoyB[3][3],struct klasma arithmoyC[3][3])
{   
    int pollaplasiastis;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            pollaplasiastis=EKP(arithmoyA[i][j].paronomastis,arithmoyB[i][j].paronomastis);
            arithmoyC[i][j].paronomastis=pollaplasiastis;
            int multipliera=pollaplasiastis/arithmoyA[i][j].paronomastis;
            int multiplierb=pollaplasiastis/arithmoyB[i][j].paronomastis;
            arithmoyC[i][j].arithmitis=arithmoyA[i][j].arithmitis*multipliera+arithmoyB[i][j].arithmitis*multiplierb;


        }
    }
}

void aplopoihsh(struct klasma arithmoyC[3][3])
{
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int koinosdiairetis=MKD(arithmoyC[i][j].arithmitis,arithmoyC[i][j].paronomastis);
            arithmoyC[i][j].arithmitis /=koinosdiairetis;
            arithmoyC[i][j].paronomastis/=koinosdiairetis;
        }
    }
}

void multiplymatrixes(struct klasma arithmoyA[3][3],struct klasma arithmoyB[3][3],struct klasma arithmoyC[3][3])
{   for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arithmoyC[i][j].arithmitis=0;
            arithmoyC[i][j].paronomastis=1;
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {   
            for(int k=0;k<3;k++)
            {  

               int a1 = arithmoyA[i][k].arithmitis;
               int b1 = arithmoyA[i][k].paronomastis;

               int a2 = arithmoyB[k][j].arithmitis;
               int b2 = arithmoyB[k][j].paronomastis;
               int per1=MKD(a1,b2);
               int per2=MKD(a2,b1);
               a1/=per1;
               b2/=per1;
               a2/=per2;
               b1/=per2;
               int arithmitis=a1*a2;
               int paranomastis=b1*b2;
               int performance=MKD(arithmitis,paranomastis);
               arithmitis/=performance;
               paranomastis/=performance;
               int pollaplasiastis=EKP(arithmoyC[i][j].paronomastis,paranomastis);
               int dejipollaplasio=pollaplasiastis/paranomastis;
               int aristeropollaplasio=pollaplasiastis/arithmoyC[i][j].paronomastis;
               
               arithmoyC[i][j].arithmitis=dejipollaplasio*arithmitis+aristeropollaplasio*arithmoyC[i][j].arithmitis;
               arithmoyC[i][j].paronomastis=pollaplasiastis;

              }
            }
        }    
    }



void SHOW(struct klasma arithmoyC[3][3]){
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (j<1)
            {
                printf("\n");
            }
            printf("| %8d/%-8d |",arithmoyC[i][j].arithmitis,arithmoyC[i][j].paronomastis);
            if (i==2 && j==2){
                printf("\n");
                for(int al=0; al<64;al++){
                    if(al==63){
                        printf("\n");
                    }
                    else
                    {
                        printf("-");
                    }
                    
                }
            }
        }
    }
}

int main()
{
    srand(5425);
    struct klasma arithmoyA[3][3];
    struct klasma arithmoyB[3][3];
    struct klasma arithmoyC[3][3];
    fillmatrixes(arithmoyA);
    fillmatrixes(arithmoyB);
    addmatrixes(arithmoyA,arithmoyB,arithmoyC);
    aplopoihsh(arithmoyC);
    printf("τα κλασματα στην πρόσθεση των 2 πινάκων ειχανε αποτελεσμα: ");
    SHOW(arithmoyC);
    multiplymatrixes(arithmoyA,arithmoyB,arithmoyC);
    printf("τα κλασματα στον πολλαπλασιασμο ΑΧΒ πινάκων ειχανε αποτέλεσμα: ");
    aplopoihsh(arithmoyC);
    SHOW(arithmoyC);
    multiplymatrixes(arithmoyB,arithmoyA,arithmoyC);
    aplopoihsh(arithmoyC);
    printf("τα κλασματα στον πολλαπλασιασμο BXA πινάκων ειχανε αποτέλεσμα: ");
    SHOW(arithmoyC);   
}