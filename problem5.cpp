/*
 * Problem 5: Integrated
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 요구사항을 읽고 Order 클래스를 처음부터 구현하세요.
 * 모든 멤버 함수는 클래스 선언부 바깥에서 정의하세요.
 *
 * ─────────────────────────────────────────────────────────────
 * [데이터 멤버] (모두 private)
 *
 *   orderId     (int)          : 주문 번호.
 *   quantity    (int)          : 주문 수량. updateQuantity 함수로만 변경됨.
 *   unitPrice   (int)          : 단가.
 *   totalOrders (int)          : 지금까지 생성된 Order 객체의 총 수.
 *                                [중요] 모든 객체가 공유하는 클래스 전체 변수.
 *
 * [생성자]
 *
 *   Order(orderId, quantity, unitPrice) 으로 세 멤버를 초기화.
 *   - 생성할 때마다 totalOrders 를 1 증가시키세요.
 *
 * [멤버 함수] — 상태를 변경하지 않는 함수에는 반드시 const 를 붙이세요.
 *             모든 함수는 클래스 바깥에서 정의하세요.
 *
 *   getOrderId()    int 반환          [중요] 객체 상태를 바꾸지 않음.
 *   getQuantity()   int 반환          [중요] 객체 상태를 바꾸지 않음.
 *   getUnitPrice()  int 반환          [중요] 객체 상태를 바꾸지 않음.
 *   totalPrice()    int 반환          quantity × unitPrice. [중요] 객체 상태를 바꾸지 않음.
 *
 *   updateQuantity(int quantity)      bool 반환
 *     파라미터 quantity 가 0 이하이면 아무것도 바꾸지 않고 false 를 반환한다.
 *     0 초과이면 this->quantity 를 업데이트하고 true 를 반환한다.
 *
 *   getTotalOrders()   int 반환   totalOrders 반환.
 *
 *   printInfo()        아래 형식으로 출력. 객체 상태를 바꾸지 않음.
 *     Order <orderId>: qty = <quantity>, unitPrice = <unitPrice>, total = <totalPrice>
 *     예) Order 1: qty = 3, unitPrice = 500, total = 1500
 *
 * runner 함수(runProblem5)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

// ── Order 클래스를 선언하세요 ──────────────────────────────────
class Order {
    // TODO
};

// TODO: totalOrders 변수를 0 으로 초기화하세요.

// TODO: 멤버 함수를 구현하세요.


// ── runner (수정하지 마세요) ───────────────────────────────────
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
// ─────────────────────────────────────────────────────────────