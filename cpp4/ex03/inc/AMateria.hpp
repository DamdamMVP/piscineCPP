#pragma once
#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};