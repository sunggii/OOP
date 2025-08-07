#include <iostream>
using namespace std;

// ตัวอย่างคลาสที่เรากำหนดเอง
class MyObject {
public:
    double value;

    MyObject(double v) : value(v) {}

    // overload operator > สำหรับเปรียบเทียบกับ double
    bool operator> (double other) const {
        return value > other;
    }

    // overload operator > สำหรับเปรียบเทียบกับ MyObject
    bool operator> (const MyObject& other) const {
        return value > other.value;
    }

    // เพื่อให้สามารถเทียบกับ int ได้ (convert int เป็น double)
    bool operator> (int other) const {
        return value > static_cast<double>(other);
    }
};

// template ฟังก์ชันสำหรับหาค่ามากที่สุด
template <typename T1, typename T2, typename T3>
auto maxOfThree(T1 a, T2 b, T3 c) {  //
    auto maxVal = (a > b) ? a : b;
    return (maxVal > c) ? maxVal : c;
}

int main() {
    MyObject obj(7.5);
    int x = 5;
    double y = 10.5;

    cout << "Max of obj, x, y: " << maxOfThree(obj, x, y).value << endl;

    return 0;
}
