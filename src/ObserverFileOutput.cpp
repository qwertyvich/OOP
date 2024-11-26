#include "../include/ObserverFileOutput.h"



void ObserverFileOutput::update(INPC *npc) const noexcept {
    const std::string path = "../log.txt";
    std::ofstream logs(path, std::ofstream::app);
    try {
        if (logs.is_open()) {
            logs << "Убит " << npc->getName() << '\n';
            logs << "С кординатами: " << "(" <<
                npc->getCords().first << ", " <<  npc->getCords().second << ")\n";
        } else {
            throw std::logic_error("Ошибка открытия файла");
        }
        logs.close();
    } catch (std::exception & ex) {
        std::cerr << ex.what() << std::endl;
    }
}
