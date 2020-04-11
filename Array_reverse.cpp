/* Array reverse - program, który wczytuje z wejścia ciąg liczb i wypisuje go w odwróconej kolejności.
Wejście - wprowadzona zostanie pewna nieokreślona, ale niewielka ilość liczb całkowitych rozdzielonych spacjami.
Na wyjściu ma się pojawić ciag liczbowy, którego i - ta pozycja jest równa(n + 1 - i) - tej liczbie wczytanej z wejścia, gdzie n to ilość wczytanych liczb. Poszczególne liczby należy rozdzielić spacjami.

Input:      1 2 3

Output:     3 2 1 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> Array;

    string input;

    getline(cin, input);

    while (input.find(' ') != string::npos && input.length() > 0)           //Jezeli spacja ' ' jest w string input i string input nie jest pusty.
    {
        if (input[0] != ' ')
        {
            Array.push_back(stoi(input.substr(0, input.find(' '))));        //stoi -> string to int.

            input.erase(0, input.find(' ') + 1);
        }

        else                                                                //Spacja ' ' jest na input[0] -> input = " 12" || input = " ".
        {
            input.erase(0, input.find(' ') + 1);
        }
    }

    if (input.find(' ') == string::npos && input.length() > 0)              //Jezeli nie ma spacja ' ' w string input i string input nie jest pusty -> input = "12".
    {
        Array.push_back(stoi(input));
    }

    reverse(Array.begin(), Array.end());

    for (size_t i : Array)
    {
        cout << i << " ";
    }

    system("PAUSE");

    return 0;
}