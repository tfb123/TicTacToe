#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

using namespace std;

const char Xsign='X';
const char Osign='O';

void DisplayBoard(char arr[3][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << arr[i][j] << " |";
        }
        cout << endl << "_________" << endl;
    }
}

bool PlaceSign(char mas[3][3], int x, int y, bool& player)
{
    //if cell is free
    if (mas[y-1][x-1]==0)
    {
        if (player)
            mas[y-1][x-1]=Osign;
        else
            mas[y-1][x-1]=Xsign;
        //change player
        player=!player;
        return true;
    }
    return false;
}

bool checkwin (char mas[3][3])
{
    bool winner = false;
    //check lines
    for (int i=0; i<3; i++)
    {
        winner = false;
        for (int j=1; j<3; j++)
        {
            if (mas[i][0]==mas[i][j] && mas[i][0]!=0 &&
                mas[i][1]!=0 && mas[i][2]!=0)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
            if (winner)
                return true;
        }
    }
    //check columns
    for (int i=0; i<3; i++)
    {
        winner = false;
        for (int j=1; j<3; j++)
        {
            if (mas[i][0]==mas[j][i] && mas[i][0]!=0 &&
                mas[i][1]!=0 && mas[i][2]!=0)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
            if (winner)
                return true;
        }
    }

    if (mas[0][0]==mas[1][1] && mas[0][0]==mas[2][2] &&
        mas[0][0]!=0 && mas[1][1]!=0 && mas[2][2]!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
    if (mas[0][2]==mas[1][1] && mas[2][0]==mas[2][2] &&
        mas[0][2]!=0 && mas[1][1]!=0 && mas[2][0]!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}



int main()
{

    char mas[3][3] = {0};
    bool player = false;//false =>X; true => O;
    int x=4;
    int y=4;
    bool win = false;
    while (!win)
    {
        cout << "TicTacToe" << endl;
        x=4;
        y=4;
        DisplayBoard(mas);
        if (player)
        {
            system("color 03");
            cout << "O zaidejo eile:\n";
        }
        else
        {
            system("color 04");
            cout << "X zaidejo eile:\n";
        }
        while (x>3)
        {
            cout << "Pasirinkite X koord: ";
            cin >> x;
        }
        while (y>3)
        {
            cout << "Pasirinkite Y koord: ";
            cin >> y;
        }
        PlaceSign(mas,x,y,player);
        win = checkwin(mas);
        system("cls");
    }
    if (player)
    {
        cout << "Player X wins\n";
    }
    else
    {
        cout << "Player O wins\n";
    }
    //check



    return 0;
}
