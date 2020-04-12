/* Array row and column reverse - program, który wczytuje z wejścia ciąg liczb i wypisuje go w odwróconej kolejności.
Wejście - wprowadzona zostanie pewna nieokreślona, ale niewielka ilość liczb całkowitych rozdzielonych spacjami. Zestawy zostaną rozdzielone znakiem nowej linii.

Input:      10 15 20 25 30
            35 40 45 50 55
            60 65 70 75 80
            85 90 95 100 105

Output:     30 25 20 15 10
            55 50 45 40 35
            80 75 70 65 60
            105 100 95 90 85 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> ArrayRowColumn;

    string input;

    getline(cin, input);

    do
    {
        vector<int> ArrayColumn;

        while (input.find(' ') != string::npos && input.length() > 0)           //Jezeli spacja ' ' jest w string input i string input nie jest pusty.
        {
            if (input[0] != ' ')
            {
                ArrayColumn.push_back(stoi(input.substr(0, input.find(' '))));  //stoi -> string to int.

                input.erase(0, input.find(' ') + 1);
            }

            else                                                                //Spacja ' ' jest na input[0] -> input = " 12" || input = " ".
            {
                input.erase(0, input.find(' ') + 1);
            }
        }

        if (input.find(' ') == string::npos && input.length() > 0)              //Jezeli nie ma spacja ' ' w string input i string input nie jest pusty -> input = "12".
        {
            ArrayColumn.push_back(stoi(input));
        }

        ArrayRowColumn.push_back(ArrayColumn);

        getline(cin, input);

    } while (input.length() > 0);

    for (size_t row = 0; row < ArrayRowColumn.size(); row++)
    {
        reverse(ArrayRowColumn[row].begin(), ArrayRowColumn[row].end());

        for (auto column : ArrayRowColumn[row])
        {
            cout << column << " ";
        }

        cout << endl;
    }

    return 0;
}