
#include "buy.h"
#include "trader.h"	

void buy(Hero& user) {
	cout << "������������ ���� ������. ���� ��� ������, ���� ������." << endl;
	Trader tr;
	tr.fill_inventory_trader();

	string s;
	tr.show_inventory_trader();
	cout << "healing_potion " << 5 << endl;
	while (cin >> s) {

		if (s == "buy") {
			cout << "���-�� �� ����� ������?" << endl;
			while (cin >> s) {
				if (s == "healing_potion") {
					if (user.get_gold() >= 5)
					{
						cout << "����� �������" << endl;
						user.set_gold(user.get_gold() - 5);
						user.add_potion();
					}
					else {
						cout << "���� ��� �� �� �������" << endl;
					}
					break;
				}
				else
					if (tr.trade_inventory(s, user) == 0)
						cout << "� ���� ��� ������ ������" << endl;
					else {
						if (tr.trade_inventory(s, user) == 1) {}
						cout << "������� �����" << endl;
						if (tr.trade_inventory(s, user) == 2)
							cout << "���� ��� �� �� �������" << endl;
						break;
					}

			}
			tr.show_inventory_trader();
			cout << "healing potion " << 5 << endl;
		}

		if (s == "exit") {
			break;
		}
	}
	cout << "����� ���� ������" << endl;

}