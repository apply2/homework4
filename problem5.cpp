/*
 * Problem 5: Integrated
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * Order class 의 member function body 를 구현하세요.
 *
 * 요구 사항:
 *  - private data member 로 내부 상태를 보호합니다.
 *  - 생성자에서 this-> 를 사용하여 parameter 와 member 를 구분합니다.
 *  - 생성자에서 totalOrders 를 증가시킵니다.
 *  - updateQuantity: quantity <= 0 이면 거부하고 false 반환.
 *    아니면 this->quantity 를 업데이트하고 true 반환.
 *  - 상태를 변경하지 않는 함수는 반드시 const 로 선언합니다.
 *  - 모든 함수는 class 외부에서 Order:: 를 이용하여 정의합니다.
 *
 * printInfo() 출력 형식:
 *   "Order <orderId>: qty = <quantity>, unitPrice = <unitPrice>, total = <totalPrice>"
 *   예) Order 1: qty = 3, unitPrice = 500, total = 1500
 *
 * 주의: class 선언부(중괄호 안)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

class Order {
private:
    int orderId;
    int quantity;
    int unitPrice;
    static int totalOrders;   // 생성된 Order 의 수 (모든 object 가 공유)
public:
    Order(int orderId, int quantity, int unitPrice);

    int getOrderId() const;
    int getQuantity() const;
    int getUnitPrice() const;
    int totalPrice() const;          // quantity * unitPrice

    bool updateQuantity(int quantity); // quantity <= 0 이면 false

    static int getTotalOrders();

    void printInfo() const;
};

// static member 정의 (수정하지 마세요)
int Order::totalOrders = 0;

// TODO: 아래 함수들의 body 를 구현하세요.

Order::Order(int orderId, int quantity, int unitPrice) {
    // TODO: this-> 를 사용하여 각 member 를 초기화하고, totalOrders 를 1 증가시키세요.
}

int Order::getOrderId() const {
    // TODO
    return 0;
}

int Order::getQuantity() const {
    // TODO
    return 0;
}

int Order::getUnitPrice() const {
    // TODO
    return 0;
}

int Order::totalPrice() const {
    // TODO: quantity * unitPrice 를 반환하세요.
    return 0;
}

bool Order::updateQuantity(int quantity) {
    // TODO: quantity <= 0 이면 아무것도 하지 않고 false 를 반환하세요.
    //       아니면 this->quantity 를 업데이트하고 true 를 반환하세요.
    return false;
}

int Order::getTotalOrders() {
    // TODO
    return 0;
}

void Order::printInfo() const {
    // TODO: 위의 형식으로 출력하세요.
}

// ── runner (수정하지 마세요) ───────────────────────────────────────────
void runProblem5(istream& in) {
    int n;
    in >> n;

    cout << "=== Problem 5: Integrated ===" << "\n";

    Order* orders[10];
    cout << "[Part 1] Create orders" << "\n";
    for (int i = 0; i < n; i++) {
        int id, qty, price;
        in >> id >> qty >> price;
        orders[i] = new Order(id, qty, price);
        orders[i]->printInfo();
    }

    cout << "[Part 2] Static state" << "\n";
    cout << "Order::getTotalOrders() = " << Order::getTotalOrders() << "\n";

    int updateIdx0, newQty0, updateIdx1, newQty1;
    in >> updateIdx0 >> newQty0 >> updateIdx1 >> newQty1;

    cout << "[Part 3] Invalid update" << "\n";
    bool r = orders[updateIdx0]->updateQuantity(newQty0);
    cout << "updateQuantity(" << newQty0 << ") = " << (r ? "true" : "false") << "\n";
    orders[updateIdx0]->printInfo();

    cout << "[Part 4] Valid update" << "\n";
    r = orders[updateIdx1]->updateQuantity(newQty1);
    cout << "updateQuantity(" << newQty1 << ") = " << (r ? "true" : "false") << "\n";
    orders[updateIdx1]->printInfo();

    cout << "[Part 5] Final static state" << "\n";
    cout << "Order::getTotalOrders() = " << Order::getTotalOrders() << "\n";

    for (int i = 0; i < n; i++) delete orders[i];
}
