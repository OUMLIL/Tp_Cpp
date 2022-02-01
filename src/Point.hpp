#pragma once


class Point {
    private:
        int x{}, y{};
        //static const Point ORIGINE;
    public: 
        Point(int x, int y);
        Point();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
};

extern Point ORIGINE;