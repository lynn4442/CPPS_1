#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int i = 0;
	while (i < 4)
	{
		materias[i] = 0;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	int i = 0;
	while (i < 4)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = 0;
		i++;
	}
}

MateriaSource::~MateriaSource()
{
	int i = 0;
	while (i < 4)
	{
		if (materias[i])
			delete materias[i];
		i++;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		// Delete existing materias
		int i = 0;
		while (i < 4)
		{
			if (materias[i])
			{
				delete materias[i];
				materias[i] = 0;
			}
			i++;
		}

		// Deep copy new materias
		i = 0;
		while (i < 4)
		{
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = 0;
			i++;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	int i = 0;
	while (i < 4)
	{
		if (!materias[i])
		{
			materias[i] = m->clone();
			delete m;
			return;
		}
		i++;
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4)
	{
		if (materias[i] && materias[i]->getType() == type)
		{
			return materias[i]->clone();
		}
		i++;
	}
	return 0;
}
