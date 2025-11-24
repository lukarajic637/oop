#include "container.h"
#include <stdexcept>
#include <utility>

using namespace std;

container::container(size_t initial_capacity)
	: data(nullptr), _size(0), _capacity(initial_capacity)
{
	if (_capacity > 0) {
		data = new int[_capacity];
	}
	cout << _capacity << endl;
}

container::container(const container& other)
	: data(nullptr), _size(other.size), _capacity(other.capacity)
{
	if (_capacity > 0) {
		data = new int[_capacity];
	}
	for (size_t i = 0; i < _size; i++) {
		data[i] = other.data[i];
	}
}
container::container(container&& other) noexcept
	: data(other.data), _size(other._size), _capacity(other._capacity)
{
	other.data = nullptr;
	other._size = 0;
	other._capacity = 0;
}

container& container::operator=(const container& other)
{
	if (this == &other) {
		return *this;
	}
	delete[] data;
	
	_size = other._size;
	_capacity = other._capacity;
	
	data = (_capacity > 0) ? new int[_capacity] : nullptr;

	for (size_t i = 0; i < _size; ++i)
		data[i] = other.data[i];
	return *this;
}

