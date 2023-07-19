#include <iostream>

#include <butil/version.h>


int main() {
    butil::Version ver("1.0.0");

    std::cout << "Version: " << ver.GetString() << std::endl;

    return 0;
}