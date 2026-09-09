#include "mat4.h"
#include <stdexcept>
#include <cmath>
#include <iomanip>

mat4::mat4() : data{
        vec4(1.0f,0.0f,0.0f,0.0f),
        vec4(0.0f,1.0f,0.0f,0.0f),
        vec4(0.0f,0.0f,1.0f,0.0f),
        vec4(0.0f,0.0f,0.0f,1.0f)} {}

mat4::mat4(float diag) : data{
        vec4(diag,0.0f,0.0f,0.0f),
        vec4(0.0f,diag,0.0f,0.0f),
        vec4(0.0f,0.0f,diag,0.0f),
        vec4(0.0f,0.0f,0.0f,diag)} {}


mat4::mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4& col3) :
    data{col0, col1, col2, col3} {}

mat4::mat4(const mat4 &m2) : data(m2.data) {}


vec4  mat4::operator[](unsigned int index) const {
    if(index >= data.size()) throw std::out_of_range("matrix index out of range 1.");
    return data[index];
}

/// Returns a reference to the column at the index
vec4& mat4::operator[](unsigned int index) {
    if(index >= data.size()) throw std::out_of_range("matrix index out of range 2.");
    return data[index];
}

mat4 mat4::rotate(float angle, float x, float y, float z) {
    float length = std::sqrt((x*x) + (y*y) + (z*z));
    x = x / length;
    y = y / length;
    z = z / length;

    float pi = std::acos(-1.0f);
    float theta = angle * pi / 180.0f;
    float c = std::cos(theta), s = std::sin(theta);
    float t = 1.0f - c;

    return mat4(
        vec4(t*x*x + c, t*x*y + s*z, t*x*z - s*y, 0.0f),
        vec4(t*x*y - s*z, t*y*y + c, t*y*z + s*x, 0.0f),
        vec4(t*x*z + s*y, t*y*z - s*x, t*z*z + c, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
        );
}

/// Takes an xyz displacement and outputs a 4x4 translation matrix
mat4 mat4::translate(float x, float y, float z) {
    mat4 matrix;
    matrix[3][0] = x;
    matrix[3][1] = y;
    matrix[3][2] = z;
    return matrix;
}

mat4 mat4::scale(float x, float y, float z) {
    mat4 matrix;
    matrix[0][0] = x;
    matrix[1][1] = y;
    matrix[2][2] = z;
    return matrix;
}

/// Generates a 4x4 identity matrix
mat4 mat4::identity() {
    return mat4();
}


/// Operator Functions
mat4& mat4::operator=(const mat4 &m2) {
    data = m2.data;
    return *this;
}

bool mat4::operator==(const mat4 &m2) const {
    return data == m2.data;
}

bool mat4::operator!=(const mat4 &m2) const {
    return !(data == m2.data);
}

mat4& mat4::operator+=(const mat4 &m2) {
    for(size_t i = 0; i < data.size(); i++) {
        data[i] += m2.data[i];
    }
    return *this;
}

mat4& mat4::operator-=(const mat4 &m2) {
    for(size_t i = 0; i < data.size(); i++) {
        data[i] -= m2.data[i];
    }
    return *this;
}


mat4& mat4::operator*=(float c) {
    for(auto& vec : data) {
        vec *= c;
    }
    return *this;
}

mat4& mat4::operator/=(float c) {
    for(auto& vec : data) {
        vec /= c;
    }
    return *this;
}

mat4  mat4::operator+(const mat4 &m2) const {
    mat4 result(*this);
    result += m2;
    return result;
}

mat4 mat4::operator-(const mat4 &m2) const {
    mat4 result(*this);
    result -= m2;
    return result;
}

mat4 mat4::operator*(float c) const {
    mat4 result(*this);
    result *= c;
    return result;
}

mat4 mat4::operator/(float c) const {
    mat4 result(*this);
    result /= c;
    return result;
}

mat4 mat4::operator*(const mat4 &m2) const {
    vec4 row0(data[0][0], data[1][0], data[2][0], data[3][0]);
    vec4 row1(data[0][1], data[1][1], data[2][1], data[3][1]);
    vec4 row2(data[0][2], data[1][2], data[2][2], data[3][2]);
    vec4 row3(data[0][3], data[1][3], data[2][3], data[3][3]);

    return mat4(
        vec4(dot(row0, m2[0]), dot(row1, m2[0]), dot(row2, m2[0]), dot(row3, m2[0])),
        vec4(dot(row0, m2[1]), dot(row1, m2[1]), dot(row2, m2[1]), dot(row3, m2[1])),
        vec4(dot(row0, m2[2]), dot(row1, m2[2]), dot(row2, m2[2]), dot(row3, m2[2])),
        vec4(dot(row0, m2[3]), dot(row1, m2[3]), dot(row2, m2[3]), dot(row3, m2[3]))
        );
}

vec4 mat4::operator*(const vec4 &v) const {
    vec4 row0(data[0][0], data[1][0], data[2][0], data[3][0]);
    vec4 row1(data[0][1], data[1][1], data[2][1], data[3][1]);
    vec4 row2(data[0][2], data[1][2], data[2][2], data[3][2]);
    vec4 row3(data[0][3], data[1][3], data[2][3], data[3][3]);

    return vec4(
        dot(row0, v),
        dot(row1, v),
        dot(row2, v),
        dot(row3, v)
        );
}

mat4 transpose(const mat4 &m) {
    return mat4(
        vec4(m[0][0], m[1][0], m[2][0], m[3][0]),
        vec4(m[0][1], m[1][1], m[2][1], m[3][1]),
        vec4(m[0][2], m[1][2], m[2][2], m[3][2]),
        vec4(m[0][3], m[1][3], m[2][3], m[3][3])
        );
}

vec4 row(const mat4 &m, unsigned int index) {
    if(index >= 4) throw std::out_of_range("mat4 row index out of range.");
    return vec4(m[0][index], m[1][index], m[2][index], m[3][index]);
}

mat4 operator*(float c, const mat4 &m) {
    return m * c;
}

vec4 operator*(const vec4&v, const mat4 &m) {
    return vec4(
        dot(v, m[0]),
        dot(v, m[1]),
        dot(v, m[2]),
        dot(v, m[3])
        );
}

std::ostream &operator<<(std::ostream &o, const mat4 &m) {
    o << row(m, 0) << '\n' << row(m, 1) << '\n' << row(m, 2) << '\n' << row(m, 3);
    return o;
}





