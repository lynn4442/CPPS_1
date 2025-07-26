#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) { (void)target; }
