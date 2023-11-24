# pragma once

const double EPS = 1e-1;

const double PI = 3.14159265;

class Point {
public:
	double x, y;

	Point();
	Point(const double& , const double& );

	bool operator==(Point& other);
};

std::ostream& operator << (std::ostream&, const Point&);

class PointArray {
public:
	int size;
	Point* value;

	PointArray();


	PointArray(const int&);

	~PointArray();

	
};

class Figure {
public:
	PointArray points;

	Figure();

	~Figure();

	bool IsFigure();

	Point Center();

	operator double();

	bool operator==(const Figure&);

	void operator=(const Figure&);

	void operator=(Figure&&) noexcept;
};

class Rhombus : public Figure {
public:
	Rhombus();
};

class Pentagon : public Figure {
public:
	Pentagon();
};

class Hexagon : public Figure {
public:
	Hexagon();
};

class FigureArray {
public:
	int size;
	Figure* value;

	FigureArray();

	FigureArray(const int );

	double AreaSum();

	void Area();

	void Center();

	void Delete(const int );

	~FigureArray();
};

std::istream& operator>>(std::istream& , Figure& );

std::ostream& operator<<(std::ostream& , const Figure& );
