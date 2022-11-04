#include "Monster.h"
#include <cmath>

// write your code here
Monster::Monster(int x, int y):MapUnit(x, y) {
}

Monster::~Monster() {}

bool Monster::is_active() const {
    return active;
}

void Monster::set_active() {
    if (is_valid()) {
        active = true;
    }
}

void Monster::recover_hp(int hp) {
    cur_hp += hp;
    if (cur_hp > max_hp){
        cur_hp = max_hp;
    }
}

UnitType Monster::get_unit_type() const {
    return UnitType::MONSTER;
}

bool Monster::is_blocked() const {
    return is_valid();
}

int Monster::attacked_by(int atk_) {
    if (is_valid()) {
        int damage = atk_ - def;
        if (damage < 0) {
            return 0;
        }
        else{
            cur_hp -= damage;
        }
        if (cur_hp <= 0) {
            invalidate();
            active = false;
            return 1;
        } 
        else {
            return 0;
        }
    } 
    else {
        return 0;
    }
}

string Monster::get_display_str() const {
    if (is_valid()) {
        if (!is_discovered()) {
            return SYM_DANGER;
        } 
        else {
            return get_monster_str();
        }
    } 
    else {
        return SYM_EMPTY;
    }
}

int mHorizontal_Distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2);
}
int mVertical_Distance(int x1, int y1, int x2, int y2){
    return abs(y1 - y2);
}
int mTotal_Distance(int x1, int y1, int x2, int y2){
    return mHorizontal_Distance(x1, y1, x2, y2) + mVertical_Distance(x1, y1, x2, y2);
}
int mDirection_Check(int a){
    if(a > 0){
        return 1;
    }
    else{
        return -1;
    }
}

void Monster::follow(const Player &p, MapUnit *map[][MAP_SIZE]) {
    int px, py;
    int monster_next_x, monster_next_y;
    bool blocked = true;    // record whether is blocked or not, blocked -> return
    p.get_position(px, py);
    if (mTotal_Distance(x, y, px, py) == 1) {
        return;
    }
    monster_next_x = x + mDirection_Check(px - x); 
    monster_next_y = y;
    if (mHorizontal_Distance(x, y, px, py) > 0  && monster_next_x >= 0 && monster_next_x < MAP_SIZE && !map[monster_next_x][monster_next_y]->is_blocked()) {
        blocked = false;
        // can go horizontally
    } 
    else {
        monster_next_x = x; // change monster_next_x back
        monster_next_y = y + mDirection_Check(py - y); 
        if (mVertical_Distance(x, y, px, py) > 0 && monster_next_y >= 0 && monster_next_y < MAP_SIZE && !map[monster_next_x][monster_next_y]->is_blocked()) { 
            blocked = false;
        }
    }
    if (blocked) {
        return;
    }

    delete map[monster_next_x][monster_next_y];
    map[monster_next_x][monster_next_y] = this; // need?

    map[x][y] = new EmptyLand(x, y);
    x = monster_next_x; 
    y = monster_next_y;    
}