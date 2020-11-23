#include "../header/Pawn.hpp"
#include <iostream>
using namespace std;
// Main Method
int main() {
    Pawn* pawn = new Pawn(WHITE, new Coord(2, 3));

    // prints sum info on pawn
    cout << "Symbol: " << pawn->getSymbol() << "  Value: " << pawn->getValue()
    << "  Team: " << pawn->getTeam() << "  Current Location: (" << pawn->getLocation()->x
    << "," << pawn->getLocation()->y << ") \n";

}
