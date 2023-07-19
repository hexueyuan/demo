#include <iostream>

#include "butil/cpu.h"


class TestOutputCPUInfo {
public:
    static void Print() {
        butil::CPU cpu;

        std::cout << "vendor_name: " << cpu.vendor_name() << std::endl;
        std::cout << "signature: " << cpu.signature() << std::endl;
        std::cout << "stepping: " << cpu.stepping() << std::endl;
        std::cout << "model: " << cpu.model() << std::endl;
        std::cout << "family: " << cpu.family() << std::endl;
        std::cout << "type: " << cpu.type() << std::endl;
        std::cout << "extended_model: " << cpu.extended_model() << std::endl;
        std::cout << "extended_family: " << cpu.extended_family() << std::endl;
        std::cout << "has_mmx: " << cpu.has_mmx() << std::endl;
        std::cout << "has_sse: " << cpu.has_sse() << std::endl;
        std::cout << "has_sse2: " << cpu.has_sse2() << std::endl;
        std::cout << "has_sse3: " << cpu.has_sse3() << std::endl;
        std::cout << "has_ssse3: " << cpu.has_ssse3() << std::endl;
        std::cout << "has_sse41: " << cpu.has_sse41() << std::endl;
        std::cout << "has_sse42: " << cpu.has_sse42() << std::endl;
        std::cout << "has_avx: " << cpu.has_avx() << std::endl;
    }
};

int main(int argc, char** argv) {
    TestOutputCPUInfo info;

    info.Print();

    return 0;
}