#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std::chrono_literals;
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


const int tabsize = 12;    //Wielkość tablicy
int Tab1[tabsize][tabsize];   //Tablica docelowa (tu jest to co powinno się wyświetlać)
int Tab2[tabsize][tabsize];   //Tablica do obliczania (tu jest obliczana nowa generacja)
int adjacent= 0;             //sąsiedzi komórki 
int percentspawn = 25;       //percentspawn na to że komórka jest żywa na starcie
int zero = 0;

void obliczanie()
{
    for (int i = 1; i < tabsize - 1; i++)   //wyświetlanie tablicy 1
    {
        for (int j = 1; j < tabsize - 1; j++)
        {
            adjacent= Tab1[j - 1][i - 1] + Tab1[j - 1][i] + Tab1[j - 1][i + 1] + Tab1[j][i - 1] + Tab1[j][i + 1] + Tab1[j + 1][i - 1] + Tab1[j + 1][i] + Tab1[j + 1][i + 1];

            if (Tab1[j][i] == 1)
            {
                cout << "\033[7;10m";
                if (adjacent== 2 or adjacent== 3)
                    Tab2[j][i] = 1;
                else
                    Tab2[j][i] = 0;
            }
            else
            {
                if (adjacent== 3)
                    Tab2[j][i] = 1;
                else
                    Tab2[j][i] = 0;
            }




            cout << "x " << "\033[0m";



        }
        cout << endl;
    }
    cout << endl;





    for (int i = 1; i < tabsize - 1; i++)
    {
        for (int j = 1; j < tabsize - 1; j++)
        {


            if (j == 0 or i == 0 or j == tabsize - 1 or i == tabsize - 1)
            {
                Tab1[j][i] = 0;
            }
            else
            {
                Tab1[j][i] = Tab2[j][i];
            }




        }
    }



    sleep_for(2s);
    cout << "\033[2J";
    obliczanie();


}







int main()
{
    srand(time(0));

    for (int i = 0; i < tabsize; i++)
    {
        for (int j = 0; j < tabsize; j++)
        {
            int los = rand() % 100;

            if (los < percentspawn)
            {
                Tab1[j][i] = 1;
            }
            else
            {
                Tab1[j][i] = 0;
            }

            if (j == 0 or i == 0 or j == tabsize - 1 or i == tabsize - 1)
            {
                Tab1[j][i] = 0;
            }


        }
    }





    obliczanie();


}


