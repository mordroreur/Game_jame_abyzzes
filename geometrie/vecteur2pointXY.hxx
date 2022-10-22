#ifndef VECTEUR2POINTXY_H
#define VECTEUR2POINTXY_H

#include "pointXY.hxx"
#include "vecteur2.hxx"


namespace geometrie
{

	// Operations Vecteur Point
	template <typename T>
	constexpr PointXY<T> operator+(const PointXY<T>& lft, const Vecteur2<T>& rht)
	{
		return { lft.x + rht.x, lft.y + rht.y };
	}

	template <typename T>
	constexpr PointXY<T> operator-(const PointXY<T>& lft, const Vecteur2<T>& rht)
	{
		return lft + (-rht);
	}

	template <typename T>
	constexpr Vecteur2<T> operator-(const PointXY<T>& lft, const PointXY<T>& rht)
	{
		return {lft.x - rht.x, lft.y - rht.y};
	}

} // namespace psa::geometrie
#endif // VECTEUR2POINTXY_H
