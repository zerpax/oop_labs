#include <iostream>
#include <algorithm>
#include <cmath>
#include "main.h"

using namespace std;



Point::Point() {
	x = 0;
	y = 0;
};

Point::Point(const double& x, const double& y) {
	this->x = x;
	this->y = y;
}

ostream& operator << (ostream& os, const Point& point) {
	os << point.x << ' ' << point.y << '\n';
	return os;
}

bool Point::operator==(Point& other) {
	if ((this->x - other.x) < EPS && (this->y - other.y) < EPS) {
		return true;
	}
	return false;
}

PointArray::PointArray() {
	size = 0;
	value = new Point[size];
}

PointArray::PointArray(const int& size) {
	this->size = size;
	value = new Point[size];
}

PointArray::~PointArray() {
	this->size = 0;
	delete[] value;
	value = nullptr;
}


Figure::Figure() {}

Figure::~Figure() {
	points.size = 0;
	delete[] points.value;
	points.value = nullptr;
}

Point Figure::Center() {
	Point center(0, 0);
	for (int i = 0; i < points.size; i++) {
		center.x += points.value[i].x;
		center.y += points.value[i].y;
	}
	center.x /= points.size;
	center.y /= points.size;

	return center;
}

Figure::operator double() {
	double area = 0;
	for (int i = 0; i < points.size; i++) {
		area += points.value[i].x * points.value[(i + 1) % points.size].y - points.value[i].y * points.value[(i + 1) % points.size].x;
	}

	return abs(area/2);
}


istream& operator>>(istream& is, Figure& figure) {
	for (int i = 0; i < figure.points.size; i++) {
		is >> figure.points.value[i].x >> figure.points.value[i].y;
	}
	if (figure.IsFigure()) {
		return is;
	}
	throw invalid_argument("Invalid figure");
}

ostream& operator<<(ostream& os, const Figure& figure) {
	for (int i = 0; i < figure.points.size; i++) {
		os << figure.points.value[i].x << ' ' << figure.points.value[i].y << ' ';
	}
	return os;
}

bool Figure::operator==(const Figure& other) {
	if (this->points.size == other.points.size){
		double this_side_squared =
			pow(this->points.value[0].x - this->points.value[1].x, 2) + pow(this->points.value[0].y - this->points.value[1].y, 2);
		double other_side_squared = 
			pow(other.points.value[0].x - other.points.value[1].x, 2) + pow(other.points.value[0].y - other.points.value[1].y, 2);
		
		double diff = abs(this_side_squared - other_side_squared);

		if (diff < EPS) {
			double this_cos[10], other_cos[10];
			for (int i = 0; i < points.size; i++) {
				Point vector1, vector2;
				vector2.x = this->points.value[(i + 2) % points.size].x - this->points.value[(i + 1) % points.size].x;
				vector2.y = this->points.value[(i + 2) % points.size].y - this->points.value[(i + 1) % points.size].y;

				vector1.x = this->points.value[(i + 1) % points.size].x - this->points.value[i].x;
				vector1.y = this->points.value[(i + 1) % points.size].y - this->points.value[i].y;

				this_cos[i] = 
					(vector1.x * vector2.x + vector1.y * vector2.y) /
					(sqrt(vector1.x * vector1.x + vector1.y * vector1.y) * sqrt(vector2.x * vector2.x + vector2.y * vector2.y));

				vector2.x = other.points.value[(i + 2) % points.size].x - other.points.value[(i + 1) % points.size].x;
				vector2.y = other.points.value[(i + 2) % points.size].y - other.points.value[(i + 1) % points.size].y;

				vector1.x = other.points.value[(i + 1) % points.size].x - other.points.value[i].x;
				vector1.y = other.points.value[(i + 1) % points.size].y - other.points.value[i].y;


				other_cos[i] = 
					(vector1.x * vector2.x + vector1.y * vector2.y) /
					(sqrt(vector1.x * vector1.x + vector1.y * vector1.y) * sqrt(vector2.x * vector2.x + vector2.y * vector2.y));
				

			}
			sort(this_cos, this_cos + this->points.size);
			sort(other_cos, other_cos + other.points.size);
			


			for (int i = 0; i < this->points.size; i++) {
				diff = abs(this_cos[i] - other_cos[i]);
				if (!(diff < EPS)) {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

void Figure::operator=(const Figure& other) {
	delete[] this->points.value;
	this->points.value = new Point[other.points.size];
	this->points.size = other.points.size;
	
	for (int i = 0; i < this->points.size; i++) {
		this->points.value[i] = other.points.value[i];
	}
	

}

void Figure::operator=(Figure&& other) noexcept {
	delete[] this->points.value;
	this->points.size = other.points.size;
	this->points.value = other.points.value;
	other.points.value = nullptr;
}

bool Figure::IsFigure() {
	double this_cos[10], sides[10];
	for (int i = 0; i < points.size; i++) {
		sides[i] = pow(this->points.value[(i + 1) % points.size].x - this->points.value[i].x, 2) +
			pow(this->points.value[(i + 1) % points.size].y - this->points.value[i].y, 2);
	}


	for (int i = 0; i < points.size - 1; i++) {
		if (abs(sides[i] - sides[i + 1]) > EPS) {
			return false;
		}
	}


	for (int i = 0; i < points.size; i++) {
		Point vector1, vector2;
		vector2.x = this->points.value[(i + 2) % points.size].x - this->points.value[(i + 1) % points.size].x;
		vector2.y = this->points.value[(i + 2) % points.size].y - this->points.value[(i + 1) % points.size].y;

		vector1.x = this->points.value[(i + 1) % points.size].x - this->points.value[i].x;
		vector1.y = this->points.value[(i + 1) % points.size].y - this->points.value[i].y;

		this_cos[i] =
			(vector1.x * vector2.x + vector1.y * vector2.y) /
			(sqrt(vector1.x * vector1.x + vector1.y * vector1.y) * sqrt(vector2.x * vector2.x + vector2.y * vector2.y));//косинус через скалярное произвеление
	}
	double sum_of_angles = 0;
	for (int i = 0; i < points.size; i++) {
		sum_of_angles += acos(this_cos[i]);
	}
	if (abs(sum_of_angles - 2*PI) > EPS) { //проверка на выпуклость: сумма углов = 360 (2pi)
		return false;
	}

	
	return true;
}


Rhombus::Rhombus() {
	points.size = 4;
	points.value = new Point[points.size];
}

Pentagon::Pentagon() {
	points.size = 5;
	points.value = new Point[points.size];
}

Hexagon::Hexagon() {
	points.size = 6;
	points.value = new Point[points.size];
}


FigureArray::FigureArray() {
	size = 0;
	value = new Figure[0];
}

FigureArray::FigureArray(const int size) {
	this->size = size;
	value = new Figure[size];
}

double FigureArray::AreaSum() {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += double(value[i]);
	}

	return sum;
}

void FigureArray::Area() {
	for (int i = 0; i < size; i++) {
		cout << double(value[i]);
	}
}

void FigureArray::Center() {
	for (int i = 0; i < size; i++) {
		cout << value[i].Center() << ' ';
	}
}

void FigureArray::Delete(const int index) {
	for (int i = index; i < size - 1; i++) {
		value[i] = value[i + 1];
	}
}

FigureArray::~FigureArray() {
	size = 0;
	delete[] value;
	value = nullptr;
}


