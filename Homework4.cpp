#include <iostream>
#include <string>

// Абстрактный класс Растение
class Plant
{
protected:
    std::string name; // Название растения
    std::string size; // Размер 
    double height;    // Высота

public:
    // Конструктор
    Plant(std::string n, std::string s, double h) : name(n), size(s), height(h) {}

    // Функция для отображения информации о растении
    virtual void displayInfo() const = 0;

    // Функция для получения плодов
    virtual std::string getFruits() const = 0;
};

// Класс Куст
class Bush : public Plant
{
public:
    // Конструктор
    Bush(std::string n, double h) : Plant(n, "маленькое", h) {}

    // Переопределение метода для отображения информации о кусте
    void displayInfo() const override
    {
        std::cout << "Куст: " << name << "\nРазмер: " << size << "\nВысота: " << height << " м \n";
    }

    // Переопределение метода для получения плодов
    std::string getFruits() const override
    {
        return "Ягоды: Малина, Черника";
    }
};

// Класс Дерево
class Tree : public Plant
{
public:
    // Конструктор
    Tree(std::string n, double h) : Plant(n, "большое", h) {}

    // Переопределение метода для отображения информации о дереве
    void displayInfo() const override
    {
        std::cout << "Дерево: " << name << "\nРазмер: " << size << "\nВысота: " << height << " м \n";
    }

    // Переопределение метода для получения плодов
    std::string getFruits() const override
    {
        return "Фрукты: Яблоко, Груша";
    }
};

// Класс для Яблони
class AppleTree : public Tree
{
public:
    AppleTree(double h) : Tree("Яблоня", h) {}

    std::string getFruits() const override
    {
        return "Яблоки";
    }
};

// Класс для Груши
class PearTree : public Tree
{
public:
    PearTree(double h) : Tree("Груша", h) {}

    std::string getFruits() const override
    {
        return "Груши";
    }
};

// Класс для Малины
class RaspberryBush : public Bush
{
public:
    RaspberryBush(double h) : Bush("Малиновый куст", h) {}

    std::string getFruits() const override
    {
        return "Малина";
    }
};

// Класс для Черники
class BlueberryBush : public Bush
{
public:
    BlueberryBush(double h) : Bush("Черничный куст", h) {}

    std::string getFruits() const override
    {
        return "Черника";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    // Создание объектов разных растений
    AppleTree appleTree(3.0);
    PearTree pearTree(4.0);
    RaspberryBush raspberryBush(1.5);
    BlueberryBush blueberryBush(1.2);

    // Отображение информации и получение плодов
    Plant* plants[] = { &appleTree, &pearTree, &raspberryBush, &blueberryBush };

    for (const auto& plant : plants)
    {
        plant->displayInfo();
        std::cout << "Собраны: " << plant->getFruits() << "\n\n";
    }

    return 0;
}
