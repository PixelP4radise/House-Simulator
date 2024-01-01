#include "headerFiles/house.h"
#include "headerFiles/app.h"

int main() {
    term::Terminal &t = term::Terminal::instance();
    launchApp(t);
    return 0;
}