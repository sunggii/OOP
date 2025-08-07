#include <iostream>
#include <string>

class Rectangle {
private:
    double w;
    double l;

public:
    Rectangle() : w(0.0), l(0.0) {}

    Rectangle(double width, double length) : w(width), l(length) {}

    double getW() const {
        return w;
    }

    double getL() const {
        return l;
    }

    void setW(double width) {
        w = width;
    }

    void setL(double length) {
        l = length;
    }

    void show() const {
        std::cout << "Width: " << w << ", Length: " << l << std::endl;
    }

    ~Rectangle() {
        std::cout << "Rectangle destroyed." << std::endl;
    }

};

class MyRect {
private:
    Rectangle** rectArray;
    int rows;
    int cols;

public:

    MyRect() : rows(0), cols(0), rectArray() {}

    MyRect(int numRow, int numCol){
        rows = numRow;
        cols = numCol;
        rectArray = new Rectangle*[rows];
        for (int i = 0; i < rows; ++i) {
            rectArray[i] = new Rectangle[cols];
        }
    }

    ~MyRect() {
        for (int i = 0; i < rows; ++i) {
            delete[] rectArray[i];
        }
        delete[] rectArray;
    }

    void reset(int numRow, int numCol) {
        for (int i = 0; i < rows; ++i) {
            delete[] rectArray[i];
        }
        delete[] rectArray;

        rows = numRow;
        cols = numCol;
        rectArray = new Rectangle*[rows];
        for (int i = 0; i < rows; ++i) {
            rectArray[i] = new Rectangle[cols];
        }

        std::cout << "Resize Array" << std::endl;
    }

    void setRect(int row, int col, double width, double length) {
        rectArray[row][col].setW(width);
        rectArray[row][col].setL(length);
    }

    Rectangle getRect(int row, int col) const {
        return rectArray[row][col];
    }

    void show() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Rectangle at (" << i << ", " << j << "): ";
                rectArray[i][j].show();
            }
        }
    }
};

int main() {
    MyRect myRectArray(2, 2);

    myRectArray.setRect(0, 0, 5.0, 7.0);
    myRectArray.setRect(0, 1, 3.0, 4.0);
    myRectArray.setRect(1, 0, 6.0, 8.0);
    myRectArray.setRect(1, 1, 4.0, 5.0);
    myRectArray.show();

    myRectArray.reset(3, 3);
    myRectArray.show();
    


    return 0;
}
