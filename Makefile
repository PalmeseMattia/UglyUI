all:
	mkdir -p target
	gcc core/*.c core/event_loop/*.c test.c -I core -I core/styles -I core/event_loop -o target/compiled
