/*
 * Problem 3: Static Members
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 요구사항에 맞게 class Student 를 직접 정의하고 구현하세요.
 *
 * [class Student]
 *   - score         : 객체마다 별도로 가지는 점수
 *   - studentNumber : 이 학생의 등록 번호 (초기값 0)
 *   - totalStudents : 등록된 학생 수
 *       - [중요] s1, s2, s3 중 어떤 객체를 통해 접근해도 항상 같은 값을 가져야 합니다.
 *         특정 객체에 속하는 것이 아니라 클래스 전체에서 단 하나만 존재합니다.
 *
 *   - void setScore(int newScore)
 *   - int getScore() const
 *   - int getStudentNumber() const
 *   - void registerStudent()     : totalStudents 를 1 증가시키고, 그 값을 studentNumber 에 저장합니다.
 *   - int getTotalStudents() const
 *
 *   ※ 위 특징을 만족하는 선언 방법과 초기화 방법을 고민해보세요.
 *
 * runner 함수(runProblem3)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

// ── Student 클래스를 구현하세요 ──────────────────────────────────
class Student {
public:
    void setScore(int newScore) {}
    int getScore() const { return 0; }
    int getStudentNumber() const { return 0; }
    void registerStudent() {}
    int getTotalStudents() const { return 0; }
};

// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem3(istream& in) {
    int sc1, sc2, sc3;
    in >> sc1 >> sc2 >> sc3;

    cout << "=== Problem 3: Static Members ===" << "\n";

    Student s1, s2, s3;
    s1.setScore(sc1);
    s2.setScore(sc2);
    s3.setScore(sc3);

    cout << "[Part 1] Before registration" << "\n";
    cout << "s1.getTotalStudents() = " << s1.getTotalStudents() << "\n";

    cout << "[Part 2] Register s1" << "\n";
    s1.registerStudent();
    cout << "s1: studentNumber = " << s1.getStudentNumber()
         << ", score = " << s1.getScore()
         << ", totalStudents = " << s1.getTotalStudents() << "\n";

    cout << "[Part 3] Register s2" << "\n";
    s2.registerStudent();
    cout << "s2: studentNumber = " << s2.getStudentNumber()
         << ", score = " << s2.getScore()
         << ", totalStudents = " << s2.getTotalStudents() << "\n";

    cout << "[Part 4] Register s3" << "\n";
    s3.registerStudent();
    cout << "s3: studentNumber = " << s3.getStudentNumber()
         << ", score = " << s3.getScore()
         << ", totalStudents = " << s3.getTotalStudents() << "\n";

    // static 으로 구현했다면 s1, s2, s3 모두 같은 totalStudents 값을 반환합니다.
    cout << "[Part 5] studentNumber(per-object) vs totalStudents(shared)" << "\n";
    cout << "s1: studentNumber = " << s1.getStudentNumber()
         << ", totalStudents = " << s1.getTotalStudents() << "\n";
    cout << "s2: studentNumber = " << s2.getStudentNumber()
         << ", totalStudents = " << s2.getTotalStudents() << "\n";
    cout << "s3: studentNumber = " << s3.getStudentNumber()
         << ", totalStudents = " << s3.getTotalStudents() << "\n";
}
// ─────────────────────────────────────────────────────────────