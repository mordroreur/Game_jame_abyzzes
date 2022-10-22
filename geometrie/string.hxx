#ifndef STRING_HXX
#define STRING_HXX

#include "pointXY.hxx"
#include "vecteur2.hxx"

#include <string>


namespace psa::geometrie {
template <typename T>
std::string toString(const Vecteur2<T>& v) {
	return "["+std::to_string(v.x)+"; "+std::to_string(v.y)+"]";
}

template <typename T>
std::string toString(const PointXY<T>& p) {
	return "{"+std::to_string(p.x)+"; "+std::to_string(p.y)+"}";
}
}

#endif // STRING_HXX
