#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// Additional tests
	std::cout << "\n=== Additional Tests ===" << std::endl;

	// Test deep copy
	Character* alice = new Character("Alice");
	Character* charlie = new Character("Charlie");

	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	alice->equip(source->createMateria("ice"));
	alice->equip(source->createMateria("cure"));

	// Test copy constructor
	Character* aliceCopy = new Character(*alice);
	std::cout << "Alice copy name: " << aliceCopy->getName() << std::endl;

	aliceCopy->use(0, *charlie);
	aliceCopy->use(1, *charlie);

	// Test unequip
	alice->unequip(0);
	alice->use(0, *charlie); // Should do nothing
	alice->use(1, *charlie); // Should still work

	// Test invalid operations
	alice->use(5, *charlie); // Invalid index
	alice->unequip(-1);      // Invalid index

	delete alice;
	delete aliceCopy;
	delete charlie;
	delete source;

	return 0;
}
