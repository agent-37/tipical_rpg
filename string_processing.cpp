#include "string_processing.h"
#include "hero.h"
#include "game_map.h"
#include "stack.h"
#include <string>
enum file_monsters { empty_cell = 0, unbreakable = 1, breakable = 2, heep_gold = 3, ogre = 4, skeleton = 5, ghost = 6, dragon = 7, traeder = 8 };
void string_processing(Hero& user, Game_map& map, stack<Hero_and_mark>& stack_turn) {
	string s;
	while (cin >> s) {
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
					Hero_and_mark stack_el;
					stack_el.set(help, map.get_cell(help.get_x(), help.get_y()), map.visited(help.get_x(), help.get_y()));
					stack_turn.push(stack_el);
					map.mark_visited_cell(x, y);
					//НАДО ЗДЕСЬ сделать проверку на начало боя
					return;
				}
			}
		}
		if (s == "turn") {
			while (cin >> s) {
				if (s == "right") {
					user.turn_right();
					return;
				}
				if (s == "left") {
					user.turn_left();
					return;
				}
			}

		}
	}

}

