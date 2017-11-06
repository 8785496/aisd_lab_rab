#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "ru-RU");
    cout << "ћеню: " << endl;
    cout << "  0 - выход" << endl;
    cout << "  1 - ?" << endl << endl;

    while (true)
    {
        cout << "¬ведите команду:" << endl;
        int command;
        cin >> command;
        switch (command)
        {
            case 1:
                // TODO
                cout << "Command 1" << endl;
                break;
            case 0:
                return 0;
        }
    }
}