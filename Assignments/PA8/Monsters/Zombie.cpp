#include "Zombie.h"

Zombie::Zombie(int x, int y) : Monster(x, y)
{
    cur_hp = max_hp = 20;
    atk = 9, def = 3;
}

//write your code here
Zombie::~Zombie() {}

string Zombie::get_monster_str() const {
    char returner[6];
    
    sprintf(returner, "%02d", cur_hp);  // print with format

    return "Z" + string(returner);
    // ref: https://stackoverflow.com/questions/15106102/how-to-use-c-stdostream-with-printf-like-formatting
}

int zHorizontal_Distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2);
}
int zVertical_Distance(int x1, int y1, int x2, int y2){
    return abs(y1 - y2);
}
int zTotal_Distance(int x1, int y1, int x2, int y2){
    return zHorizontal_Distance(x1, y1, x2, y2) + zVertical_Distance(x1, y1, x2, y2);
}

void Zombie::action(Player &p, MapUnit *map[][MAP_SIZE]) {
    int px, py;
    p.get_position(px, py);
    
    if (zTotal_Distance(x, y, px, py) <= 1) {
        p.attacked_by(atk);
    }
}
