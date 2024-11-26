#pragma once
#include "NPC.h"

class Bear;
class Elf;
class Outlaw;
class IVisitor {
public:
    virtual bool visit(const Bear & bear) = 0;
    virtual bool visit(const Elf & elf) = 0;
    virtual bool visit(const Outlaw & outlaw) = 0;

};

class BearVisitor : public IVisitor {
public:
    bool visit(const Bear & bear) override;
    bool visit(const Elf & elf) override;
    bool visit(const Outlaw & outlaw) override;

};

class ElfVisitor : public IVisitor {
public:
    bool visit(const Bear & bear) override;
    bool visit(const Elf & elf) override;
    bool visit(const Outlaw & outlaw) override;

};

class OutlawVisitor : public IVisitor {
public:
    bool visit(const Bear & bear) override;
    bool visit(const Elf & elf) override;
    bool visit(const Outlaw & outlaw) override;
};

