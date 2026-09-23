/*
 * Problem 3: Static Members
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * Student class 의 TODO 함수를 구현하세요.
 *
 *  setScore(newScore)     : score 를 newScore 로 설정합니다.
 *  getScore()             : score 를 반환합니다. (const 필수)
 *  registerStudent()      : totalStudents 를 1 증가시킵니다.
 *  getTotalStudents()     : totalStudents 를 반환합니다. (static)
 *
 * 확인 사항:
 *  - static data member 는 모든 object 가 공유합니다.
 *  - static member function 은 object 없이 ClassName::func() 로 호출합니다.
 *  - static member function 은 non-static data member (score) 에 접근할 수 없습니다.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

class Student {
private:
    int score;
    static int totalStudents;   // 모든 Student object 가 공유하는 class-level 변수
public:
    // TODO: score 를 newScore 로 설정하세요.
    void setScore(int newScore);

    // TODO: score 를 반환하세요. (const 필수)
    int getScore() const;

    // TODO: totalStudents 를 1 증가시키세요.
    void registerStudent();

    // TODO: totalStudents 를 반환하세요. (static 유지)
    static int getTotalStudents();
};

// static member 정의 — 반드시 class 외부에서 한 번 정의합니다. (수정하지 마세요)
int Student::totalStudents = 0;

void Student::setScore(int newScore) {
    // TODO
}

int Student::getScore() const {
    // TODO
    return 0;
}

void Student::registerStudent() {
    // TODO
}

int Student::getTotalStudents() {
    // TODO
    return 0;
}

// ── runner (수정하지 마세요) ───────────────────────────────────────────
void runProblem3(istream& in) {
    int n;
    in >> n;

    cout << "=== Problem 3: Static Members ===" << "\n";

    cout << "[Part 1] Before registration" << "\n";
    cout << "totalStudents = " << Student::getTotalStudents() << "\n";

    Student students[10];
    cout << "[Part 2] Register students" << "\n";
    for (int i = 0; i < n; i++) {
        int score;
        in >> score;
        students[i].setScore(score);
        students[i].registerStudent();
        cout << "Student " << i << ": score = " << students[i].getScore() << "\n";
    }
    cout << "totalStudents after registration = " << Student::getTotalStudents() << "\n";

    cout << "[Part 3] Access via class name" << "\n";
    cout << "Student::getTotalStudents() = " << Student::getTotalStudents() << "\n";
}
