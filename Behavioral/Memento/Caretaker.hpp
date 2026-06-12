#pragma once

#include "OriginatorMemento.hpp"
#include <stack>
#include <memory>

class History {
	private:
		std::stack<std::shared_ptr<TextEditor::Memento>> undoStack;
		std::stack<std::shared_ptr<TextEditor::Memento>> redoStack;

	public:
		void save(const std::shared_ptr<TextEditor::Memento>& memento) {
			undoStack.push(memento);
			while (!redoStack.empty()) {
				redoStack.pop();
			}
		}

		std::shared_ptr<TextEditor::Memento> undo() {
			if (undoStack.empty())
				return nullptr;
			auto current = undoStack.top();
			undoStack.pop();
			redoStack.push(current);

			if (undoStack.empty())
				return nullptr;

			return undoStack.top();
		}

		std::shared_ptr<TextEditor::Memento> redo() {
			if (redoStack.empty())
				return nullptr;
			auto m = redoStack.top();
			redoStack.pop();
			undoStack.push(m);
			return m;
		}

		bool canUndo() const { return !undoStack.empty(); }
		bool canRedo() const { return !redoStack.empty(); }
};
