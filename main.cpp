//main.cpp
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

void printTable(HashTable<float, int> &table)
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
	cout << " 10 - очистка таблицы" << endl;
	cout << " 11 - заполнить таблицу тестовыми данными" << endl << endl;

    HashTable<float, int> table(10);
    float key;
	int value, command;
    while (true)
    {
        cout << ">> ";
        cin >> command;
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
				cout << "Вставка. Введите ключ [-10000.00, 10000.00]: ";
                cin >> key;
				cout << "Введите значение (int): ";
				cin >> value;
                cout << table.insert(key, value) << endl;
                break;
            case 5:
                cout << "Удаление. Введите ключ [-10000.00, 10000.00]: ";
                cin >> key;
                cout << table.remove(key) << endl;
                break;
            case 6:
                cout << "Поиск. Введите ключ [-10000.00, 10000.00]: ";
                cin >> key;
                cout << (table.search(key, value) ? to_string(value) : "Элемент не найден") << endl;
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
			case 11:
				table.insert(1.0f, 1);
				table.insert(2.0f, 2);
				table.insert(3.0f, 3);
				break;
            case 0:
                return 0;
            default:
                cout << "Команда не найдена";
        }
    }
}