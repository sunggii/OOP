#include <iostream>
//#include <stdexcept>

// ฟังก์ชันที่อยู่ลึกสุดซึ่งจะโยนความผิดปกติ
void level3() {
    std::cout << "Inside level 3\n";
    throw std::runtime_error("Error occurred in level 3");
}

// ฟังก์ชันชั้นที่สอง
void level2() {
    std::cout << "Inside level 2\n";
    try {
        level3();
    } catch (const std::exception& e) {
        std::cout << "Caught exception in level 2: " << e.what() << '\n';
        throw; // โยนความผิดปกติต่อไป
    }
}

// ฟังก์ชันชั้นแรก
void level1() {
    std::cout << "Inside level 1\n";
    try {
        level2();
    } catch (const std::exception& e) {
        std::cout << "Caught exception in level 1: " << e.what() << '\n';
        throw; // โยนความผิดปกติกลับไป
    }
}

int main() {
    try {
        level1();
    } catch (const std::exception& e) {
        std::cout << "Caught exception in main: " << e.what() << '\n';
    }
    return 0;
}
