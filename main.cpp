#include "house/house.h"
#include "app/app.h"

int main() {
    term::Terminal &t = term::Terminal::instance();
    launchApp(t);
    return 0;
}