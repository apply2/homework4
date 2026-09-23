/*
 * Problem 2: Encapsulation and this Pointer
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 class 선언을 참고하여 각 member function 을 class 외부에서 구현하세요.
 *
 *  - 잘못된 입력은 exception 대신 bool 반환값으로 처리합니다.
 *  - class 선언부는 수정하지 마세요.
 *
 * runner 함수(runProblem2)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;
public:
    // balance 를 설정합니다.
    void setBalance(int balance);

    // amount > 0 이면 balance 에 더하고 true 를 반환합니다.
    // amount <= 0 이면 아무것도 하지 않고 false 를 반환합니다.
    bool deposit(int amount);

    // amount > 0 이고 amount <= balance 이면 balance 에서 빼고 true 를 반환합니다.
    // 그 외에는 아무것도 하지 않고 false 를 반환합니다.
    bool withdraw(int amount);

    // 현재 balance 를 반환합니다.
    int getBalance() const;
};

// TODO: setBalance 를 구현하세요.

// TODO: deposit 를 구현하세요.

// TODO: withdraw 를 구현하세요.

// TODO: getBalance 를 구현하세요.

// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem2(istream& in) {
    int initialBalance, depositAmount, badDepositAmount, withdrawAmount, badWithdrawAmount;
    in >> initialBalance >> depositAmount >> badDepositAmount
       >> withdrawAmount >> badWithdrawAmount;

    cout << "=== Problem 2: Encapsulation and this ===" << "\n";

    BankAccount acc;
    acc.setBalance(initialBalance);

    cout << "[Part 1] Initial state" << "\n";
    cout << "balance = " << acc.getBalance() << "\n";

    cout << "[Part 2] deposit(" << depositAmount << ")" << "\n";
    bool r = acc.deposit(depositAmount);
    cout << "result = " << (r ? "true" : "false") << "\n";
    cout << "balance = " << acc.getBalance() << "\n";

    cout << "[Part 3] deposit(" << badDepositAmount << ")" << "\n";
    r = acc.deposit(badDepositAmount);
    cout << "result = " << (r ? "true" : "false") << "\n";
    cout << "balance = " << acc.getBalance() << "\n";

    cout << "[Part 4] withdraw(" << withdrawAmount << ")" << "\n";
    r = acc.withdraw(withdrawAmount);
    cout << "result = " << (r ? "true" : "false") << "\n";
    cout << "balance = " << acc.getBalance() << "\n";

    cout << "[Part 5] withdraw(" << badWithdrawAmount << ")" << "\n";
    r = acc.withdraw(badWithdrawAmount);
    cout << "result = " << (r ? "true" : "false") << "\n";
    cout << "balance = " << acc.getBalance() << "\n";
}
// ─────────────────────────────────────────────────────────────