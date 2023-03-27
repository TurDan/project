#include <functionDeclatation.hpp>

//Funkcja sprawdzająca input od użytkownika
bool getUserInput(int* userInput)
{
    for (int i = 0; i < SIZE; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
        {
            return false;
        }
    
        if(tmp<1 || tmp>49){
            cout<<"Podaj liczbę w zakresie 1-49"<<endl;
           i--;
            continue;
        }
        

        if (checkDuplicates(tmp, userInput))
        {
            cout << "Tę liczbę już podałeś/aś, proszę podaj inną" << endl;
           i--;
            continue;
        }
        else
        {
            userInput[i] = tmp;
        }
    }

    return true;
}
//Funkcja generująca niepowtarzalne liczby z zakresu 1-49
void getWinningNumbers(int* winningNumbers)
{
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        int tmp = (rand() % 49) + 1;

        while (checkDuplicates(tmp, winningNumbers))
        {
            tmp = (rand() % 49) + 1;
        }

        winningNumbers[i] = tmp;
    }
}
// Funkcja pomocznicza do wyświetlania tablic
void printNumbers(int* numbers)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
//Funkcja pomocnicza do wyszukiwania duplikatów
bool checkDuplicates(int n, int* numbers)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (n == numbers[i])
        {
            return true;
        }
    }

    return false;
}


//Porównanie liczb z tablic i wyświetlenie wyniku gry:
void printScore(int* winningNumbers, int* userInput){
    int matchCount = 0;
    for (int i = 0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++){
            if(userInput[i]==winningNumbers[j]){
                matchCount++;
            }
        }
    }
    if(matchCount<2){
        cout<<"Przegrana. Spróbuj jeszcze raz!"<< endl;
    }
    if (matchCount==2){
        cout<< "Wygrałeś/aś 2 zł"<< endl;
    }
    else if(matchCount==3){
        cout<< "Wygrałeś/aś 500 zł"<< endl;

    }
    else if(matchCount==4){
        cout<< "Wygrałeś/aś 20 000 zł"<< endl;

    }
    else if(matchCount==5){
        cout<< "Wygrałeś/aś 250 000 zł"<< endl;

    }
    else if(matchCount==6){
        cout<< "GŁÓWNA WYGRANA! Wygrałeś/aś 1 000 000 zł!” "<< endl;

    }
}