#include "Warlock.h"

Warlock::Warlock(int x, int y) : Monster(x, y)
{
    cur_hp = max_hp = 15;
    atk = 5, def = 1;
}

//write your code here

Warlock::~Warlock() {}

string Warlock::get_monster_str() const {
    char returner[6];

    sprintf(returner, "%02d", cur_hp);

    return "W" + string(returner);
}

int wHorizontal_Distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2);
}
int wVertical_Distance(int x1, int y1, int x2, int y2){
    return abs(y1 - y2);
}
int wTotal_Distance(int x1, int y1, int x2, int y2){
    return wHorizontal_Distance(x1, y1, x2, y2) + wVertical_Distance(x1, y1, x2, y2);
}
void Warlock::action(Player &p, MapUnit *map[][MAP_SIZE]) {
    int px, py;
    p.get_position(px, py);
    if (wTotal_Distance(x, y, px, py) <= 1) {
        p.attacked_by(atk);
    }
    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) { // center point
                continue;
            }
            else if (!((x + c >= 0 && x + c < MAP_SIZE) && (y + r >= 0 && y + r < MAP_SIZE))){   // out of bound
                continue;
            }
            else if (map[x+c][y+r] -> is_blocked()) {
                continue;
            }
            else if (px == x + c && py == y + r){
                continue;
            }

            delete map[x+c][y+r];

            map[x+c][y+r] = new Zombie(x+c, y+r);
        }
    }
}