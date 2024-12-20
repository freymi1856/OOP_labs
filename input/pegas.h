#ifndef PEGAS_H
#define PEGAS_H

#include "npc.h"

struct Pegas : public NPC
{
    Pegas(int x, int y,std::string &_name);
    Pegas(std::ifstream &is,std::string &_name);
    ~Pegas();

    void print() override;
    void save(std::ofstream &os) override;

    void get_name(std::ofstream &os) override;

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor);

    void attach(std::shared_ptr<IObserver> observer) override;
    void detach(std::shared_ptr<IObserver> observer) override;

    friend std::ostream &operator<<(std::ostream &os, Pegas &pegas);
};

#endif