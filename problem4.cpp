/*
 * Problem 4: const Member Functions
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * Product class 의 TODO 함수를 구현하세요.
 *
 *  - 상태를 변경하지 않는 함수(getter, totalValue, printInfo)에는 반드시 const 를 붙이세요.
 *  - const object (또는 const 참조)는 const member function 만 호출할 수 있습니다.
 *  - getter 는 const, setter 는 non-const 로 선언합니다.
 *
 * printInfo() 출력 형식:
 *   "<name>: price = <price>, quantity = <quantity>, total = <totalValue>"
 *   예) Apple: price = 200, quantity = 10, total = 2000
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int price;
    int quantity;
public:
    // TODO: this-> 를 사용하여 name, price, quantity 를 초기화하세요.
    Product(const string& name, int price, int quantity);

    // TODO: name 을 반환하세요. (const 필수)
    string getName() const;

    // TODO: price 를 반환하세요. (const 필수)
    int getPrice() const;

    // TODO: quantity 를 반환하세요. (const 필수)
    int getQuantity() const;

    // TODO: price * quantity 를 반환하세요. (const 필수)
    int totalValue() const;

    // TODO: price 를 newPrice 로 설정하세요.
    void setPrice(int newPrice);

    // TODO: quantity 에 amount 를 더하세요.
    void restock(int amount);

    // TODO: 위 형식으로 출력하세요. (const 필수)
    void printInfo() const;
};

Product::Product(const string& name, int price, int quantity) {
    // TODO: this-> 를 반드시 사용하세요.
}

string Product::getName() const {
    // TODO
    return "";
}

int Product::getPrice() const {
    // TODO
    return 0;
}

int Product::getQuantity() const {
    // TODO
    return 0;
}

int Product::totalValue() const {
    // TODO
    return 0;
}

void Product::setPrice(int newPrice) {
    // TODO
}

void Product::restock(int amount) {
    // TODO
}

void Product::printInfo() const {
    // TODO
}

// ── runner (수정하지 마세요) ───────────────────────────────────────────
void runProblem4(istream& in) {
    string name;
    int price, quantity, newPrice, restockAmount;
    in >> name >> price >> quantity >> newPrice >> restockAmount;

    cout << "=== Problem 4: const Member Functions ===" << "\n";

    Product prod(name, price, quantity);

    cout << "[Part 1] Initial state" << "\n";
    prod.printInfo();

    // const 참조를 통해서는 const member function 만 호출 가능
    cout << "[Part 2] const object read-only access" << "\n";
    const Product& cRef = prod;
    cout << "name = " << cRef.getName() << "\n";
    cout << "price = " << cRef.getPrice() << "\n";
    cout << "quantity = " << cRef.getQuantity() << "\n";
    cout << "totalValue = " << cRef.totalValue() << "\n";

    cout << "[Part 3] setPrice(" << newPrice << ")" << "\n";
    prod.setPrice(newPrice);
    prod.printInfo();

    cout << "[Part 4] restock(" << restockAmount << ")" << "\n";
    prod.restock(restockAmount);
    prod.printInfo();
}
