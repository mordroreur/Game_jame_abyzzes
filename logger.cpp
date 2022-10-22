#include "logger.h"
#include <fstream>

void log(const std::string_view& s) {
	static std::ofstream file("log.o");
	file<<s<<std::endl;
}

void log(const SDL_Rect& r) {
	log(std::to_string(r.x)+" "+std::to_string(r.y)+" "+std::to_string(r.w)+" "+std::to_string(r.h));
}
