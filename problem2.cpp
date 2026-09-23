/*
 * Problem 2: Encapsulation and this Pointer
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * BankAccount class 의 TODO 함수를 구현하세요.
 *
 *  setBalance(balance) : this->balance 를 사용하여 balance 를 설정합니다.
 *  deposit(amount)     : amount > 0 이면 balance 에 더하고 true 반환.
 *                        amount <= 0 이면 아무것도 하지 않고 false 반환.
 *  withdraw(amount)    : amount > 0 이고 amount <= balance 이면
 *                        balance 에서 빼고 true 반환.
 *                        그 외에는 아무것도 하지 않고 false 반환.
 *  getBalance()        : balance 를 반환합니다. (const 필수)
 *
 * 주의: exception 은 사용하지 말고 bool 반환값으로 처리하세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;
public:
    // TODO: this->balance 를 사용하여 balance 를 설정하세요.
    void setBalance(int balance);

    // TODO: amount > 0 이면 balance 에 더하고 true 를 반환하세요.
    //       amount <= 0 이면 아무것도 하지 않고 false 를 반환하세요.
    bool deposit(int amount);

    // TODO: amount > 0 이고 amount <= balance 이면 balance 에서 빼고 true 를 반환하세요.
    //       그 외에는 아무것도 하지 않고 false 를 반환하세요.
    bool withdraw(int amount);

    // TODO: balance 를 반환하세요. (const 필수)
    int getBalance() const;
};

void BankAccount::setBalance(int balance) {
    // TODO: this->balance 를 반드시 사용하세요.
}

bool BankAccount::deposit(int amount) {
    // TODO
    return false;
}

bool BankAccount::withdraw(int amount) {
    // TODO
    return false;
}

int BankAccount::getBalance() const {
    // TODO
    return 0;
}

// ── runner (수정하지 마세요) ───────────────────────────────────────────
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
