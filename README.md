# Лабораторная работа № 2
### Тема: Классы
##### Выполнил: Салихов Руслан М8О-203Б-23
##### Цель:
+ Закрепление навыков работы с классами
+ Закрепление навыков работы с динамической памятью на «куче»
+  Закрепление навыков работы с массивами

##### Классы:
№3. Создать класс Octal для работы с беззнаковыми целыми восьмеричными числами, используя для 
представления числа массив из элементов типа unsigned char, каждый элемент которого является 
восьмеричной цифрой. Младшая цифра имеет меньший индекс (единицы — в нулевом элементе массива). 

#### Установка
```bash
sudo apt update
git clone --branch lab2 https://github.com/qwertyvich/OOP.git
cd OOP
git clone https://github.com/google/googletest.git
mkdir build 
cd build 
cmake .. 
make run_tests 
./run_tests
```