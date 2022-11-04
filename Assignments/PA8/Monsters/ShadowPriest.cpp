#include "ShadowPriest.h"

ShadowPriest::ShadowPriest(int x, int y) : Monster(x, y)
{
    cur_hp = max_hp = 15;
    atk = 5, def = 2;
}

//write your code here

ShadowPriest::~ShadowPriest() {}

string ShadowPriest::get_monster_str() const {
    char returner[6];
    sprintf(returner, "%02d", cur_hp);
    return "S" + string(returner);
}


int sHorizontal_Distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2);
}
int sVertical_Distance(int x1, int y1, int x2, int y2){
    return abs(y1 - y2);
}
int sTotal_Distance(int x1, int y1, int x2, int y2){
    return sHorizontal_Distance(x1, y1, x2, y2) + sVertical_Distance(x1, y1, x2, y2);
}

void ShadowPriest::action(Player &p, MapUnit *map[][MAP_SIZE]) {
    int px, py;
    p.get_position(px, py);
    if (sTotal_Distance(x, y, px, py) <= 1) {
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
            else if (px == x + c && py == y + r){
                continue;
            }
            else if (map[x+c][y+r]->get_unit_type() != UnitType::MONSTER){   // no heal
                continue;
            }
 
            static_cast<Monster*>(map[x+c][y+r])->recover_hp(5);    // recover hp            
        }
    }
}