#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "windowManager.h"
#include "gestionInput.h"

int main(int, char*[]){
  srand(time(NULL));
  auto ec = std::make_shared<Ecran>();

  startMainBoucle(ec);
  
  return 0;
}
