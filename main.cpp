// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

void vec4AddTest() {
	vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
	vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
	std::cout << "vec4 + vec4 expected value: (3.0, 6.0, 9.0, 12.0)" << std::endl;
	std::cout << "vec4 + vec4 actual value: " << (a + b) << std::endl;
}

void vec4Tests() {
    vec4 defVec;
    cout << "Default Constructor" << endl;


    cout << "Expected: [0.0000, 0.0000, 0.0000, 0.0000]" << endl;
    cout << "Actual: " << defVec << endl;


    vec4 temp(1.0f, 2.0f, 3.0f, 4.0f);
    cout << "Four float constructor" << endl;
    cout << "Expected: [1.0000, 2.0000, 3.0000, 4.0000]" << endl;
    cout << "Actual: " << temp << endl;

    vec4 copied(temp);
    cout << "Copied four float vec" << endl;
    cout << "Expected: [1.0000, 2.0000, 3.0000, 4.0000]" << endl;
    cout << "Actual: " << copied << endl;

    vec4 assigned;
    assigned = temp;
    cout << "Assigned four float vec" << endl;
    cout << "Expected: [1.0000, 2.0000, 3.0000, 4.0000]" << endl;
    cout << "Actual: " << assigned << endl;

    cout << "Equal Operator" << endl;
    cout << "Expected: true" << endl;
    cout << "Actual: " << (temp == copied ? true : false) << endl;

    vec4 different(4.0f, 3.0f, 2.0f, 1.0f);
    cout << "Not Equal Operator" << endl;
    cout << "Expected: true" << endl;
    cout << "Actual: " << (temp != different ? true : false) << endl;


    cout << "Dot Product" << endl;
    cout << "Expected: 20" << endl;
    cout << "Actual: " << dot(temp, different) << endl;

    vec4 vec1(1.0f, 0.0f, 0.0f, 0.0f);
    vec4 vec2(0.0f, 1.0f, 0.0f, 0.0f);
    cout << "Cross Product" << endl;
    cout << "Expected: [0.0000, 0.0000, 1.0000, 0.0000]" << endl;
    cout << "Actual: " << cross(vec1, vec2) << endl;

    vec4 normalised(3.0f, 0.0f, 0.0f, 4.0f);
    cout << "Normalised" << endl;
    cout << "Expected: [0.6000, 0.0000, 0.0000, 0.8000]" << endl;
    cout << "Actual: " << normalize(normalised) << endl;
}

void mat4Tests() {
    cout << "Mat4 Tests" << endl;
    mat4 identityMat;
    cout << "Default constructor" << endl;
    cout << "Expected:" << endl;
    cout << "[1.0000, 0.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, 1.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 1.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 0.0000, 1.0000]" << endl;
    cout << "Actual: " << endl;
    cout << identityMat << endl;

    mat4 diagonal(5.0f);
    cout << "Diagonal constructor" << endl;
    cout << "Expected:" << endl;
    cout << "[5.0000, 0.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, 5.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 5.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 0.0000, 5.0000]" << endl;
    cout << "Actual: " << endl;
    cout << diagonal << endl;

    mat4 temp(
        vec4(2.0f, 4.0f, 6.0f, 8.0f),
        vec4(3.0f, 5.0f, 7.0f, 9.0f),
        vec4(2.0f, 4.0f, 6.0f, 8.0f),
        vec4(3.0f, 5.0f, 7.0f, 9.0f)
        );

    cout << "Four-Col constructor" << endl;
    cout << "Expected:" << endl;
    cout << "[2.0000, 3.0000, 2.0000, 3.0000]" << endl;
    cout << "[4.0000, 5.0000, 4.0000, 5.0000]" << endl;
    cout << "[6.0000, 7.0000, 6.0000, 7.0000]" << endl;
    cout << "[8.0000, 9.0000, 8.0000, 9.0000]" << endl;
    cout << "Actual: " << endl;
    cout << temp << endl;

    mat4 copied(temp);
    cout << "Copied Four-Col Mat" << endl;
    cout << "Expected:" << endl;
    cout << "[2.0000, 3.0000, 2.0000, 3.0000]" << endl;
    cout << "[4.0000, 5.0000, 4.0000, 5.0000]" << endl;
    cout << "[6.0000, 7.0000, 6.0000, 7.0000]" << endl;
    cout << "[8.0000, 9.0000, 8.0000, 9.0000]" << endl;
    cout << "Actual: " << endl;
    cout << copied << endl;

    mat4 assigned;
    assigned = temp;
    cout << "Assigned Four-Col Mat" << endl;
    cout << "Expected:" << endl;
    cout << "[2.0000, 3.0000, 2.0000, 3.0000]" << endl;
    cout << "[4.0000, 5.0000, 4.0000, 5.0000]" << endl;
    cout << "[6.0000, 7.0000, 6.0000, 7.0000]" << endl;
    cout << "[8.0000, 9.0000, 8.0000, 9.0000]" << endl;
    cout << "Actual: " << endl;
    cout << assigned << endl;

    cout << "Equal Operator" << endl;
    cout << "Expected: true" << endl;
    cout << "Actual: " << (temp == copied) << endl;

    cout << "Not Equal Operator" << endl;
    cout << "Expected: true" << endl;
    cout << "Actual: " << (temp != diagonal) << endl;

    mat4 rot90 = mat4::rotate(90.0f, 0.0f, 0.0f, 1.0f);
    cout << "90 deg rotation around z" << endl;
    cout << "Expected: " << endl;
    cout << "[0.0000, -1.0000, 0.0000, 0.0000]" << endl;
    cout << "[1.0000, 0.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 1.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 0.0000, 1.0000]" << endl;
    cout << "Actual: " << endl;
    cout << rot90 << endl;

    mat4 rot180 = mat4::rotate(180.0f, 1.0f, 0.0f, 0.0f);
    cout << "180 deg rotation around x" << endl;
    cout << "Expected: " << endl;
    cout << "[1.0000, 0.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, -1.0000, 0.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, -1.0000, 0.0000]" << endl;
    cout << "[0.0000, 0.0000, 0.0000, 1.0000]" << endl;
    cout << "Actual: " << endl;
    cout << rot180 << endl;

    mat4 scaleMat = mat4::scale(2.0f, 3.0f, 4.0f);
    cout << "Matrix Matrix using Scale" << endl;
    cout << "Expected: " << endl;
    cout << "[4.0000, 9.0000, 8.0000, 3.0000]" << endl;
    cout << "[8.0000, 15.0000, 16.0000, 5.0000]" << endl;
    cout << "[12.0000, 21.0000, 24.0000, 7.0000]" << endl;
    cout << "[16.0000, 27.0000, 32.0000, 9.0000]" << endl;
    cout << "Actual:" << endl;
    cout << (temp * scaleMat) << endl;

    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
    cout << "Matrix-Vector Multiplication" << endl;
    cout << "Expected: [26.0000, 46.0000, 66.0000, 86.0000]" << endl;
    cout << "Actual: " << (temp * vec) << endl;

    cout << "Vector-Matrix Multiplication" << endl;
    cout << "Expected: [60.0000, 70.0000, 60.0000, 70.0000]" << endl;
    cout << "Actual: " << (vec * temp) << endl;

}
int main() {
    cout << boolalpha;
	// Example test (won't work until you implement vec4's operator+ and operator<<)
	vec4AddTest();
	// Add your own tests here
    vec4Tests();
    mat4Tests();

}
