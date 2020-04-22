#include "catch2/catch.hpp"
#include <iostream>
#include <sstream>
#include <lab4\lab4\CPoint.h>
#include <lab4\lab4\CUtils.h>
#include <lab4\lab4\CLineSegment.h>
#include <lab4\lab4\CCircle.h>
#include <lab4\lab4\CTriangle.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

TEST_CASE("CPoint")
{
	CPoint point(1, 2);
	SECTION("GetX should returns x")
	{
		REQUIRE(point.GetX() == 1);
	}
	SECTION("GetY should returns y")
	{
		REQUIRE(point.GetY() == 2);
	}
	SECTION("GetString should returns y")
	{
		REQUIRE(point.ToString() == "Point(1.000000; 2.000000)");
	}
}

TEST_CASE("CUtils")
{
	CPoint point(1, 2);
	SECTION("GetDistance should returns distance between two points")
	{
		double distance = CUtils::GetDistance(CPoint(0, 0), CPoint(1, 1));
		REQUIRE(distance == sqrt(2));
	}
}

TEST_CASE("CLineSegment")
{
	CPoint start(0, 0);
	CPoint end(1, 1);
	CLineSegment lineSegment(start, end, 0);
	SECTION("GetArea should returns area")
	{
		REQUIRE(lineSegment.GetArea() == 0);
	}
	SECTION("GetPerimeter should returns perimeter")
	{
		REQUIRE(lineSegment.GetPerimeter() == sqrt(2));
	}
	SECTION("ToString should returns string value")
	{
		string expected = "LineSegment(Point(0.000000; 0.000000); Point(1.000000; 1.000000); 0)";
		REQUIRE(lineSegment.ToString() == expected);
	}
	SECTION("GetOutlineColor should returns outline color")
	{
		REQUIRE(lineSegment.GetOutlineColor() == 0);
	}
	SECTION("SetOutlineColor should set outline color")
	{
		lineSegment.SetOutlineColor(1);
		REQUIRE(lineSegment.GetOutlineColor() == 1);
	}
	SECTION("GetStartPoint should returns start point")
	{
		REQUIRE(lineSegment.GetStartPoint() == start);
	}
	SECTION("GetEndPoint should returns end point")
	{
		REQUIRE(lineSegment.GetEndPoint() == end);
	}
	CPoint newPoint(2, 2);
	SECTION("SetStartPoint should set start point")
	{
		lineSegment.SetStartPoint(newPoint);
		REQUIRE(lineSegment.GetStartPoint() == newPoint);
	}
	SECTION("SetEndPoint should set end point")
	{
		lineSegment.SetEndPoint(newPoint);
		REQUIRE(lineSegment.GetEndPoint() == newPoint);
	}
}

void testsGeneratorSolidShape(ISolidShape& solidShape, double area, double perimeter, string str, uint32_t outlineColor, uint32_t fillColor)
{
	SECTION("GetArea should returns area")
	{
		REQUIRE(solidShape.GetArea() == area);
	}
	SECTION("GetPerimeter should returns perimeter")
	{
		REQUIRE(solidShape.GetPerimeter() == perimeter);
	}
	SECTION("ToString should returns string value")
	{
		REQUIRE(solidShape.ToString() == str);
	}
	SECTION("GetOutlineColor should returns outline color")
	{
		REQUIRE(solidShape.GetOutlineColor() == outlineColor);
	}
	SECTION("SetOutlineColor should set outline color")
	{
		solidShape.SetOutlineColor(2);
		REQUIRE(solidShape.GetOutlineColor() == 2);
	}
	SECTION("GetFillColor should returns fill color")
	{
		REQUIRE(solidShape.GetFillColor() == fillColor);
	}
	SECTION("SetFillColor should set fill color")
	{
		solidShape.SetFillColor(2);
		REQUIRE(solidShape.GetFillColor() == 2);
	}
}

TEST_CASE("CCircle")
{
	CPoint center = CPoint(0, 0);
	CCircle circle(center, 2, 1, 1);
	string expectedStr = "Circle(Point(0.000000; 0.000000); 2.000000; 1; 1)";
	testsGeneratorSolidShape(circle, M_PI * 4, 2 * M_PI * 2, expectedStr, 1, 1);
	SECTION("GetCenter should returns center")
	{
		REQUIRE(circle.GetCenter() == center);
	}
	SECTION("GetRadius should returns radius")
	{
		REQUIRE(circle.GetRadius() == 2);
	}
}

TEST_CASE("CTriangle")
{
	CPoint a(0, 0);
	CPoint b(5, 0);
	CPoint c(0, 4);
	CTriangle triangle(a, b, c, 1, 1);
	string expectedStr = "Triangle(Point(0.000000; 0.000000); Point(5.000000; 0.000000); Point(0.000000; 4.000000); 1; 1)";
	double perimeter = 4 + 5 + CUtils::GetDistance(b, c);
	testsGeneratorSolidShape(triangle, 10, perimeter, expectedStr, 1, 1);
	SECTION("GetVertex1 should returns vertex A")
	{
		REQUIRE(triangle.GetVertex1() == a);
	}
	SECTION("GetVertex1 should returns vertex B")
	{
		REQUIRE(triangle.GetVertex2() == b);
	}
	SECTION("GetVertex1 should returns vertex C")
	{
		REQUIRE(triangle.GetVertex3() == c);
	}
}