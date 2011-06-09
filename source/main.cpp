#include <main.h>

extern Buffer* main_buffer;
extern Buffer* main_layer;

Rope* rope;
bool physics;
touchPosition touch;

void handle_keys_down(u32 keys)
{
	if (keys & KEY_A){}
	if (keys & KEY_B){}
	if (keys & KEY_SELECT){}
	if (keys & KEY_START)
		physics = true;
	if (keys & KEY_RIGHT){}
	if (keys & KEY_LEFT){}
	if (keys & KEY_UP){}
	if (keys & KEY_DOWN){}
	if (keys & KEY_R){}
	if (keys & KEY_L){}
	if (keys & KEY_X){}
	if (keys & KEY_Y){}
	if (keys & KEY_TOUCH)
		add_segment_to_rope(rope, create_rope_segment(touch.px, touch.py, 0, 10));
	if (keys & KEY_LID){}
}

void handle_keys_held(u32 keys)
{
	if (keys & KEY_A){}
	if (keys & KEY_B){}
	if (keys & KEY_SELECT){}
	if (keys & KEY_START){}
	if (keys & KEY_RIGHT){}
	if (keys & KEY_LEFT){}
	if (keys & KEY_UP){}
	if (keys & KEY_DOWN){}
	if (keys & KEY_R){}
	if (keys & KEY_L){}
	if (keys & KEY_X){}
	if (keys & KEY_Y){}
	if (keys & KEY_TOUCH){}
	if (keys & KEY_LID){}
}

void handle_keys_up(u32 keys)
{
	if (keys & KEY_A){}
	if (keys & KEY_B){}
	if (keys & KEY_SELECT){}
	if (keys & KEY_START){}
	if (keys & KEY_RIGHT){}
	if (keys & KEY_LEFT){}
	if (keys & KEY_UP){}
	if (keys & KEY_DOWN){}
	if (keys & KEY_R){}
	if (keys & KEY_L){}
	if (keys & KEY_X){}
	if (keys & KEY_Y){}
	if (keys & KEY_TOUCH){}
	if (keys & KEY_LID){}
}

void handle_keys()
{
	handle_keys_down(keysDown());
	handle_keys_held(keysHeld());
	handle_keys_up(keysUp());
}

void loop()
{
	while(1)
	{
		touchRead(&touch);
		scanKeys();

		handle_keys();

		clear_topscreen();
		printf("Physics: %s", physics?"On":"Off");

		if(physics)
			give_rope_physics(rope);

		copy_buffers();
		swiWaitForVBlank();
	}
}

int main()
{
	init_video();

	fill_background(main_buffer, COLOR_BLACK);

	physics = false;

	rope = create_rope(COLOR_WHITE, new LinkedList);

	loop();

	delete_buffers();

	return 0;
}