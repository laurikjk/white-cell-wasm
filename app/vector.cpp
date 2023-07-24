#include <cmath>
#include <emscripten/bind.h>

using namespace emscripten;

class Vector {
  public:
    Vector(float x, float y): x(x), y(y) {}

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector add(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }

    Vector subtract(const Vector& v) const {
        return Vector(x - v.x, y - v.y);
    }

    Vector divideScalar(float s) const {
        return Vector(x / s, y / s);
    }

    Vector multiplyScalar(float s) const {
        return Vector(x * s, y * s);
    }

    float dot(const Vector& v) const {
        return x * v.x + y * v.y;
    }

    Vector normalize() const {
        return this->divideScalar(this->length());
    }

    Vector reverse() const {
        return Vector(-x, -y);
    }

    bool isApproximately(const Vector& v, float epsilon = 0.0001f) const {
        return std::abs(x - v.x) < epsilon && std::abs(y - v.y) < epsilon;
    }

    Vector scale(float length) const {
        return this->normalize().multiplyScalar(length);
    }

    float x, y;
};

EMSCRIPTEN_BINDINGS(my_class_example) {
    class_<Vector>("Vector")
        .constructor<float, float>()
        .function("length", &Vector::length)
        .function("add", &Vector::add)
        .function("subtract", &Vector::subtract)
        .function("divideScalar", &Vector::divideScalar)
        .function("multiplyScalar", &Vector::multiplyScalar)
        .function("dot", &Vector::dot)
        .function("normalize", &Vector::normalize)
        .function("reverse", &Vector::reverse)
        .function("isApproximately", &Vector::isApproximately)
        .function("scale", &Vector::scale)
        .property("x", &Vector::x)
        .property("y", &Vector::y)
    ;
}
