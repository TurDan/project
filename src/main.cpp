#include <iostream>
#include <string>
#include <ctime>
#include <functionDeclaration.hpp>
using namespace std;


const int SIZE = 6;

int main()
{
    bool game = true;
    while(game)
    {
        int userInput[SIZE] = {};
        int winningNumbers[SIZE] = {};

        cout << "Wprowadz szesc liczb, by zagrac w Duzego Lotka!, wpisz dowolną literę lub 0 - aby zakończyć" << endl;
        
        // czytanie danych
        game = getUserInput(userInput);

        if (game)
        {
            // losowanie liczb
            getWinningNumbers(winningNumbers);

            //wyswietlanie danych
            cout << "Twoje liczby:" << endl;
            printNumbers(userInput);
            cout << "Wylosowane liczby:" << endl;
            printNumbers(winningNumbers);
            printScore(winningNumbers,userInput);
        }
        else
        {
            cout << "Do widzenia!\n";
        }
    }

    return 0;
}
