#ifndef main

const double EPS = 1e-1;

const double PI = 3.14159265;

template<class Type>
class Point {
public:
	Type x, y;

	Point();
	Point(const Type& , const Type& );

	bool operator==(Point<Type>& other);
};

template<class Type>
std::ostream& operator << (std::ostream&, const Point<Type>&);

template<class Type>
class PointArray {
public:
	int size;
	std::unique_ptr<Point<Type>[]> value;

	PointArray();

	PointArray<Type>(const int&);

	~PointArray();

	
};

template<class Type>
class Figure {
public:
	PointArray<Type> points;

	Figure();

	~Figure();

	bool IsFigure();

	Point<Type> Center();

	operator double();

	bool operator==(const Figure&);

	void operator=(const Figure&);

	void operator=(Figure&&) noexcept;
};

template<class Type>
class Rhombus : public Figure<Type> {
public:
	Rhombus();
};

template<class Type>
class Pentagon : public Figure<Type> {
public:
	Pentagon();
};

template<class Type>
class Hexagon : public Figure<Type> {
public:
	Hexagon();
};

template<class Type>
class FigureArray {
public:
	int size;
	std::unique_ptr<Figure<Type>[]> value;

	FigureArray();

	FigureArray(const int );

	double AreaSum();

	void Area();

	void Center();

	void Delete(const int );

	~FigureArray();
};

template<class Type>
std::istream& operator>>(std::istream& , Figure<Type>& );

template<class Type>
std::ostream& operator<<(std::ostream& , const Figure<Type>& );
#endif 