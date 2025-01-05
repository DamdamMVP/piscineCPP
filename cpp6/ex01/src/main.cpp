#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;
  data.value = 42;
  data.name = "Sérialisation Test";

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized: " << raw << std::endl;

  Data *deserializedData = Serializer::deserialize(raw);
  std::cout << "Deserialized Data -> Value: " << deserializedData->value
            << ", Name: " << deserializedData->name << std::endl;

  if (deserializedData == &data) {
    std::cout << "Les objets sont identiques !" << std::endl;
  } else {
    std::cout << "Erreur : Les objets ne sont pas identiques." << std::endl;
  }
  return 0;
}
