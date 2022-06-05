#include "string_processing.h"
#include "hero.h"
#include "game_map.h"
#include "stack.h"
#include "fight.h"
#include "monsters.h"
#include <string>
enum file_monsters { empty_cell = 0, unbreakable = 1, breakable = 2, heep_gold = 3, _ogre = 4, _skeleton = 5, _ghost = 6, _dragon = 7, _traeder = 8 };
void string_processing(Hero& user, Game_map& map, stack<Hero_and_mark>& stack_turn) {
	string s;
	switch (map.get_cell(user.get_x(), user.get_y())) {
	case(_ogre): {
		ogre ovbor;
		fight(user, ovbor);
		break;
	}
	case(_skeleton): {
		skeleton ovbor;
		fight(user, ovbor); break;
	}
	case(_ghost): {
		ghost ovbor;
		fight(user, ovbor);
		break;
	}
	case(_dragon): {
		dragon ovbor;
		fight(user, ovbor);
		break;
	}
				 //	case(_traeder): {}

	}
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

