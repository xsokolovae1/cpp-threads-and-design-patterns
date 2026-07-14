#include <iostream>
#include <vector>
using namespace std;

struct Point { float x, y, z; };
using Path = vector<Point>;


class IPlanner {
public:
    virtual Path plan() = 0;
};

class RRTPlanner : public IPlanner {
public:
    Path plan() override {
        cout << "RRT planning\n";
        return {{1,1,1}};
    }
};

class AStarPlanner : public IPlanner {
public:
    Path plan() override {
        cout << "A* planning\n";
        return {{0,0,0}};
    }
};

class SmoothedPlanner : public IPlanner {
    IPlanner* inner;
public:
    SmoothedPlanner(IPlanner* p) {
        inner = p;
    }
    Path plan() override {
        Path path = inner->plan();
        cout << "Smoothing\n";
        return path;
    }
};


class Navigator {
public:
    Path computePath(IPlanner* planner) {
        return planner->plan();
    }
};

/
class Robot {
public:
    void move(const Path& path) {
        for (auto& p : path)
            cout << "Move to " << p.x << "," << p.y << "," << p.z << "\n";
    }
};


int main() {
    RRTPlanner rrt;
    SmoothedPlanner smoothed(&rrt);

    Navigator nav;
    Robot robot;

    Path path = nav.computePath(&smoothed);
    robot.move(path);
}
