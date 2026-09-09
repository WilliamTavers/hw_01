#include "vec4.h"
#include <stdexcept>
#include <numeric>
#include <cmath>
#include <iomanip>

vec4::vec4() : data {} {}

vec4::vec4(float x, float y, float z, float w) : data{x, y, z, w} {}

vec4::vec4(const vec4 &v2) : data{v2.data} {}

/// Getters and Setters
float vec4::operator[](unsigned int index) const {
    if(index >= data.size()) throw std::out_of_range("vec4 index out of range.");
    return data[index];
}

float& vec4::operator[](unsigned int index) {
    if(index >= data.size()) throw std::out_of_range("vec4 index out of range.");
    return data[index];
}

/// Operator Functions
vec4& vec4::operator=(const vec4 &v2) {
    data = v2.data;
    return *this;
}

bool vec4::operator==(const vec4 &v2) const {
    return data[0] == v2[0] && data[1] == v2[1] && data[2] == v2[2] && data[3] == v2[3];
}


bool vec4::operator!=(const vec4 &v2) const {
    return !(*this==v2);
}

/// Arithmetic
vec4& vec4::operator+=(const vec4 &v2) {
    for(std::size_t i = 0; i < data.size(); i++) {
        data[i] += v2.data[i];
    }
    return *this;
}

vec4& vec4::operator-=(const vec4 &v2) {
    for(std::size_t i = 0; i < data.size(); i++) {
        data[i] -= v2.data[i];
    }
    return *this;
}
vec4& vec4::operator*=(float c) {
    for(auto& coordinate : data) {
        coordinate *= c;
    }
    return *this;
}

vec4& vec4::operator/=(float c) {
    for(auto& coordinate : data) {
        coordinate /= c;
    }
    return *this;
}

vec4  vec4::operator+(const vec4 &v2) const {
    vec4 result(*this);
    result += v2;
    return result;
}

vec4  vec4::operator-(const vec4 &v2) const {
    vec4 result(*this);
    result -= v2;
    return result;
}

vec4  vec4::operator*(float c) const {
    vec4 result(*this);
    result *= c;
    return result;
}

vec4  vec4::operator/(float c) const {
    vec4 result(*this);
    result /= c;
    return result;
}


/// Dot Product
float dot(const vec4 &v1, const vec4 &v2) {
    return (v1[0]*v2[0] + v1[1] * v2[1] + v1[2] * v2[2] + v1[3] * v2[3]);
}

/// Cross Product
vec4 cross(const vec4 &v1, const vec4 &v2) {
    return vec4(
            (v1[1] * v2[2]) - (v1[2] * v2[1]),
            (v1[2] * v2[0]) - (v1[0] * v2[2]),
            (v1[0] * v2[1]) - (v1[1] * v2[0]),
        0.0f);
}

/// Geometric Length
float length(const vec4 &v) {
    return std::sqrt(dot(v, v));
}

/// Scalar Multiplication
vec4 operator*(float c, const vec4 &v) {
    return v * c;
}

vec4 normalize(const vec4& v) {
    return v / length(v);
}
std::ostream &operator<<(std::ostream &o, const vec4 &v) {
    std::ios_base::fmtflags origFlags = o.flags();
    std::streamsize origPrecision = o.precision();

    o << std::fixed << std::setprecision(4);
    o << "[" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << "]";

    o.flags(origFlags);
    o.precision(origPrecision);

    return o;
}







