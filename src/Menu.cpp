#include "../include/Menu.h"


void Menu::Start() {
    int npcCounter = 0;
    std::vector<INPC*> npcArray;
    std::cout << "Введите количесво создаваемых NPC: ";
    std::cin >> npcCounter;

    std::cout << "Идет создание NPC..." << std::endl;
    NPCGenerator(npcArray, npcCounter);
    std::cout << "Процесс создания завершен!" << std::endl << std::endl;

    std::cout << "Идет загрузка массива с NPC в файл..." << std::endl;
    const std::string fileName = "../npc.txt";
    saveNpcArrayToFile(npcArray, fileName);
    std::cout << "Процесс загрузки завершен!" << std::endl << std::endl;

    std::cout << "Идет процесс считывания NPC из файла..." << std::endl;
    std::vector<INPC*> loadedArray = loadNpcArrayFromFile(fileName);
    std::cout << "Процесс выгрузки завершен!" << std::endl << std::endl;

    while (true) {
        std::string inputFromUser = "";
        std::cout << "Введите 'Go', если хотите запустить битву, или 'Exit', если хотите выйти: ";
        std::cin >> inputFromUser;
        if (inputFromUser == "Go") {
            makeFight(loadedArray);
            break;
        } else if (inputFromUser == "Exit") {
            return;
        } else {
            std::cout << "Некоректные входные данные" << std::endl;
        }
    }
}
