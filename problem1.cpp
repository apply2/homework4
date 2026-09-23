/*
 * Problem 1: struct vs class
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * struct 와 class 의 차이를 직접 확인하는 문제입니다.
 *
 *  - struct 의 member 는 기본적으로 public  → 외부에서 직접 접근 가능
 *  - class  의 member 는 기본적으로 private → member function 을 통해서만 접근 가능
 *
 * 아래 struct Point 와 class Rectangle 의 TODO 함수를 구현하세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

// ── struct Point: passive data structure (members public by default) ──
struct Point {
    int x;   // public by default: 외부에서 직접 접근 가능
    int y;

    // TODO: "Point(x, y)" 형식으로 출력하세요.  예) Point(3, 4)
    void print() const;

    // TODO: x*x + y*y 를 반환하세요.
    int distanceSquared() const;
};

// ── class Rectangle: active object (members private by default) ───────
class Rectangle {
private:
    int width;
    int height;
public:
    // TODO: this->width 와 this->height 를 이용하여 초기화하세요.
    Rectangle(int width, int height);

    // TODO: width * height 를 반환하세요.  (const 필수)
    int area() const;

    // TODO: 2 * (width + height) 를 반환하세요.  (const 필수)
    int perimeter() const;

    // TODO: "Rectangle(width x height)" 형식으로 출력하세요.  예) Rectangle(5 x 3)
    //       (const 필수)
    void print() const;

    // TODO: width 와 height 각각에 factor 를 곱하세요.
    void scale(int factor);
};

// ── struct Point 구현 ─────────────────────────────────────────────────
void Point::print() const {
    // TODO
}

int Point::distanceSquared() const {
    // TODO
    return 0;
}

// ── class Rectangle 구현 ─────────────────────────────────────────────
Rectangle::Rectangle(int width, int height) {
    // TODO: this-> 를 반드시 사용하세요.
}

int Rectangle::area() const {
    // TODO
    return 0;
}

int Rectangle::perimeter() const {
    // TODO
    return 0;
}

void Rectangle::print() const {
    // TODO
}

void Rectangle::scale(int factor) {
    // TODO
}

// ── runner (수정하지 마세요) ───────────────────────────────────────────
void runProblem1(istream& in) {
    int px, py, rw, rh, factor;
    in >> px >> py >> rw >> rh >> factor;

    cout << "=== Problem 1: struct vs class ===" << "\n";

    // struct 의 member 는 기본적으로 public → p.x, p.y 에 직접 접근
    cout << "[Part 1] struct Point" << "\n";
    Point p;
    p.x = px;
    p.y = py;
    p.print();
    cout << "distanceSquared = " << p.distanceSquared() << "\n";
    cout << "x = " << p.x << ", y = " << p.y << "\n";

    // class 의 member 는 기본적으로 private → member function 으로만 접근
    cout << "[Part 2] class Rectangle" << "\n";
    Rectangle r(rw, rh);
    r.print();
    cout << "area = " << r.area() << "\n";
    cout << "perimeter = " << r.perimeter() << "\n";

    cout << "[Part 3] scale(" << factor << ")" << "\n";
    r.scale(factor);
    r.print();
    cout << "area = " << r.area() << "\n";
    cout << "perimeter = " << r.perimeter() << "\n";
}
