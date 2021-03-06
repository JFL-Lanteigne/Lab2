#include "dynamicArray.h"
#include <stdexcept>
#include <algorithm>

DynamicArray::DynamicArray(unsigned int _nbElements)
{
	if (_nbElements <= 0)
	{
		throw std::invalid_argument("La capacit� doit �tre sup�rieure � 0");
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

DynamicArray::DynamicArray(const DynamicArray& _source)
{
	tabElements = new int[_source.capacite];
	capacite = _source.capacite;

	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = _source.tabElements[i];
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray& _source)
{
	if (&_source != this)
	{
		delete[] tabElements;
		tabElements = new int[_source.capacite];
		capacite = _source.capacite;

		for (unsigned int i = 0; i < capacite; i++)
		{
			tabElements[i] = _source.tabElements[i];
		}
	}

	return *this;
}

bool DynamicArray::operator==(const DynamicArray& _rhs) const
{
	bool memeTableau = false;

	if (capacite == _rhs.capacite)
	{
		for (unsigned int i = 0; i < capacite; i++)
		{
			if (tabElements[i] != _rhs.tabElements[i])
			{
				return false;
			}
			else
			{
				memeTableau = true;
			}
		}
	}

	return memeTableau;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _rhs)
{
	int ancienneCapacite = capacite;
	int nouvelleCapacite = ancienneCapacite + _rhs.capacite;
	int capaciteTableauAconcatener = _rhs.capacite;

	setCapacite(nouvelleCapacite);

	for (unsigned int i = 0; i < capaciteTableauAconcatener; i++)
	{
		tabElements[ancienneCapacite + i] = _rhs.tabElements[i];
	}

	return *this;
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
		throw std::invalid_argument("La capacit� doit �tre sup�rieure � 0");
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
		throw std::out_of_range("L'index est sup�rieur � la capacit�");
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