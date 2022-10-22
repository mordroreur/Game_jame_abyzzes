#ifndef POINTXY_H
#define POINTXY_H

#include <math.h>

namespace geometrie {
	template <typename T>
	struct PointXY {
		T x;
		T y;
		using type = T;
	};

	// Distance
	template <typename Res, typename T>
	constexpr Res distanceCarree(const PointXY<T>& a, const PointXY<T>& b) {
		const auto difX = a.x-b.x;
		const auto difY = a.y-b.y;
		return difX*difX+difY*difY;
	}

	template <typename Res, typename T>
	constexpr Res distance(const PointXY<T>& a, const PointXY<T>& b) {
		return static_cast<Res>(std::sqrt(distanceCarree<Res>(a,b)));
	}

	// comparaisons
	template<typename T>
	constexpr bool operator==(const PointXY<T>& lft, const PointXY<T>& rht) {
		return lft.x==rht.x && lft.y == rht.y;
	}
	template<typename T>
	constexpr bool operator!=(const PointXY<T>& lft, const PointXY<T>& rht) {
		return !(lft == rht);
	}

	//conversion
	template<typename Res, typename T>
	constexpr PointXY<Res> pointXYFrom(const PointXY<T>& p) {
		return {static_cast<Res>(p.x), static_cast<Res>(p.y)};
	}

	template<typename Res, typename T>
	constexpr PointXY<Res> pointXYFrom(const T& inconnu) {
		return {static_cast<Res>(inconnu.x), static_cast<Res>(inconnu.y)};
	}
}

#endif // POINTXY_H
