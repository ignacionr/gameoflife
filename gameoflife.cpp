#include <iostream>
#include <cstring>

class Board {
    // a variable that is part of an object, we call "field"
    bool world_[25][25];
public:
    // constructor
    Board() {
        // a constructor will initialize the state of the object to some valid initial state
        std::memset(world_, 0, sizeof(world_));
    }

    // a function that is a member of an object, is called "method"
    bool what_is_the_value_of(int y, int x) 
        // const here means that the state of the object is not modified
        const 
    { return world_[y][x];}
    
    template<typename TStream>
    void print(TStream &out) {
        // iterate from the first line to the last
        for (int i = 0; i < 25; ++i) {
            // on each line, iterate from the first cell to the last
            for (int j = 0; j < 25; ++j) {
                // print '-' if 0 or '*' if 1
                //Ternary operator
                char c = world_[i][j] ? /* something true*/ '*' : /* something false*/ '-';
                out << c;
            }
            // print an end of line
            out << std::endl;
        }
    }
};

int main() {
    // model a world (rectangular world with positions that are either dead or alive)
    Board b; 
    // << applied to integrals, is called the "left bit-wise shift operator" (1 << 3 == 8)
    // << applied to streams is called the "insertion operator"
    // cout represents the stream (series of bytes) that you want shown on the screen
    std::cout << b.what_is_the_value_of(0,0)<< std::endl;

    // print the board as it is
    b.print(std::cout);

    // the rules of production/deletion
    // generations (apply the rules time and again)
    return 0;
}
