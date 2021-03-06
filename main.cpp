//main.cpp
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

void printTable(HashTable<float, int> &table)
{
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		cout << **it << " ";
	}
	cout << endl;
}

int main()
{
    setlocale(LC_CTYPE, "ru-RU");
    cout << "����: " << endl;
    cout << "  0 - �����" << endl;
    cout << "  1 - ������ �������" << endl;
    cout << "  2 - ���������� ���������" << endl;
    cout << "  3 - ���������� ������ ���������" << endl;
    cout << "  4 - �������� ����� �������" << endl;
    cout << "  5 - ������� �������" << endl;
    cout << "  6 - ����� �������" << endl;
	cout << "  7 - ���������� ����" << endl;
	cout << "  8 - ������� ��������� �������" << endl;
	cout << "  9 - ������� �������" << endl;
	cout << " 10 - ������� �������" << endl;
	cout << " 11 - ��������� ������� ��������� �������" << endl;
	cout << " 12 - ��������� ������" << endl;
	cout << " 13 - �������� ++" << endl;
	cout << " 14 - �������� �������� ����� ��������" << endl << endl;

    HashTable<float, int> table(20);
    float key;
	int value, command;
	HashTable<float, int>::iterator it;
	//auto it = table.begin();
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
				cout << "�������. ������� ���� [-10000.00, 10000.00]: ";
                cin >> key;
				cout << "������� �������� (int): ";
				cin >> value;
                cout << table.insert(key, value) << endl;
                break;
            case 5:
                cout << "��������. ������� ���� [-10000.00, 10000.00]: ";
                cin >> key;
                cout << table.remove(key) << endl;
                break;
            case 6:
                cout << "�����. ������� ���� [-10000.00, 10000.00]: ";
                cin >> key;
                cout << (table.search(key, value) ? to_string(value) : "������� �� ������") << endl;
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
			case 12:
				try 
				{
					it = table.begin();
					cout << **it << endl;
				}
				catch (int e)
				{
					if (e == HashTable<float, int>::ERROR_EMPTY_TABLE)
					{
						cout << "������: ������� ������" << endl;
					}
				}
				break;
			case 13:
				try 
				{
					++it;
					cout << **it << endl;
				}
				catch (int e)
				{
					if (e == HashTable<float, int>::ERROR_INCREMENT)
					{
						cout << "������: ������ ����������������" << endl;
					}
					else if (e == HashTable<float, int>::ERROR_GET_VALUE)
					{
						cout << "������: ��������� ��������" << endl;
					}
				}
				break;
			case 14:
				cout << "��������� �������� �� ���������. ������� ����� ��������: ";
				cin >> value;
				try
				{
					**it = value;
					cout << **it << endl;
				}
				catch (int e)
				{
					if (e == HashTable<float, int>::ERROR_GET_VALUE)
					{
						cout << "������: ��������� ��������" << endl;
					}
				}
				break;
            case 0:
                return 0;
            default:
                cout << "������� �� �������";
        }
    }
}