#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape(outlineColor, fillColor)
{
	m_center = center;
	m_radius = radius;
}

double CCircle::GetArea()
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter()
{
	return 2 * M_PI * m_radius;
}

string CCircle::ToString()
{
	return "Circle(" + m_center.ToString() + ", " + to_string(m_radius) + ")";
}
