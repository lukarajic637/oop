#include <iostream>
#ifndef CONTAINER_H
#define CONTAINER_H

class container {
private:
	int* data;
	std::size_t _size;
	std::size_t _capacity;
public:
	explicit container(std::size_t initial_capacity = 0);
	container(const container& other);
	container(container&& other) noexcept;
	container& operator=(const container& other);
	container& operator=(container&& other) noexcept;
	~container();

	void push_back(int value);
	std::size_t _size() const;
	std::size_t _capacity() const;
	int& at(std::size_t index);
	const int& at(std::size_t index) const;
	void clear();

	void print() const;
};

#endif