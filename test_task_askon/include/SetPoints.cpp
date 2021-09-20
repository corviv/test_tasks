#include "SetPoints.h"

SetPoints::SetPoints() = default;

void SetPoints::append(const Point &a) {
    data.emplace(a.x, a.y);
}

void SetPoints::append(const double &Px, const double &Py) {
    data.emplace(Px, Py);
}

size_t SetPoints::size() const {
    return data.size();
}

auto SetPoints::begin() const -> decltype(data.begin()) {
    return data.begin();
}

auto SetPoints::end() const -> decltype(data.end()) {
    return data.end();
}
