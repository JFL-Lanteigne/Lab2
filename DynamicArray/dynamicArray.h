#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{
public:
	DynamicArray(unsigned int _nbElements = 100);
	~DynamicArray();
	void setElement(unsigned int _index, int _element);
	void setCapacite(unsigned int _nouvelleCapacite);
	int getElement(unsigned int _index) const;
	int getCapacite() const;

private:
	int* tabElements;
	unsigned int capacite;
};


#endif //DYNAMICARRAY_H_