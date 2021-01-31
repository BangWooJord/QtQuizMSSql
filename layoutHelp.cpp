#include "layoutHelp.h"

SIZE_AND_PLACE::SIZE_AND_PLACE() {
    hsize =10;
    vsize = 5;
    xpos = 10;
    ypos = 5;
}

SIZE_AND_PLACE::SIZE_AND_PLACE(int h, int v, int x, int y):hsize(h), vsize(v), xpos(x), ypos(y) {

}