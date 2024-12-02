#include "../include/Visitor.hpp"


bool BearVisitor::visit(const Elf &elf) {
    return true;
}

bool BearVisitor::visit(const Bear & bear) {
    return false;
}

bool BearVisitor::visit(const Outlaw &outlaw) {
    return false;
}

bool ElfVisitor::visit(const Elf &elf) {
    return false;
}

bool ElfVisitor::visit(const Bear &bear) {
    return false;
}

bool ElfVisitor::visit(const Outlaw &outlaw) {
    return true;
}

bool OutlawVisitor::visit(const Elf &elf) {
    return false;
}

bool OutlawVisitor::visit(const Bear &bear) {
    return false;
}

bool OutlawVisitor::visit(const Outlaw &outlaw) {
    return true;
}



