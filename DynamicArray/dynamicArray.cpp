#include "dynamicArray.h"
#include <stdexcept>
#include <algorithm>

DynamicArray::DynamicArray(unsigned int _nbElements)
{
	if (_nbElements <= 0)
	{
		throw std::invalid_argument("La capacité doit être supérieure à 0");
	}
	else
	{
		capacite = _nbElements;
		tabElements = new int[capacite];

		for (unsigned int i = 0; i < capacite; i++)
		{
			tabElements[i] = 0;
		}
	}
}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

void DynamicArray::setElement(unsigned int _index, int _element)
{
	if (_index >= capacite)
	{
		setCapacite(_index + 1);
	}

	tabElements[_index] = _element;
}

void DynamicArray::setCapacite(unsigned int _nouvelleCapacite)
{
	if (_nouvelleCapacite <= 0)
	{
		throw std::invalid_argument("La capacité doit être supérieure à 0");
	}
	else
	{
		int* nouveauTableauElements = new int[_nouvelleCapacite];
		
		for (unsigned int i = 0; i < std::min(capacite, _nouvelleCapacite); i++)
		{
			nouveauTableauElements[i] = tabElements[i];
		}

		for (unsigned int i = capacite; i < _nouvelleCapacite; i++)
		{
			nouveauTableauElements[i] = 0;
		}

		delete[] tabElements;
		tabElements = nouveauTableauElements;
		capacite = _nouvelleCapacite;
	}
}

int DynamicArray::getElement(unsigned int _index) const
{
	if (_index >= capacite)
	{
		throw std::out_of_range("L'index est supérieur à la capacité");
	}
	else
	{
		return tabElements[_index];
	}
}

int DynamicArray::getCapacite() const
{
	return capacite;
}