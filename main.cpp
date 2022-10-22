#include <iostream>
#include "windowManager.h"
#include "gestionInput.h"

int main(int, char*[]){

  auto ec = std::make_shared<Ecran>();

  startMainBoucle(ec);
  
  return 0;
}
