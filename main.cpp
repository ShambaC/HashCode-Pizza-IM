#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

unsigned int R;                         //Number of rows
unsigned int C;                        //Number of columns
unsigned int L;                         //Minimum number of ingredients
unsigned int H;                        //Maximum number of cells in the slice

struct Pizza{
char Value;
bool Occupied;
int Serial;
}P[1000][1000];       //Legendary Pizza;
int i=0, j=0;                                          //Loop Variables

char fileLocation[40];                 //file location of file
char filename[8];                 //filename of the input file
char fullFile[60];
fstream input_file;                 //input_file filestream object

void CreatePizza();                //Will Create The Fking Pizza
void TakeInput();                  //Will take those asshole inputs
void IngrediantFinder();
int main()
{
    CreatePizza();
    TakeInput();


    return 0;
}
void CreatePizza(){
    cout<<"Welcome to our master Pizza code !!\n";
    cout<<"\nLet's create the Pizza first :p ";
    cout<<"\nTell me the input file name : ";
    cin>>filename;
    cout<<"\nNice One ! Now Tell me the Location of the file";
    cin>>fileLocation;
    strcat(fullFile,fileLocation);
    strcat(fullFile,filename);
    strcat(fullFile,".in");
    input_file.open(fullFile, ios::in);
    input_file.seekg(0);
}
void TakeInput(){
    while(!input_file.eof())
    {
        int k = 0;
        char ch;
        input_file.get(ch);

        if(ch != ' ' || ch != '\n')
        {
            switch(k)
            {
            case 0 :
                R = ch;
                k++;
                break;
            case 1 :
                C = ch;
                k++;
                break;
            case 2 :
                L = ch;
                k++;
                break;
            case 3 :
                H = ch;
                k++;
                break;
            default :
                P[i][j].Value = ch;
                P[i][j].Occupied=false;
                j++;
                if(j == C)
                {
                    j = 0;
                    i++;
                }
                break;
            }
        }
    }
}
int IngrediantFinder(){//Work in progress, if the square piece doesnt satisfies, it will extending through columns first then through rows,if slice is satisfied return the number of slices
   int CountT=0;    //Counts the tomatoes
   int CountM=0;   //Count the Mushrooms
   int LoopR=2;
   int LoopC=2;
   int Serial=1;
   bool Swap=false;
   int slice=0;
   if(H>2){
    for(int m=0;i<LoopR;i++){
        for(int n=0;j<LoopC;j++){
                  P[m][n].Serial=Serial;
            if(P[m][n].Value=="T"){
                CountT++;
            }
            else if(P[m][n].Value=="T"){
                CountM++;
            }
        }
    }
            if(CountM<=L&&CountT<=L&&(CountM>=2||CountT>=2)){
               slice++;
               Serial++;
            }
            else if(Swap==false){
                if(LoopR<R){
                    LoopR++;
                    Swap=true;
                }
                else{
                    if(LoopC<C){
                        LoopC++;
                    }
                }
            }
            else if(Swap==true){
                if(LoopC<C){
                    LoopC++;
                    Swap=false;
                }
                  else{
                    if(LoopR<R){
                        LoopR++;
                    }
                }
            }

   }
}
