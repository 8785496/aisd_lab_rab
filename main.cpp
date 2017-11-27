#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "ru-RU");
    cout << "Меню: " << endl;
    cout << "  0 - выход" << endl;
    cout << "  1 - размер таблицы" << endl;
    cout << "  2 - количество элементов" << endl;
    cout << "  3 - количество пустых элементов" << endl;
    cout << "  4 - добавить новый элемент" << endl;
    cout << "  5 - удалить элемент" << endl;
    cout << "  6 - найти элемент" << endl;
    cout << "  7 - количество проб" << endl << endl;

    HashTable<float> table(10);

	auto it = table.begin();
	auto res = *it;
	cout << res << endl;

	int a;
	cin >> a;
	return 0;

    while (true)
    {
        cout << "Введите команду: ";
        int command;
        cin >> command;
        float f;
        switch (command)
        {
            case 1:
                cout << table.getSize() << endl;
                break;
            case 2:
                cout << table.getCount() << endl;
                break;
            case 3:
                cout << table.getFree() << endl;
            case 4:
                cout << "Вставка. Введите число в диапазоне -10000..10000" << endl;
                cin >> f;
                table.insert(f);
                break;
            case 5:
                cout << "Удаление. Введите число в диапазоне -10000.0 - 10000" << endl;
                cin >> f;
                table.del(f);
                break;
            case 6:
                cout << "Поиск. Введите число в диапазоне -10000..10000" << endl;
                cin >> f;
                table.del(f);
                break;
            case 0:
                return 0;
            default:
                cout << "Команда не найдена";
        }
    }
}