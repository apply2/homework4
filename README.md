## 개요

C++의 class 기초 개념을 실습합니다.  
총 5문제로 구성되어 있으며, 각 `problem*.cpp` 파일에 있는 클래스를 구현하세요.  
`main.cpp` 는 수정하지 않습니다.

---

## 개발 환경 준비

g++ 컴파일러가 필요합니다. 이미 설치되어 있다면 다음 단계로 넘어가세요.

| 운영체제 | 설치 방법 |
|---|---|
| Windows | [MSYS2](https://www.msys2.org/) 설치 후 `pacman -S mingw-w64-ucrt-x86_64-gcc` |
| macOS | 터미널에서 `xcode-select --install` |
| Linux (Ubuntu) | `sudo apt install build-essential` |

설치 확인:
```bash
g++ --version
```

---

## 파일 구조

```
homework4/
├── main.cpp              ← 수정 금지. 테스트 실행 로직 (테스트 데이터 파일을 읽어 실행).
├── problem1.cpp          ← Problem 1 구현 (struct vs class)
├── problem2.cpp          ← Problem 2 구현 (Encapsulation and this)
├── problem3.cpp          ← Problem 3 구현 (Static Members)
├── problem4.cpp          ← Problem 4 구현 (const Member Functions)
├── problem5.cpp          ← Problem 5 구현 (Integrated)
├── test4.sh              ← 채점 스크립트 (macOS / Linux)
├── test4.bat             ← 채점 스크립트 (Windows)
└── Test/
    ├── case1.txt         ← 테스트 케이스 1 입력 데이터
    ├── case2.txt         ← 테스트 케이스 2 입력 데이터
    ├── case3.txt         ← 테스트 케이스 3 입력 데이터
    ├── expected1.txt     ← 테스트 케이스 1 기대 출력
    ├── expected2.txt     ← 테스트 케이스 2 기대 출력
    └── expected3.txt     ← 테스트 케이스 3 기대 출력
```

---

## 문제 1 — struct vs class (`problem1.cpp`)

`struct` 와 `class` 의 차이를 이해하고, 두 타입을 직접 정의합니다.  
기본 접근 제어자(public/private)의 차이를 확인합니다.

| 타입 | 멤버 | 설명 |
|---|---|---|
| `struct Point` | `int x, y` | 기본 접근 제어자가 public — 외부에서 직접 접근 가능 |
| | `void print() const` | `"Point(x, y)"` 형식으로 출력 |
| | `int distanceSquared() const` | `x*x + y*y` 반환 |
| `class Rectangle` | `int width, height` (private) | 외부에서 직접 접근 불가 |
| | `Rectangle(int width, int height)` | 멤버 변수 초기화 |
| | `int area() const` | `width * height` 반환 |
| | `int perimeter() const` | `2*(width+height)` 반환 |
| | `void print() const` | `"Rectangle(width x height)"` 형식으로 출력 |
| | `void scale(int factor)` | `width`, `height` 에 `factor` 를 곱함 |

---

## 문제 2 — Encapsulation and this (`problem2.cpp`)

`private` 멤버 변수를 public 멤버 함수로만 접근하는 캡슐화를 실습합니다.  
파라미터 이름과 멤버 이름이 같을 때 `this->` 로 구분하는 방법을 확인합니다.

| 함수 | 설명 |
|---|---|
| `void setBalance(int balance)` | `this->balance` 를 초기화 |
| `bool deposit(int amount)` | `amount > 0` 이면 잔액에 더하고 `true` 반환, 아니면 `false` |
| `bool withdraw(int amount)` | `amount > 0` 이고 잔액 이하이면 빼고 `true` 반환, 아니면 `false` |
| `int getBalance() const` | 현재 잔액 반환 |

모든 함수는 클래스 외부에서 `BankAccount::` 를 붙여 정의합니다.

---

## 문제 3 — Static Members (`problem3.cpp`)

`static` 멤버 변수와 멤버 함수를 실습합니다.  
객체마다 독립적인 값과 모든 객체가 공유하는 값의 차이를 확인합니다.

| 멤버 | 설명 |
|---|---|
| `int score` | 객체마다 별도로 가지는 점수 |
| `int studentNumber` | 이 학생의 등록 번호 |
| `static int totalStudents` | 등록된 학생 수 — 모든 객체가 공유 |
| `void setScore(int newScore)` | 점수 설정 |
| `int getScore() const` | 점수 반환 |
| `int getStudentNumber() const` | 등록 번호 반환 |
| `void registerStudent()` | `totalStudents` 를 1 증가시키고 그 값을 `studentNumber` 에 저장 |
| `int getTotalStudents() const` | 전체 등록 학생 수 반환 |

---

## 문제 4 — const Member Functions (`problem4.cpp`)

객체의 상태를 변경하지 않는 함수에 `const` 를 붙이는 이유와 효과를 실습합니다.  
`const` 참조에서는 `const` 멤버 함수만 호출할 수 있음을 확인합니다.

| 멤버 | 설명 |
|---|---|
| `title`, `author` (string) | 생성 시 결정되며 이후 절대 변경 불가 |
| `price` (int) | 외부에서 조회 및 변경 가능 |
| `stock` (int) | 외부에서 조회만 가능. `restock` / `sell` 로만 변경 |
| `getTitle() const` 외 getter | 상태를 읽기만 하므로 `const` |
| `getTotalValue() const` | `price × stock`. 결과를 `const` 지역 변수에 저장 후 반환 |
| `setPrice(int p)` | `price` 변경 |
| `restock(int n)` | `stock` 을 `n` 만큼 증가 |
| `sell(int n)` | 재고가 충분하면 감소 후 `true`, 부족하면 `false` |
| `printInfo() const` | `title / author \| price: ... \| stock: ... \| total: ...` 형식 출력 |

---

## 문제 5 — Integrated (`problem5.cpp`)

앞서 배운 개념(`private/public`, `this`, `static`, `const`, `::`)을 종합하여  
`Order` 클래스를 처음부터 구현합니다.  
모든 멤버 함수는 클래스 선언부 바깥에서 `Order::` 를 붙여 정의합니다.

| 멤버 | 설명 |
|---|---|
| `int orderId` | 주문 번호 |
| `int quantity` | 주문 수량. `updateQuantity` 로만 변경 |
| `int unitPrice` | 단가 |
| `static int totalOrders` | 생성된 Order 객체의 총 수 — 모든 객체가 공유 |
| `getOrderId() const` 외 getter | 상태를 읽기만 하므로 `const` |
| `int totalPrice() const` | `quantity × unitPrice` 반환 |
| `bool updateQuantity(int quantity)` | `quantity > 0` 이면 `this->quantity` 업데이트 후 `true`, 아니면 `false` |
| `static int getTotalOrders()` | `totalOrders` 반환 |
| `void printInfo() const` | `Order id: qty = ..., unitPrice = ..., total = ...` 형식 출력 |

---

## 테스트 방법

```bash
# macOS / Linux
bash test4.sh

# Windows
test4.bat
```

테스트 케이스 3개를 순서대로 실행하며 각 문제별로 `PASS` / `FAIL` 을 출력합니다.  
`FAIL` 인 경우 기대 출력과 실제 출력의 차이를 함께 확인하세요.

테스트 데이터는 `Test/case1.txt` ~ `Test/case3.txt` 에 있으며,  
`main.cpp` 는 이 파일을 읽어 실행합니다 (`./hw4_main Test/case1.txt` 형식).

---

## 제출 방법 (git)

```bash
git add problem1.cpp problem2.cpp problem3.cpp problem4.cpp problem5.cpp
git commit -m "학번 이름"
git push
```

- push 후 저장소의 **Actions 탭** 에서 자동 채점 결과를 확인할 수 있습니다.
- 마감 전까지 몇 번이든 다시 제출할 수 있습니다.
