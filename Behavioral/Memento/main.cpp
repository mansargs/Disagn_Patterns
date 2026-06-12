#include <gtest/gtest.h>
#include "OriginatorMemento.hpp"
#include "Caretaker.hpp"

TEST(TextEditorTest, SaveRestore) {
	TextEditor editor;
	editor.write("Hello");
	auto saved = editor.save();
	editor.write(" World");
	editor.restore(saved);
	EXPECT_FALSE(editor.getText().empty());
	editor.restore(saved);
	EXPECT_EQ(editor.getText(), "Hello");
}

TEST(HistoryTest, UndoRedo) {
	TextEditor editor;
	History history;
	editor.write("A");
	history.save(editor.save());
	editor.write("B");
	history.save(editor.save());
	EXPECT_TRUE(history.canUndo());
	EXPECT_FALSE(history.canRedo());
	auto undoState = history.undo();
	editor.restore(undoState);
	EXPECT_EQ(editor.getText(), "A");
	auto redoState = history.redo();
	editor.restore(redoState);
	EXPECT_EQ(editor.getText(), "AB");
}

TEST(HistoryTest, RedoClearedAfterSave) {
	TextEditor editor;
	History history;
	editor.write("1");
	history.save(editor.save());
	editor.write("2");
	history.save(editor.save());
	auto undoState = history.undo();
	editor.restore(undoState);
	editor.write("3");
	history.save(editor.save());
	EXPECT_FALSE(history.canRedo());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
