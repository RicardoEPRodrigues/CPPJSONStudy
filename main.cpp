#include <iostream>
#include <fstream>

#include "json.hpp"
#include "Looper.h"

using json = nlohmann::json;
using namespace RRUtils;

void Update(Looper*);

int main() {

    Looper looper (Update, 1000);
    looper.start();

    return 0;
}

int cycles = 0;
json j;

void Update(Looper* looper) {
    std::ifstream i("test.json");
    json file;
    i >> file;

    if (j != file) {
        j = file;
        std::cout << j << std::endl;
    }


    if (j["stop"]) {
        looper->stop();
    }

    ++cycles;
    if (cycles >= j["maxCycles"]) {
        looper->stop();
    }
    std::cout << cycles << std::endl;
}
