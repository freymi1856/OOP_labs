#include "../input/dragon.h"
#include "../input/knight.h"
#include "../input/pegas.h"
#include <algorithm>

Pegas::Pegas(int x, int y,std::string &_name) :  NPC(PegasType, x, y, _name) {}

Pegas::Pegas(std::ifstream &is,std::string &_name) : NPC(PegasType, is, _name) {}

Pegas::~Pegas() {}

void Pegas::print()
{
    std::cout << *this;
}

void Pegas::save(std::ofstream &os){
    os << PegasType << std::endl;
    NPC::save(os);
}

void Pegas::get_name(std::ofstream &os){
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl;
}

void Pegas::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Pegas::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream &operator<<(std::ostream &os, Pegas &Pegas)
{
    os << "Pegas: " << *static_cast<NPC*>(&Pegas) << std::endl;
    return os;
}