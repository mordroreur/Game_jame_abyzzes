#ifndef __GARDIEN_RENDER_H__
#define __GARDIEN_RENDER_H__

#include "windowManager.h"
#include <mutex>

static std::mutex mutexDo;

void boucleAffichage(std::shared_ptr<Ecran> ec, int *frameCount);

#endif
