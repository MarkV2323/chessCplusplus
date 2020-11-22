#ifndef FINALPROJECT_COORD_HPP
#define FINALPROJECT_COORD_HPP
#include <string>

class Coord {
public:
    int x, y;
    Coord(int x, int y);

    void add(const Coord &c);
    // add where reaching 8 wraps back around to 0
    void addWrapped(const Coord &c);

    Coord& operator=(const Coord& arg) noexcept = default;
    Coord& operator+=(const Coord& arg);
    Coord operator+(const Coord& rhs) const;
    bool operator==(const Coord& rhs) const;

    // toString for x and y values.
    std::string stringify();

};
#endif //FINALPROJECT_COORD_HPP
