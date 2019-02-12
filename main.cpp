#include <iostream>
#include<fstream>

using namespace std;

unsigned int R;                         //Number of rows
unsigned int C;                        //Number of columns
unsigned int L;                         //Minimum number of ingredients
unsigned int H;                        //Maximum number of cells in the slice

char Pizza[1000][1000];         //Legendary Pizza
int i, j;                                          //Loop Variables

char filename[10];                 //filename of the input file

fstream input_file;                 //input_file filestream object


int main()
{
    cout<<"Welcome to our master Pizza code !!\n";
    cout<<"\nLet's create the Pizza first :p ";
    cout<<"\nTell me the input file name : ";
    cin>>filename;

    input_file.open(filename, ios::in);
    input_file.seekg(0);

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
                Pizza[i][j] = ch;
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

    return 0;
}
