#ifndef TEST_TASK_ASKON_SETPOINTS_H
#define TEST_TASK_ASKON_SETPOINTS_H

#include <set>
#include "Point.h"

class SetPoints {
public:
    std::set<Point> data;

    SetPoints();

    ~SetPoints() = default;

    void append(const Point &);

    void append(const double &, const double &);

    size_t size() const;

    auto begin() const -> decltype(data.begin());

    auto end() const -> decltype(data.end());

};

#endif //TEST_TASK_ASKON_SETPOINTS_H
