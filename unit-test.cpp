#include "func.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Student Comparison") {
    Student s1("Matas", "Karantinas", 4.54),
            s2("Kovidas", "Devynioliktasis", 1.12),
            s3("Salomeja", "Neris", 10),
            s4("Salomeja", "Neris", 10);

    SECTION("Results (1st == 2nd)") {
        REQUIRE(s1 != s2);
        REQUIRE(s3 == s4);
    }
    SECTION("Results (1st > 2nd)") {
        REQUIRE(s1 > s2);
        REQUIRE(s4 <= s3);
    }
    SECTION("Surnames (1st >= 2nd)") {
        REQUIRE(s1.getSurname() >= s2.getSurname());
        REQUIRE(s3.getSurname() >= s4.getSurname());
    }
}
TEST_CASE("Result calculation") {
    vector<double> hw1{1, 5, 8, 4}, hw2{1, 6, 8};
    Student s1("Matas", "Karantinas", hw1, 10),
            s2("Kovidas", "Devynioliktasis", hw2, 5);
    vector<Student> stud;
    stud.push_back(s1);
    stud.push_back(s2);
    stud.shrink_to_fit();

    CalculateV(stud, false);
    SECTION("Result by Average") {
        REQUIRE( stud[0] == 7.80);
        REQUIRE( stud[1] == 5.0 );
    }
    CalculateV(stud, true);
    SECTION("Result by Median") {
        REQUIRE( stud[0] == 7.80);
        REQUIRE( stud[1] == 5.4 );
    }
    Student s3("Lukas", "Karantinas", hw1, 3);
    s3 = s2;
    stud.push_back(s3);
    stud.shrink_to_fit();
    SECTION("Results (2nd == 3rdd)") {
        REQUIRE(s3 == s2);
    }
}