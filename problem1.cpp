/*
 * Problem 1: struct vs class
 *
 * 학번:202302603
 * 이름:이지원
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 두 타입을 직접 정의하고 구현하세요.
 *
 * [Part 1] struct Point
 *   - struct 키워드를 사용하세요.
 *   - data member : int x, int y
 *   - void print() const          → "Point(x, y)" 형식으로 출력  예) Point(3, 4)
 *   - int distanceSquared() const → x*x + y*y 를 반환합니다.
 *   ※ 기본 접근 제어자가 무엇인지 생각해 보세요.
 *
 * [Part 2] class Rectangle
 *   - class 키워드를 사용하세요.
 *   - private data member : int width, int height
 *   - public member function :
 *       Rectangle(int width, int height) : 멤버 변수를 초기화합니다.
 *       int area() const        → width * height 를 반환합니다.
 *       int perimeter() const   → 2*(width+height) 를 반환합니다.
 *       void print() const      → "Rectangle(width x height)" 형식으로 출력  예) Rectangle(5 x 3)
 *       void scale(int factor)  → width, height 에 factor 를 곱합니다.
 *   ※ 기본 접근 제어자가 무엇인지 생각해 보세요.
 *
 * runner 함수(runProblem1)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
#include <type_traits>
using namespace std;

// ── struct Point 를 구현하세요 ───────────────────────────────────
struct Point {
    int x, y;
    void printInfo() const {
        std::cout << "Point(" << x << ", " << y << ")" <<"\n";
    }
    int distanceSquared() const {
        return x*x + y*y;
    }
}

// ── class Rectangle 을 구현하세요 ────────────────────────────────
class Rectangle {
    private:
    int width, height;
    public:
    Rectangle(int width, int height);
    int area() const {
        return width*height;
    }
    int perimeter() const {
        return 2*(width*height);
    }
    void print() const {
        std::cout << "Rectangle(" << width * height << ")" << "\n";
    }
    void scale(int factor) {
        width  *= factor;
        height *= height;
    }
}

// ── runner (수정하지 마세요) ───────────────────────────────────
template<typename T, typename = void>
struct has_public_width : false_type {};
template<typename T>
struct has_public_width<T, void_t<decltype(declval<T>().width)>> : true_type {};

template<typename T, typename = void>
struct has_public_height : false_type {};
template<typename T>
struct has_public_height<T, void_t<decltype(declval<T>().height)>> : true_type {};

static_assert(!has_public_width<Rectangle>::value,  "Rectangle::width 는 private 이어야 합니다.");
static_assert(!has_public_height<Rectangle>::value, "Rectangle::height 는 private 이어야 합니다.");

void runProblem1(istream& in) {
    int px, py, rw, rh, factor;
    in >> px >> py >> rw >> rh >> factor;

    cout << "=== Problem 1: struct vs class ===" << "\n";

    cout << "[Part 1] struct Point" << "\n";
    Point p;
    p.x = px;
    p.y = py;
    p.print();
    cout << "distanceSquared = " << p.distanceSquared() << "\n";
    cout << "x = " << p.x << ", y = " << p.y << "\n";

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
// ─────────────────────────────────────────────────────────────