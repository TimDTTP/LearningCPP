
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season {
  std::string_view name{};
  double averageTemperature{};
};

int main() {
  std::array<Season, 4> seasons{{
      {"Spring", 285.0},
      {"Summer", 296.0},
      {"Fall", 288.0},
      {"Winter", 263.0},
  }};

  const auto ascendTemp{[](const auto &i, const auto &j) {
    return i.averageTemperature < j.averageTemperature;
  }};

  std::sort(seasons.begin(), seasons.end(), ascendTemp);

  for (const auto &season : seasons) {
    std::cout << season.name << '\n';
  }

  return 0;
}
