#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double EPS = 1e-6;

class Point
{
    double x, y;

public:
    Point(double X = 0, double Y = 0) : x(X), y(Y){};

    double
    getX() const
    {
        return x;
    }

    double
    getY() const
    {
        return y;
    }

    friend bool equals(const Point &A, const Point &B);
};

bool
equals(const Point &A, const Point &B)
{
    return std::abs(A.x - B.x) < EPS && std::abs(A.y - B.y) < EPS;
}

class Line
{
    double a, b, c;

public:
    Line() : a(0), b(0), c(0){};

    Line(const Point &A, const Point &B)
    {
        double A_x = A.getX(), A_y = A.getY(), B_x = B.getX(), B_y = B.getY();
        if (equals(A, B)) {
            a = 0;
            b = 1;
            c = -A_y;
        } else {
            a = A_y - B_y;
            b = B_x - A_x;
            c = A_x * B_y - B_x * A_y;
        }
    }

    friend int intersecting(const Line &A, const Line &B);

    friend Point intersect(const Line &A, const Line &B);
};

int
intersecting(const Line &A, const Line &B)
{
    if (std::abs(A.a * B.b - B.a * A.b) < EPS) {
        if (std::abs(A.a * B.c - A.c * B.a) < EPS && std::abs(A.b * B.c - A.c * B.b) < EPS) {
            return 2;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

Point
intersect(const Line &A, const Line &B)
{
    double x = -(A.c * B.b - B.c * A.b) / (A.a * B.b - B.a * A.b);
    double y = -(A.a * B.c - B.a * A.c) / (A.a * B.b - B.a * A.b);
    return {x, y};
}

int
main()
{
    using std::cin, std::cout, std::endl;
    Point pts[2];
    Line lns[2];
    double x, y;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> x >> y;
            pts[j] = Point(x, y);
        }
        lns[i] = Line(pts[0], pts[1]);
    }
    int inter = intersecting(lns[0], lns[1]);
    cout << inter << endl;
    if (inter == 1) {
        Point inter_pnt = intersect(lns[0], lns[1]);
        cout << std::setprecision(6) << inter_pnt.getX() << " " << inter_pnt.getY() << endl;
    }
    return 0;
}
