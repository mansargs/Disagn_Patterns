#include "FileSystemNode.hpp"
#include "ConcreteVisitors.hpp"
#include <memory>
#include <iostream>

int main() {
	auto root = std::make_shared<Folder>("root");
	root->add(std::make_shared<File>("readme.txt", 512));
	root->add(std::make_shared<Image>("photo.jpg", 1920, 1080));

	auto docs = std::make_shared<Folder>("documents");
	docs->add(std::make_shared<File>("report.pdf", 2048));
	docs->add(std::make_shared<File>("notes.txt", 256));
	root->add(docs);

	auto media = std::make_shared<Folder>("media");
	media->add(std::make_shared<Image>("banner.png", 800, 600));
	media->add(std::make_shared<File>("video.mp4", 5000000));
	root->add(media);

	std::cout << "=== Directory Structure ===" << std::endl;
	PrintVisitor printer;
	root->accept(&printer);

	std::cout << "\n=== Total Size ===" << std::endl;
	SizeVisitor sizer;
	root->accept(&sizer);
	std::cout << "Total: " << sizer.totalSize << " bytes" << std::endl;

	return 0;
}
