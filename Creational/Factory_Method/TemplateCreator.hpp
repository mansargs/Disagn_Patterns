#pragma once

#include "Document.hpp"
#include <concepts>


template<typename T>
requires std::derived_from<T, Document>   //concepts is c++ 20 standart
class DocumentFactory {
public:
	~DocumentFactory() {}
	Document* createDocument() const {
		return new T();
	}
};
