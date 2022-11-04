#include "Terrain.h"

//write your codes here

Terrain::Terrain(int x_, int y_):MapUnit(x_, y_) { 
}

Terrain::~Terrain() {
}

UnitType Terrain::get_unit_type() const {
    return UnitType::TERRAIN;
}