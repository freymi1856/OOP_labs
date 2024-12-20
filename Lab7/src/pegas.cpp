#include "../input/pegas.hpp"
#include "../input/dragon.hpp"
#include "../input/knight.hpp"

Pegas::Pegas(int x, int y) : NPC(PegasType, x, y) {}
Pegas::Pegas(std::istream &is) : NPC(PegasType, is) {}

bool Pegas::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Pegas>(this,[](Pegas*){}));
}

void Pegas::print()
{
    std::cout << *this;
}

void Pegas::save(std::ostream &os)
{
    os << PegasType << std::endl;
    NPC::save(os);
}


bool Pegas::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return true;
}

bool Pegas::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return true;
}

bool Pegas::fight(std::shared_ptr<Pegas> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Pegas &pegas)
{
    os << "pegas: " << *static_cast<NPC *>(&pegas) << std::endl;
    return os;
}