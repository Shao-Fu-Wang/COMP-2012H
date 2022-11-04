#include "GameEngine.h"

using namespace std;

// Please do not change the following already implemented code

void GameEngine::print_active_monsters()
{
    int i = 0;
    cout << "Active Monsters:" << endl;
    MonsterNode *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data->get_display_str();
        cout << "@(" << cur->data->get_x();
        cout << "," << cur->data->get_y() << "), ";
        cur = cur->next;
        i++;
        if (i == 4)
        {
            i = 0;
            cout << endl;
        }
    }
}

bool GameEngine::player_win() const
{
    int px, py;
    player->get_position(px, py);
    if (px == MAP_SIZE - 1 && py == MAP_SIZE - 1)
    {
        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                if (map[i][j]->get_unit_type() == UnitType::MONSTER && map[i][j]->is_valid())
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

GameEngine::GameEngine()
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (i > 8 && i < 12 && j > 2 && j < 6)
                map[i][j] = new Wall(i, j);
            else if (i > 14 && i < 18 && j > 2 && j < 6)
                map[i][j] = new Grass(i, j);
            else if (i > 2 && i < 6 && j == 9)
                map[i][j] = new Gem(i, j, GemType::RUBY);
            else if (i > 2 && i < 6 && j == 10)
                map[i][j] = new Gem(i, j, GemType::EMERALD);
            else if (i > 2 && i < 6 && j == 11)
                map[i][j] = new Gem(i, j, GemType::SAPPHIRE);
            else if (i > 8 && i < 12 && j > 8 && j < 12)
                map[i][j] = new Book(i, j);
            else if (i > 14 && i < 18 && j > 8 && j < 12)
                map[i][j] = new Medicine(i, j);
            else if (i > 2 && i < 6 && j > 14 && j < 18)
                map[i][j] = new Zombie(i, j);
            else if (i > 8 && i < 12 && j > 14 && j < 18)
                map[i][j] = new Warlock(i, j);
            else if (i > 14 && i < 18 && j > 14 && j < 18)
                map[i][j] = new ShadowPriest(i, j);
            else
                map[i][j] = new EmptyLand(i, j);
        }
    }
}

char GameEngine::input()
{
    char c;
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    return c;
}

void GameEngine::run()
{
    string name;
    cout << "Please enter your name:" << endl;
    cin >> name;
    cout << "Please choose your role:" << endl;
    cout << "1 Warrior" << endl;
    cout << "2 Archer" << endl;
    cout << "3 Mage" << endl;

    int x = 0, y = 0;
    char role = input();
    switch (role)
    {
    case '1':
        create_player(x, y, name, Role::WARRIOR);
        break;
    case '2':
        create_player(x, y, name, Role::ARCHER);
        break;
    case '3':
        create_player(x, y, name, Role::MAGE);
        break;
    default:
        exit(0);
        break;
    }
    ui.refresh(this->map, *player);

    while (true)
    {
        switch (input())
        {
        case 'w':
            this->player_move(Direction::UP);
            break;
        case 'a':
            this->player_move(Direction::LEFT);
            break;
        case 's':
            this->player_move(Direction::DOWN);
            break;
        case 'd':
            this->player_move(Direction::RIGHT);
            break;
        case 'h':
            this->player_attack();
            break;
        case 'j':
            this->player_skill();
            break;
        default:
            break;
        }
        if (player_win())
        {
            cout << endl;
            cout << "You win." << endl;
            break;
        }
        player_discover();
        activate_monsters();
        monster_follow();
        monster_act();
        ui.refresh(this->map, *player);
        print_active_monsters();
        if (!player->is_alive())
        {
            cout << endl;
            cout << "You lose." << endl;
            break;
        }
    }
}


// write your code here

GameEngine::~GameEngine() { 
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            delete map[c][r];
        }
    }

    if (head != nullptr) {
        MonsterNode* thisNode = head;   
        MonsterNode* nextNode = thisNode->next;
        while (thisNode != nullptr) {
            delete thisNode;
            thisNode = nextNode;
            if (thisNode != nullptr) {
                nextNode = thisNode->next;
            }
        }
    }

    delete player;
}

void GameEngine::create_player(int x, int y, const string &name, Role role) {
    if(role == Role::ARCHER){
        player = new Archer(x, y, name);
    }
    else if(role == Role::MAGE){
        player = new Mage(x, y, name);
    }
    else if(role == Role::WARRIOR){
        player = new Warrior(x, y, name);
    }
}

void GameEngine::activate_monster(Monster *monster) {
    if (monster->is_valid() && !monster->is_active()) {
        monster->set_active();
        MonsterNode* newNode = new MonsterNode;
        newNode->next = nullptr;
        newNode->data = monster;
        if (head != nullptr) {
            MonsterNode* prevNode = nullptr;
            MonsterNode* currNode = head;

            while(currNode != nullptr){ // iter
                prevNode = currNode;
                currNode = prevNode->next;
                prevNode->next = newNode; 
            }
        } 
        else{       // nothing
            head = newNode;
        }
    }
}

int Horizontal_Distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2);
}
int Vertical_Distance(int x1, int y1, int x2, int y2){
    return abs(y1 - y2);
}
int Total_Distance(int x1, int y1, int x2, int y2){
    return Horizontal_Distance(x1, y1, x2, y2) + Vertical_Distance(x1, y1, x2, y2);
}
int Direction_Check(int a){
    if(a > 0){
        return 1;
    }
    else{
        return -1;
    }
}

