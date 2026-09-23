/*
 * Problem 4: const Member Functions
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 요구사항을 읽고 Book 클래스를 처음부터 구현하세요.
 *
 * [const 의 두 가지 용도]
 *
 *   ① 변수·멤버에 const 붙이기
 *       값이 한 번 정해지면 이후 변경할 수 없습니다.
 *
 *   ② 멤버 함수에 const 붙이기
 *       이 함수는 객체의 상태를 변경하지 않음을 컴파일러에 보장합니다.
 *
 * ─────────────────────────────────────────────────────────────
 * [데이터 멤버] (모두 private)
 *
 *   title  (string) : 책 제목. 생성 시 결정되며 [중요] 이후 절대 변경 불가.
 *   author (string) : 저자 이름. 생성 시 결정되며 [중요] 이후 절대 변경 불가.
 *   price  (int)    : 정가(원). 외부에서 조회 및 변경 가능.
 *   stock  (int)    : 재고 수량. 외부에서 조회만 가능.
 *                     restock / sell 함수로만 변경됨.
 *
 * [생성자]
 *   Book(title, author, price, stock) 으로 네 멤버를 초기화.
 *
 * [멤버 함수] — 상태를 변경하지 않는 함수에는 반드시 const 를 붙이세요.
 *
 *   getTitle()       string 반환   [중요] 객체 상태를 바꾸지 않음.
 *   getAuthor()      string 반환   [중요] 객체 상태를 바꾸지 않음.
 *   getPrice()       int 반환      [중요] 객체 상태를 바꾸지 않음.
 *   getStock()       int 반환      [중요] 객체 상태를 바꾸지 않음.
 *
 *   getTotalValue()  int 반환      price × stock 을 계산한다.
 *                                  계산 결과를 const 지역 변수에 저장한 뒤 반환.
 *                                  [중요] 객체 상태를 바꾸지 않음.
 *
 *   setPrice(int p)                price 를 p 로 변경.
 *                                  title / author / stock 은 건드리지 않음.
 *
 *   restock(int n)                 stock 을 n 만큼 증가.
 *
 *   sell(int n)      bool 반환     stock 이 n 이상이면 stock 에서 n 을 빼고
 *                                  true 를 반환한다.
 *                                  stock 이 부족하면 아무것도 바꾸지 않고
 *                                  false 를 반환한다.
 *
 *   printInfo()                    아래 형식으로 출력. 객체 상태를 바꾸지 않음.
 *     <title> / <author> | price: <price> | stock: <stock> | total: <totalValue>
 *     예) CleanCode / Martin | price: 30000 | stock: 20 | total: 600000
 *
 * runner 함수(runProblem4)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
#include <string>
using namespace std;

// ── Book 클래스를 구현하세요 ───────────────────────────────────
class Book {
    // TODO
};

// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem4(istream& in) {
    string title, author;
    int price, stock, newPrice, restockAmount, sellAmount;
    in >> title >> author >> price >> stock >> newPrice >> restockAmount >> sellAmount;

    cout << "=== Problem 4: const Member Functions ===" << "\n";

    Book book(title, author, price, stock);

    // const 참조: const 멤버 함수만 호출 가능
    cout << "[Part 1] const 참조로 읽기" << "\n";
    const Book& cRef = book;
    cout << "title = "      << cRef.getTitle()      << "\n";
    cout << "author = "     << cRef.getAuthor()     << "\n";
    cout << "price = "      << cRef.getPrice()      << "\n";
    cout << "stock = "      << cRef.getStock()      << "\n";
    cout << "totalValue = " << cRef.getTotalValue() << "\n";
    cRef.printInfo();

    // 상태 변경: non-const 멤버 함수 호출
    cout << "[Part 2] setPrice(" << newPrice << ")" << "\n";
    book.setPrice(newPrice);
    book.printInfo();

    cout << "[Part 3] restock(" << restockAmount << ")" << "\n";
    book.restock(restockAmount);
    book.printInfo();

    cout << "[Part 4] sell(" << sellAmount << ")" << "\n";
    bool ok = book.sell(sellAmount);
    cout << "sell result = " << (ok ? "success" : "fail") << "\n";
    book.printInfo();
}
// ─────────────────────────────────────────────────────────────
