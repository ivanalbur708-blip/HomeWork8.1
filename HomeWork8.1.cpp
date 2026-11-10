
#include <iostream>
using namespace std;

int MyStrLen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

void DeleteAt(char* str, int index)
{
    int length = MyStrLen(str);

    if (index < 0 || index >= length)
        return;

    for (int i = index; i < length; i++)
        str[i] = str[i + 1];
}

void DeleteAll(char* str, char symbol)
{
    int writeIndex = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != symbol)
            str[writeIndex++] = str[i];
    }

    str[writeIndex] = '\0';
}

void InsertAt(char* str, int capacity, int index, char symbol)
{
    int length = MyStrLen(str);

    if (index < 0 || index > length || length >= capacity - 1)
        return;

    for (int i = length; i >= index; i--)
        str[i + 1] = str[i];

    str[index] = symbol;
}

void ReplaceDots(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
            str[i] = '!';
    }
}

int CountSymbol(const char* str, char symbol)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == symbol)
            count++;
    }

    return count;
}

int main()
{
    const int SIZE = 256;
    char str[SIZE];
    int index;
    char symbol;

    // Task 1
    cout << "Enter string: ";
    cin.getline(str, SIZE);

    cout << "Enter index to delete: ";
    cin >> index;
    cin.ignore(10000, '\n');

    DeleteAt(str, index);
    cout << "Result: " << str << '\n';

    // Task 2
    cout << "Enter string: ";
    cin.getline(str, SIZE);

    cout << "Enter symbol to delete: ";
    cin.get(symbol);
    cin.ignore(10000, '\n');

    DeleteAll(str, symbol);
    cout << "Result: " << str << '\n';

    // Task 3
    cout << "Enter string: ";
    cin.getline(str, SIZE);

    cout << "Enter index: ";
    cin >> index;
    cin.ignore(10000, '\n');

    cout << "Enter symbol: ";
    cin.get(symbol);
    cin.ignore(10000, '\n');

    InsertAt(str, SIZE, index, symbol);
    cout << "Result: " << str << '\n';

    // Task 4
    cout << "Enter string: ";
    cin.getline(str, SIZE);

    ReplaceDots(str);
    cout << "Result: " << str << '\n';

    // Task 5
    cout << "Enter string: ";
    cin.getline(str, SIZE);

    cout << "Enter symbol to count: ";
    cin.get(symbol);

    cout << "Count: " << CountSymbol(str, symbol) << '\n';
}