void GameEngine::activate_monsters() {
    int px, py;

    player->get_position(px, py);
    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) { // center point
                continue;
            }
            else if (!((px + c >= 0 && px + c < MAP_SIZE) && (0 <= py + r && py + r < MAP_SIZE))){   // valid position
                continue;
            }
            else if (map[px+c][py+r]->get_unit_type() != UnitType::MONSTER) {
                continue;
            }

            Monster* temp = static_cast<Monster*>(map[px+c][py+r]);
            activate_monster(temp);
        }
    }
}

void GameEngine::deactivate_monster(Monster const *const monster) { 
    MonsterNode* currNode = head;
    MonsterNode* prevNode = nullptr;
    while(currNode != nullptr && currNode->data != monster){    // iter through
        prevNode = currNode;
        currNode = prevNode->next;
    }

    if (prevNode == nullptr) { // first node
        head = currNode->next;
    } 
    else {
        prevNode->next = currNode->next;
    }
    delete currNode;
}

void GameEngine::player_move(Direction d) {
    int tar_x, tar_y, px, py;
    player->get_position(px, py);
    if(d == Direction::UP){
        tar_x = px; tar_y = py + 1;
    }
    else if(d == Direction::DOWN){
        tar_x = px; tar_y = py - 1;
    }
    else if(d == Direction::LEFT){
        tar_x = px - 1; tar_y = py;
    }
    else if(d == Direction::RIGHT){
        tar_x = px + 1; tar_y = py;
    }
    

    if ((tar_x < 0 || tar_x >= MAP_SIZE || tar_y < 0 || tar_y >= MAP_SIZE) || (map[tar_x][tar_y]->is_blocked())) {    // is not in map or blocked
        player->move(d, 0);
    } 
    else {  // valid
        player->move(d, 1);
        map[tar_x][tar_y]->triggered_by(*player);
    }
}

void GameEngine::player_discover() {
    int px, py;
    player->get_position(px, py);
    for (int r = -2; r <= 2; r++) {
        for (int c = -2; c <= 2; c++) {
            if (r == 0 && c == 0) { // center point
                continue;
            }
            if (!((px + c >= 0 && px + c < MAP_SIZE) && (0 <= py + r && py + r < MAP_SIZE))){   // out of bound
                continue;
            }
            map[px+c][py+r]->set_discovered();
        }
    }
}


class position{
    public:
        int x;
        int y;
    private:
    
};

void GameEngine::player_attack() {
    int px, py;
    int attack, defense;
    int range = player->get_range();
    player->get_atk_def(attack, defense);
    Direction towards = player->get_direction();
    player->get_position(px, py);

    position attackable[range];
    if(towards == Direction::UP){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px;
            attackable[r].y = py + r + 1;
        }
    }
    else if(towards == Direction::DOWN){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px;
            attackable[r].y = py - r  - 1;
        }
    }
    else if(towards == Direction::LEFT){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px - r - 1;
            attackable[r].y = py;
        }
    }
    else if(towards == Direction::RIGHT){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px + r + 1;
            attackable[r].y = py;
        }
    }

    for (int r = 0; r < range; r++) {
        if (!(attackable[r].x >= 0 && attackable[r].x < MAP_SIZE) && !(attackable[r].y >= 0 && attackable[r].y < MAP_SIZE)){    // out of bound
            continue;
        }
        if (map[attackable[r].x][attackable[r].y]->get_unit_type() != UnitType::MONSTER){
            continue;
        }

        int hp;
        Monster* temp = static_cast<Monster*>(map[attackable[r].x][attackable[r].y]);
        hp = temp->attacked_by(attack);
        if (hp > 0) {
            deactivate_monster(temp);   // hp <= 0
            player->gain_exp(1);
        }
        else if (hp == 0 && !temp->is_active()) {
            activate_monster(temp);
        }
    }
}

void GameEngine::player_skill() {
    int px, py;
    int attack;
    int range = player->get_range();
    if (player->skill(attack, range)){
        return;
    }
    Direction towards = player->get_direction();
    player->get_position(px, py);

    position attackable[range];
    if(towards == Direction::UP){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px;
            attackable[r].y = py + r + 1;
        }
    }
    else if(towards == Direction::DOWN){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px;
            attackable[r].y = py - r  - 1;
        }
    }
    else if(towards == Direction::LEFT){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px - r - 1;
            attackable[r].y = py;
        }
    }
    else if(towards == Direction::RIGHT){
        for (int r = 0; r < range; r++) {
            attackable[r].x = px + r + 1;
            attackable[r].y = py;
        }
    }

    for (int r = 0; r < range; r++) {
        if (!(attackable[r].x >= 0 && attackable[r].x < MAP_SIZE) && !(attackable[r].y >= 0 && attackable[r].y < MAP_SIZE)){    // out of bound
            continue;
        }
        if (map[attackable[r].x][attackable[r].y]->get_unit_type() != UnitType::MONSTER){
            continue;
        }

        int hp;
        Monster* temp = static_cast<Monster*>(map[attackable[r].x][attackable[r].y]);
        hp = temp->attacked_by(attack);
        if (hp > 0) {
            deactivate_monster(temp);   // hp <= 0
            player->gain_exp(1);
        }
        else if (hp == 0 && !temp->is_active()) {
            activate_monster(temp);
        }
    }
}

void GameEngine::monster_follow() {
    MonsterNode* currNode = head;
    while(currNode != nullptr){
        currNode = currNode->next;
        currNode->data->follow(*player, map);
    }
}

void GameEngine::monster_act() {
    MonsterNode* currNode = head;
    while(currNode != nullptr){
        currNode = currNode->next;
        currNode->data->action(*player, map);
    }
}