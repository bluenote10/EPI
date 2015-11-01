#include "convenience.hpp"


char flip_char(char x) { // C doesn't have parametric polymorphism, so don't overload
    /*
    char result = 0;
    for (int i = 0; i < 8; ++i) {
        result ^= ((x >> i) & 1 ? (1 << i) : 0);

    }
    */
    for (int i = 0; i < 4; ++i) {
        int k = 7 - i;
        if (((x >> i) & 1) != ((x >> k) & 1)) {
            x ^= (1 << i) | (1 << k);
        }
    }
}

void flip(unsigned char* bitmap, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x <= width / 16; ++x) {
            // note: divide by 8 (due to bits) and 2 to only iterate one half
            // TODO: if there is an uneven number of column, we still have to flip the remaining "center" column...

            //bitmap[x][y] = bitmap[width-x-1][y]
            //swap(bitmap[x + width*y], bitmap[(width-x-1) + width*y]);
            char left = bitmap[x + width*y];
            bitmap[x + width*y] = flip_char(bitmap[(width-x-1) + width*y]);
            bitmap[(width-x-1) + width*y] = flip_char(left);
        }
    }
}

int main(int argc, char** args) {


  return 0;
}


