#ifndef ANGLE_HXX
#define ANGLE_HXX

#include "vecteur2.hxx"
#include <math.h>

namespace geometrie
{

	template <typename T, typename Angle, typename Distance=double>
	constexpr Vecteur2<T> vecteur2(const Angle& angle, const Distance& distance = 1)
	{
		return vecteur2From<T>(Vecteur2<Angle>{std::cos(angle), std::sin(angle)}*distance);
	}

	template <typename Angle, typename T>
	constexpr Angle angle(const Vecteur2<T>& vec)
	{
		return std::atan2(vec.y, vec.x);
	}

	template <typename Angle, typename T>
	constexpr Angle angleOriente(const Vecteur2<T>& a, const Vecteur2<T>& b)
	{
		const auto angleA = angle<Angle>(a);
		const auto angleB = angle<Angle>(b);

		const auto angleAB = angleB - angleA;
                double pi = 3.141592653589793238462643383279;
		if (angleAB>pi) {
			return angleAB-2*pi;
		}
		else if (angleAB<-pi){
			return angleAB+2*pi;
		}
		return angleAB;
	}


}

#endif // ANGLE_HXX
