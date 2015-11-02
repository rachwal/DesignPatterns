// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMMONS_POINT_H_
#define STRUCTURAL_COMMONS_POINT_H_

#include <iostream>

namespace structural
{
namespace commons
{
template<class type>
class Point
{
	public:
	Point();
	Point(const Point<type>&);
	Point(const type&, const type&);

	type x() const;
	void x(type x);
	type y() const;
	void y(type y);

	friend Point<type> operator+(const Point<type>& left, const Point<type>& right)
	{
		Point<type> left1(left);
		return left1 += right;
	}

	friend Point<type> operator-(const Point<type>& left, const Point<type>& right)
	{
		Point<type> left1(left);
		return left1 -= right;
	}

	Point<type> &operator+=(const Point<type>&);
	Point<type> &operator-=(const Point<type>&);
	Point<type> &operator*=(const type&);
	Point<type> &operator/=(const type&);

	Point<type> operator-();

	friend bool operator==(const Point<type>& left, const Point<type>& right)
	{
		bool x = left.x() == right.x();
		bool y = left.y() == right.y();
		return ((x == true) && (y == true));
	}

	friend bool operator!=(const Point<type>& left, const Point<type>& right)
	{
		return !(left == right);
	}

	friend std::ostream &operator<<(std::ostream& to, const Point<type>& point)
	{
		to << point.x() << " " << point.y();
		return to;
	}

	friend std::istream &operator>>(std::istream& from, Point<type>& point)
	{
		return from;
	}

	private:
	type x_;
	type y_;
};

template<class type>
Point<type>::Point() :Point<type>(0, 0) { }

template<class type>
Point<type>::Point(const type& x, const type& y) : x_(x), y_(y) { }

template<class type>
Point<type>::Point(const Point<type>& point) : Point<type>(point.x_, point.y_) { }

template<class type>
type Point<type>::x() const
{
	return x_;
}

template<class type>
void Point<type>::x(type x)
{
	x_ = x;
}

template<class type>
type Point<type>::y() const
{
	return y_;
}

template<class type>
void Point<type>::y(type y)
{
	y_ = y;
}

template<class type>
Point<type> &Point<type>::operator+=(const Point<type>& point)
{
	x_ += point.x();
	y_ += point.y();
	return *this;
}

template<class type>
Point<type> &Point<type>::operator-=(const Point<type>& point)
{
	x_ -= point.x();
	y_ -= point.y();
	return *this;
}

template<class type>
Point<type> &Point<type>::operator*=(const type& point)
{
	x_ *= point.x();
	y_ *= point.y();
	return *this;
}

template<class type>
Point<type> &Point<type>::operator/=(const type& value)
{
	x_ /= value;
	y_ /= value;
	return *this;
}

template<class type>
Point<type> Point<type>::operator-()
{
	x_ = -x_;
	y_ = -x_;
	return *this;
}
}}

#endif
