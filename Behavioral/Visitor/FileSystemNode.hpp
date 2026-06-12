#pragma once

#include "IVisitor.hpp"
#include <vector>
#include <memory>
#include <string>

class IFileSystemNode {
	public:
		virtual void accept(IVisitor* visitor) = 0;
		virtual ~IFileSystemNode() = default;
};

class File : public IFileSystemNode {
	private:
		std::string name;
		int size;

	public:
		File(const std::string& n, int s) : name(n), size(s) {}
		const std::string& getName() const { return name; }
		int getSize() const { return size; }
		void accept(IVisitor* v) override { v->visit(this); }
};

class Image : public IFileSystemNode {
	private:
		std::string name;
		int width, height;

	public:
		Image(const std::string& n, int w, int h) : name(n), width(w), height(h) {}
		const std::string& getName() const { return name; }
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		void accept(IVisitor* v) override { v->visit(this); }
};

class Folder : public IFileSystemNode {
	private:
		std::string name;
		std::vector<std::shared_ptr<IFileSystemNode>> children;
	
	public:
		Folder(const std::string& n) : name(n) {}
		const std::string& getName() const { return name; }
	
		void add(std::shared_ptr<IFileSystemNode> node) {
			children.push_back(node);
		}
	
		void accept(IVisitor* v) override {
			v->visit(this);
			for (auto& child : children) {
				child->accept(v);
			}
		}
};
