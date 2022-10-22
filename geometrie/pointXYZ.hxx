#ifndef PointXYZZ_HXX
#define PointXYZZ_HXX

#include <math.h>

namespace geometrie {
	template <typename T>
	struct PointXYZ {
		T x;
		T y;
		T z;
	};

	// Distance
	template <typename Res, typename T>
	constexpr Res distance_carre(const PointXYZ<T>& a, const PointXYZ<T>& b) {
		const auto difX = a.x-b.x;
		const auto difY = a.y-b.y;
		const auto difZ = a.z-b.z;
		return difX*difX+difY*difY+difZ*difZ;
	}

	template <typename Res, typename T>
	constexpr Res distance(const PointXYZ<T>& a, const PointXYZ<T>& b) {
		return std::sqrt(distance_carre<Res>(a,b));
	}

	// comparaisons
	template<typename T>
	constexpr bool operator==(const PointXYZ<T>& lft, const PointXYZ<T>& rht) {
		return lft.x==rht.x && lft.y == rht.y && lft.z == rht.z;
	}

	template<typename T>
	constexpr bool operator!=(const PointXYZ<T>& lft, const PointXYZ<T>& rht) {
		return !(lft == rht);
	}

	//conversion
	template<typename Res, typename T>
	constexpr PointXYZ<Res> toPointXYZ(const PointXYZ<T>& p) {
		return {p.x, p.y, p.z};
	}
}

#endif // PointXYZZ_HXX
