#include "string_processing.h"
#include "hero.h"
#include "game_map.h"
#include "stack.h"
#include "fight.h"
#include "monsters.h"
#include "buy.h"
#include "draw.h"
#include <string>
#include "C:\Temp\glut-3.7.6-bin\glut.h"

enum file_monsters { empty_cell = 0, unbreakable = 1, breakable = 2, heep_gold = 3, _ogre = 4, _skeleton = 5, _ghost = 6, _dragon = 7, _traeder = 8 };

//запоминание хода(нужно запоминать и соседние так, как можем их разрушить)
void push_stack_turn(Game_map& map, stack<Hero_and_map>& stack_turn, Hero& help, Hero& user) {
	Hero_and_map stack_el;
	int help_el[5];
	help_el[0] = map.get_cell(help.get_x(), help.get_y());
	help_el[1] = map.get_cell(help.get_x() + 1, help.get_y());
	help_el[2] = map.get_cell(help.get_x(), help.get_y() + 1);
	help_el[3] = map.get_cell(help.get_x() - 1, help.get_y());
	help_el[4] = map.get_cell(help.get_x(), help.get_y() - 1);
	stack_el.set(help, help_el, map.visited(user.get_x(), user.get_y()));
	stack_turn.push(stack_el);
}

//процедура обрабатывающая строку и делающая соответсв ход игрока
void string_processing(Hero& user, Game_map& map, stack<Hero_and_map>& stack_turn) {
	//если в клетке есть кто-то то включаем либо бой, либо фазу покупки
	switch (map.get_cell(user.get_x(), user.get_y())) {
	case(_ogre): {
		ogre ovbor;
		fight(user, ovbor, 4);
		map.murder_monster(user, 4);
		draw_walk(user, map);
		draw_mini_map(user, map, 0, 804);
		break;
	}
	case(_skeleton): {
		skeleton ovbor;
		fight(user, ovbor, 5);
		map.murder_monster(user, 5);
		draw_walk(user, map);
		draw_mini_map(user, map, 0, 804);
		break;
	}
	case(_ghost): {
		ghost ovbor;
		fight(user, ovbor, 6);
		map.murder_monster(user, 6);
		draw_walk(user, map);
		draw_mini_map(user, map, 0, 804);
		break;
	}
	case(_dragon): {
		dragon ovbor;
		fight(user, ovbor, 7);
		map.murder_monster(user, 7);
		draw_walk(user, map);
		draw_mini_map(user, map, 0, 804);
		break;
	}
	case(_traeder): {
		buy(user);
		break;
	}
	}
	//после обработки клетки могли персонаж мог умереть, поэтому говорим об этом пользователю
	if (user.check_died())
		cout << "Вы умерли. Для того, чтобы отмотать ход используйте remove";
	string s;
	while (cin >> s) {
		//если умер то ограничиваем возможности(чтобы не было ходячего трупа)
		if (!user.check_died()) {
			//ходьба
			if (s == "step") {
				while (cin >> s) {
					if (s == "forward" || s == "left" || s == "right" || s == "back") {
						Hero help = user;
						if (s == "forward")
							user.call_step_f();
						if (s == "left")
							user.call_step_l();
						if (s == "right")
							user.call_step_r();
						if (s == "back")
							user.call_step_b();
						int x = user.get_x(), y = user.get_y();
						if (map.get_cell(x, y) == unbreakable || map.get_cell(x, y) == breakable) {
							user = help;
							return;
						}
						//запоминание хода
						push_stack_turn(map, stack_turn, help, user);
						map.mark_visited_cell(x, y);
						return;
					}
				}
			}
			//повороты
			if (s == "turn") {
				while (cin >> s) {
					if (s == "right") {
						user.turn_right();
						draw_walk(user, map);
						draw_mini_map(user, map, 0, 804);

						break;
					}
					if (s == "left") {
						user.turn_left();
						draw_walk(user, map);
						draw_mini_map(user, map, 0, 804);

						break;
					}
				}
			}
			//использование зелий здоровья
			if (s == "use") {
				while (cin >> s) {
					if (s == "potion") {
						if (user.healing_poison() == 0)
							cout << "Зелья кончились" << endl;
						draw_walk(user, map);
						draw_mini_map(user, map, 0, 804);

						break;
					}
				}
			}
			//показ характеристик, что надето и что в рюкзаке
			if (s == "show") {
				while (cin >> s) {
					if (s == "stats") {
						user.show_characteristics();
						draw_walk(user, map);
						draw_mini_map(user, map, 0, 804);

						break;
					}
					if (s == "weared") {
						user.show_wear_art();
						draw_walk(user, map);
						draw_mini_map(user, map, 0, 804);

						break;
					}
					if (s == "unweared") {
						user.show_un_wear_art();
						draw_walk(user, map);
						draw_mini_map(user, map, 0, 804);

						break;
					}
				}
			}
			//уничтожить стену перед собой, если можем
			if (s == "break") {
				map.cut_tree(user);
				draw_walk(user, map);
				draw_mini_map(user, map, 0, 804);

				break;
			}
			//надеть на себя артефакт
			if (s == "wear") {
				cin >> s;
				if (!user.wear_art(s))
					cout << "У вас нет такого артифакта.";
			}
			//снятие с себя артефакта
			if (s == "unwear") {
				cin >> s;
				if (!user.un_wear_art(s))
					cout << "У вас нет такого артифакта.";
			}
		}
		//отматывает на ход назад
		if (s == "remove" && stack_turn.size() != 0) {
			Hero_and_map help, g1;
			stack_turn.front(help);
			stack_turn.pop(g1);
			map.set_cell(help.user.get_x(), help.user.get_y(), help.mark[0]);
			map.set_cell(help.user.get_x() + 1, help.user.get_y(), help.mark[1]);
			map.set_cell(help.user.get_x(), help.user.get_y() + 1, help.mark[2]);
			map.set_cell(help.user.get_x() - 1, help.user.get_y(), help.mark[3]);
			map.set_cell(help.user.get_x(), help.user.get_y() - 1, help.mark[4]);
			map.set_visit(user.get_x(), user.get_y(), help.visited);
			user = help.user;
			return;
		}
	}

}

