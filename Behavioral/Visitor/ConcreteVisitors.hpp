#pragma once

#include "IVisitor.hpp"
#include "FileSystemNode.hpp"
#include <iostream>

class PrintVisitor : public IVisitor {
	private:
		int depth = 0;

		void printIndent() {
			for (int i = 0; i < depth * 2; ++i) std::cout << " ";
		}

	public:
		void visit(File* file) override {
			printIndent();
			std::cout << "[FILE] " << file->getName()
					  << " (" << file->getSize() << " bytes)" << std::endl;
		}

		void visit(Image* image) override {
			printIndent();
			std::cout << "[IMG] " << image->getName()
					  << " (" << image->getWidth() << "x" << image->getHeight()
					  << ")" << std::endl;
		}

		void visit(Folder* folder) override {
			printIndent();
			std::cout << "[DIR] " << folder->getName() << "/" << std::endl;
			++depth;
		}
};

class SizeVisitor : public IVisitor {
	public:
		int totalSize = 0;

		void visit(File* file) override {
			totalSize += file->getSize();
		}

		void visit(Image* image) override {
			totalSize += image->getWidth() * image->getHeight() / 8;
		}

		void visit(Folder* /*folder*/) override {
			// folders don't contribute to size
		}
};
