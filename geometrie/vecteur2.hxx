#ifndef VECTEUR2_H
#define VECTEUR2_H

#include <math.h>

namespace geometrie
{
	template <typename T>
	struct Vecteur2
	{
		T x;
		T y;

		constexpr Vecteur2<T>& operator+=(const Vecteur2<T>& autre)
		{
			x += autre.x;
			y += autre.y;
			return *this;
		}
	};

	// Operation vecteurs
	template <typename T>
	constexpr Vecteur2<T> operator-(const Vecteur2<T>& vec)
	{
		return { -vec.x, -vec.y };
	}

	template <typename T>
	constexpr Vecteur2<T> operator+(const Vecteur2<T>& lft, const Vecteur2<T>& rht)
	{
		return { lft.x + rht.x, lft.y + rht.y };
	}

	template <typename T>
	constexpr Vecteur2<T> operator-(const Vecteur2<T>& lft, const Vecteur2<T>& rht)
	{
		return lft + (-rht);
	}

	template <typename T>
	constexpr double dot(const Vecteur2<T>& lft, const Vecteur2<T>& rht)
	{
		return lft.x * rht.x + lft.y * rht.y;
	}

	// Operation vecteur scalaire
	template <typename T, typename Ts>
	constexpr Vecteur2<T> operator*(const Vecteur2<T>& vec, const Ts& scalaire)
	{
		return { static_cast<T>(vec.x * scalaire), static_cast<T>(vec.y * scalaire) };
	}

	template <typename T, typename Ts>
	constexpr Vecteur2<T> operator*(const Ts& scalaire, const Vecteur2<T>& vec)
	{
		return vec * scalaire;
	}

	template <typename T, typename Ts>
	constexpr Vecteur2<T> operator/(const Vecteur2<T>& vec, const Ts& scalaire)
	{
		return { vec.x / scalaire, vec.y / scalaire };
	}

	// comparaisons
	template<typename T>
	constexpr bool operator==(const Vecteur2<T>& lft, const Vecteur2<T>& rht) {
		return lft.x==rht.x && lft.y == rht.y;
	}

	template<typename T>
	constexpr bool operator!=(const Vecteur2<T>& lft, const Vecteur2<T>& rht) {
		return !(lft == rht);
	}

	//conversion
	template<typename Res, typename T>
	constexpr Vecteur2<Res> vecteur2From(const Vecteur2<T>& v) {
		return {static_cast<Res>(v.x), static_cast<Res>(v.y)};
	}

	// Longueur
	template<typename Res, typename T>
	constexpr Res longueurCarree(const Vecteur2<T>& v) {
		return v.x*v.x+v.y*v.y;
	}
	template<typename Res, typename T>
	constexpr Res longueur(const Vecteur2<T>& v) {
		return std::sqrt(longueurCarree<Res>(v));
	}


	template <typename T>
	constexpr Vecteur2<T> normalized(const Vecteur2<T>& vec)
	{
		const auto lenght = longueur<T>(vec);
		return vec/lenght;
	}


	template <typename T>
	constexpr Vecteur2<T> projeteOrthogonal(const Vecteur2<T>& vecteur, const Vecteur2<T>& base) {
		const auto baseNorm = normalized(base);
		return dot(vecteur,baseNorm)*baseNorm;
	}

} // namespace psa::geometrie

namespace std {
template <typename T>
constexpr geometrie::Vecteur2<T> abs(const geometrie::Vecteur2<T>& v) {
	return {abs(v.x), abs(v.y)};
}
}

#endif // VECTEUR2_H
