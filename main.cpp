#include "struct.h"
#include "func.h"

int main() {
    vector<Student> stud;
    stud.reserve(150);
    Input(stud);
    stud.shrink_to_fit();
    sort(begin(stud), end(stud), [](const Student &a1, const Student &a2 ) {
        return a1.surname.compare(a2.surname) < 0;
    });
    Calculate(stud);
    Print(stud);

    return 0;
}