#pragma once

class File;
class Folder;
class Image;

class IVisitor {
public:
	virtual void visit(File* file) = 0;
	virtual void visit(Folder* folder) = 0;
	virtual void visit(Image* image) = 0;
	virtual ~IVisitor() = default;
};
