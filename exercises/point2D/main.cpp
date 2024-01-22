
#include <cmath>
#include <iostream>

class Point2d {
private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };

public:
    Point2d() = default;
    
    Point2d(double x, double y)
        : m_x{ x }
        , m_y{ y }
    {
    }

    void print() {
        std::cout << "Point2d(" << m_x << ", " << m_y << " )\n";
    }

    double distanceTo(Point2d initial) {
        double distance{ std::sqrt((m_x - initial.m_x) * (m_x - initial.m_x) +
                                   (m_y - initial.m_y) * (m_y - initial.m_y))
        };

        return distance;
    }
};


int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}