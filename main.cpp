#include <iostream>
#include "HashTable.h"

using namespace std;

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
    cout << "  7 - ���������� ����" << endl << endl;

    HashTable<float> table(10);

	auto it = table.begin();
	auto res = *it;
	cout << res << endl;

	int a;
	cin >> a;
	return 0;

    while (true)
    {
        cout << "������� �������: ";
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
                cout << "�������. ������� ����� � ��������� -10000..10000" << endl;
                cin >> f;
                table.insert(f);
                break;
            case 5:
                cout << "��������. ������� ����� � ��������� -10000.0 - 10000" << endl;
                cin >> f;
                table.del(f);
                break;
            case 6:
                cout << "�����. ������� ����� � ��������� -10000..10000" << endl;
                cin >> f;
                table.del(f);
                break;
            case 0:
                return 0;
            default:
                cout << "������� �� �������";
        }
    }
}