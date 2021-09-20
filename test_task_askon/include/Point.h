#ifndef TEST_TASK_ASKON_POINT_H
#define TEST_TASK_ASKON_POINT_H

class Point {
public:
    explicit Point(double, double);

    ~Point() = default;

    bool operator==(const Point &) const;

    bool operator<(const Point &) const;

    double x;
    double y;
};

#endif //TEST_TASK_ASKON_POINT_H
