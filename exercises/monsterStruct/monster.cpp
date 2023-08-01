#include <iostream>
#include <string>

// enum monster types
enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

// struct monster
struct Monster
{
    MonsterType monster{};
    std::string name{};
    int health{};
};

// print function
void printMonster(const Monster& input)
{
    std::cout << "This ";

    switch (input.monster)
    {
        case MonsterType::ogre:
        {
            std::cout << "Ogre";
            break;
        };

        case MonsterType::dragon:
        {
            std::cout << "Dragon";
            break;
        };

        case MonsterType::orc:
        {
            std::cout << "Orc";
            break;
        };

        case MonsterType::giantSpider:
        {
            std::cout << "Giant Spider";
            break;
        };

        case MonsterType::slime:
        {
            std::cout << "Slime";
            break;
        };

        default: std::cout << "Faulty";
    };

    std::cout << " is named " << input.name << " and has " << input.health << " health.\n";
}

int main()
{
    Monster monster1{ MonsterType::ogre, "Shrek", 1000 };
    Monster monster2{ MonsterType::slime, "Rimuru", 250 };

    printMonster(monster1);
    printMonster(monster2);

    return 0;
}