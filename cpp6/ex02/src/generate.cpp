#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base *generate() {
  srand(time(NULL));
  int random = rand() % 3;

  if (random == 0) {
    std::cout << "Création d'un objet de type A" << std::endl;
    return new A();
  } else if (random == 1) {
    std::cout << "Création d'un objet de type B" << std::endl;
    return new B();
  } else {
    std::cout << "Création d'un objet de type C" << std::endl;
    return new C();
  }
}

// if dynamic_cast fail with a pointer, return NULL
void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "Type réel : A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "Type réel : B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "Type réel : C" << std::endl;
  } else {
    std::cout << "Type inconnu" << std::endl;
  }
}

// if dynamic_cast fail with a reference, catch a throw ( catch (...) takes all
// exceptions )
void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Type réel : A" << std::endl;
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Type réel : B" << std::endl;
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Type réel : C" << std::endl;
    return;
  } catch (...) {
  }

  std::cout << "Type inconnu" << std::endl;
}