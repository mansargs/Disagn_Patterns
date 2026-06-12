#include "ChatRoom.hpp"

int main() {
	ChatRoom room;

	User alice(&room, "Alice");
	User bob(&room, "Bob");
	User carol(&room, "Carol");

	room.addUser(&alice);
	room.addUser(&bob);
	room.addUser(&carol);

	alice.send("Hello everyone!");
	bob.send("Hi Alice!");
	carol.send("Meeting at 3pm.");

	return 0;
}
