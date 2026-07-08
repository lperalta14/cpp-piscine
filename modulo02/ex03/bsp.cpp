#include "Point.hpp"

static Fixed deltaX(const Point& from, const Point& to)
{
	return (to.getX() - from.getX());
}

static Fixed deltaY(const Point& from, const Point& to)
{
	return (to.getY() - from.getY());
}

static Fixed cross(Fixed v1x, Fixed v1y, Fixed v2x, Fixed v2y)
{
	return (v1x * v2y - v1y * v2x);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	zero;

	Fixed	abx = deltaX(a, b);
	Fixed	aby = deltaY(a, b);

	Fixed	bcx = deltaX(b, c);
	Fixed	bcy = deltaY(b, c);

	Fixed	cax = deltaX(c, a);
	Fixed	cay = deltaY(c, a);

	Fixed	apx = deltaX(a, point);
	Fixed	apy = deltaY(a, point);

	Fixed	bpx = deltaX(b, point);
	Fixed	bpy = deltaY(b, point);

	Fixed	cpx = deltaX(c, point);
	Fixed	cpy = deltaY(c, point);

	Fixed	crossAB = cross(abx, aby, apx, apy);
	Fixed	crossBC = cross(bcx, bcy, bpx, bpy);
	Fixed	crossCA = cross(cax, cay, cpx, cpy);

	if ((crossAB > zero && crossBC > zero && crossCA > zero)
		|| (crossAB < zero && crossBC < zero && crossCA < zero))
		return true;
	return false;
}