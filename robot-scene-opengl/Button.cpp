#include "Button.h"

Button::Button(Vector3 new_position, float new_length, float new_width, std::string new_name, FunctionPtr new_function) {
	position = new_position;
	length = new_length;
	width = new_width;
	name = new_name;
	function = new_function;
}