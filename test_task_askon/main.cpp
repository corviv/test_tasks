#include <iostream>
#include <vector>
#include <algorithm>
#include <Point.h>
#include <fstream>
#include <set>
#include <SetPoints.h>

// std::vector
bool is_equal(const std::vector<Point> &a, const std::vector<Point> &b) {
    return (a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin()));
}

bool is_subset(const std::vector<Point> &a, const std::vector<Point> &b) {
    return std::includes(a.begin(), a.end(), b.begin(), b.end());
}

// std::set
bool is_equal(const std::set<Point> &a, const std::set<Point> &b) {
    return (a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin()));
}

bool is_subset(const std::set<Point> &a, const std::set<Point> &b) {
    return std::includes(a.begin(), a.end(), b.begin(), b.end());
}

// SetPoints
bool is_equal(const SetPoints &a, SetPoints &b) {
    return (a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin()));
}

bool is_subset(const SetPoints &a, const SetPoints &b) {
    return std::includes(a.begin(), a.end(), b.begin(), b.end());
}

double getValue(bool isCoordinate) {
    while (true) {
        double a;
        std::cin >> a;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Input number is invalid. Please try again.\n";
            continue;
        }

        if (!isCoordinate) {
            if (a <= 0 || a != int(a)) {
                std::cout << "Input number is invalid. Please try again.\n";
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                continue;
            }
        }
        std::cin.ignore(32767, '\n');
        return a;
    }
}

double getValue() {
    return getValue(true);
}

void setValues(int count_points, SetPoints &set) {
    double x, y;
    for (int i = 1; count_points > 0; ++i, --count_points) {
        std::cout << "Point " << i << "\n";
        std::cout << "Enter coordinate X:\n";
        x = getValue();
        std::cout << "Enter coordinate Y:\n";
        y = getValue();
        set.append(x, y);
    }
}

void manual_mode(SetPoints &set1, SetPoints &set2) {
    std::cout << "Manual input mode.\n";
    std::cout << "Each line must end with the Enter key\n";

    std::cout << "Enter the number of points for first set:\n";
    double count_points = 0;
    count_points = getValue(false);
    std::cout << "First set\n";
    setValues(count_points, set1);

    std::cout << "Enter the number of points for second set\n";
    count_points = getValue(false);
    std::cout << "Second set\n";
    setValues(count_points, set2);

    std::cout << "Enter completed.\n";
}

void file_mode(SetPoints &set1, SetPoints &set2, const char *fname1, const char *fname2) {
    std::cout << "File input mode.\n";

    std::ifstream file1(fname1);
    if (!file1) {
        std::cerr << "Could not be opened for reading!\n";
        exit(1);
    }
    std::ifstream file2(fname2);
    if (!file2) {
        std::cerr << "Could not be opened for reading!\n";
        exit(1);
    }

    while (file1) {
        double x, y;
        file1 >> x >> y;
        set1.append(x, y);
    }
    while (file2) {
        double x, y;
        file2 >> x >> y;
        set2.append(x, y);
    }
}

int main(int argc, char *argv[]) {

    using std::cout;
    using std::endl;

    SetPoints set1;
    SetPoints set2;

    if (argc <= 1) {
        manual_mode(set1, set2);
    } else {
        if (argc != 3) {
            std::cerr << "Too few arguments\n";
            exit(1);
        }
        file_mode(set1, set2, argv[1], argv[2]);
    }

    cout << "Result: \n";
    if (set1.size() == set2.size()) {
        if (is_equal(set1, set2)) {
            cout << "Sets is equals.\n";
            return 0;
        }
    }

    if (set1.size() > set2.size()) {
        if (is_subset(set1, set2)) {
            cout << "set2 is subset of set1.\n";
            return 0;
        }
    } else {
        if (is_subset(set2, set1)) {
            cout << "set1 is subset of set2.\n";
            return 0;
        }
    }

    cout << "Sets are not equal.\n";

    /*
     * Tests for std::vector & std:set
     *
    Point a{0.0, 1.1};
    Point b{-2, 3};
    Point c{1.1, 0.0};

    std::vector<Point> set1{a, b, c};
    std::vector<Point> set2{c, a};
    std::sort(set1.begin(), set1.end());
    std::sort(set2.begin(), set2.end());
    set1.erase(std::unique(set1.begin(), set1.end()), set1.end());
    set2.erase(std::unique(set2.begin(), set2.end()), set2.end());

    std::set<Point> set2{a, b, c};
    std::set<Point> set1{c, a};
    */

    return 0;
}