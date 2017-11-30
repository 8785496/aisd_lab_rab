//main.cpp
#include <iostream>
#include "HashTable.h"

using namespace std;

void printTable(HashTable<float> &table)
{
	for (auto item : table)
	{
		cout << item << " ";
	}
	cout << endl;
}

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
	cout << "  7 - количество проб" << endl;
	cout << "  8 - вывести структуру таблицы" << endl;
	cout << "  9 - вывести таблицу" << endl;
	cout << " 10 - очистка таблицы" << endl << endl;

    HashTable<float> table(3);
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
				break;
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
                cout << (table.search(f) ? "Элемент найден" : "Элемент не найден") << endl;
                break;
			case 7:
				cout << table.getCountIteration() << endl;
				break;
			case 8:
				table.print();
				break;
			case 9:
				printTable(table);
				break;
			case 10:
				table.clear();
				break;
            case 0:
                return 0;
            default:
                cout << "Команда не найдена";
        }
    }
}