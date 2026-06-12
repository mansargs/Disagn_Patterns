#pragma once

#include <iostream>
#include <memory>
#include <string>

class TextEditor {
	private:
		std::string text;

	public:
		TextEditor() = default;

		void write(const std::string& newText) {
			text += newText;
		}

		void show() const {
			std::cout << "Current text: " << text << std::endl;
		}

		const std::string& getText() const { return text; }

		class Memento {
			private:
				std::string state;
				friend class TextEditor;

			public:
				Memento(const std::string& s) : state(s) {}
		};

		std::shared_ptr<Memento> save() const {
			return std::make_shared<Memento>(text);
		}

		void restore(const std::shared_ptr<Memento>& memento) {
			if (memento) {
				text = memento->state;
			}
		}
};
