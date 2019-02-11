#include <iostream>
#include<fstream>

using namespace std;

unsigned int R;                         //Number of rows
unsigned int C;                        //Number of columns
unsigned int L;                         //Minimum number of ingredients
unsigned int H;                        //Maximum number of cells in the slice

int Pizza[1000][1000];             //Legendary Pizza
int i, j;                                          //Loop Variables

char filename[10];

fstream input_file;


int main()
{
    cout<<"Welcome to our master Pizza code !!\n";
    cout<<"\nLet's create the Pizza first :p ";
    cout<<"\nTell me the input file name : ";
    cin>>filename;

    input_file.open(filename, ios::in);
    input_file.seekg(0);

    return 0;
}
