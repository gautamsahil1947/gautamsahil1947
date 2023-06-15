#include <iostream>

class Vec2 {
public:
    float x = 0;
    float y  = 0;

    Vec2() {}

    Vec2(float xin, float yin) 
    : x(xin), y(yin) {

    }

    Vec2 operator + (const Vec2& rhs) const {
        return Vec2(Vec2(x + rhs.x, y + rhs.y));
    }

    void add (const Vec2& v) {
        x += v.x;
        y += v.y;
    }

    void operator += (const Vec2& v) {
        x += v.x;
        y += v.y;
    }
};

int main() {

    Vec2 v1(199, 199);
    Vec2 v2(11, 10);

    Vec2 v3 = v1 + v2;
    std::cout << v3.x << " " << v3.y << std::endl;
}
