
#include "buy.h"
#include "trader.h"	

void buy(Hero& user) {
	cout << "Приветствуяю тебя путник. Купи мои товары, если хочешь." << endl;
	Trader tr;
	tr.fill_inventory_trader();

	string s;
	tr.show_inventory_trader();
	cout << "healing_potion " << 5 << endl;
	while (cin >> s) {

		if (s == "buy") {
			cout << "Что-бы ты хотел купить?" << endl;
			while (cin >> s) {
				if (s == "healing_potion") {
					if (user.get_gold() >= 5)
					{
						cout << "Держи склянку" << endl;
						user.set_gold(user.get_gold() - 5);
						user.add_potion();
					}
					else {
						cout << "Тебе это не по карману" << endl;
					}
					break;
				}
				else
					if (tr.trade_inventory(s, user) == 0)
						cout << "У меня нет такого товара" << endl;
					else {
						if (tr.trade_inventory(s, user) == 1) {}
						cout << "Хороший выбор" << endl;
						if (tr.trade_inventory(s, user) == 2)
							cout << "Тебе это не по карману" << endl;
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
	cout << "Удачи тебе путник" << endl;

}