
#include <iostream>
#include <string_view>

class Ball {
private:
    std::string_view m_color{ "black" };
    double m_radius{ 10 };

public:
    Ball()
    {
        Ball{ "black", 10 };
    }

    Ball(std::string_view color)
        : m_color{ color }
    {
        Ball{ color, 10 };
    }

    Ball(double radius)
        : m_radius{ radius }
    {
        Ball{ "black", radius };
    }

    Ball(std::string_view color, double radius)
        : m_color{ color }
        , m_radius{ radius }
    {
        std::cout << "Ball(" << m_color << ", " << radius << ")\n";
    }
};


int main() {
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}