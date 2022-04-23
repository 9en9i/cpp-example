#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


void print_container(const vector<char>* array)
{
    cout << "[";
    for (auto index = 0; index < array->size(); index++)
    {
        cout << "'" << (*array)[index] << "'";
        if (index != array->size() - 1)
        {
           cout << ", ";
        }
    }
    cout << "]";
    cout << endl;
}

int main()
{
    cout << "enter symbols ('?' - stop):\n";
    auto array = new vector<char>();
    char temp_symbol;
    while (true)
    {
        cin >> temp_symbol;
        if (temp_symbol == '?')
        {
            break;
        }
        array->push_back(temp_symbol);
    }
    auto matrix = new vector<vector<char>*>
    {
        new vector<char>(),
        new vector<char>(),
        new vector<char>(),
    };

    int current_line = 0;

    for (auto i : *array)
    {
        (*matrix)[current_line]->push_back(i);
        current_line++;

        if (current_line == 3)
        {
            current_line = 0;
        }
    }
    cout << "result:\n";
    for (auto index = 0; index < 3; index++)
    {
        print_container((*matrix)[index]);
    }
}

