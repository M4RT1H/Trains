#pragma once
#include "Colors.h"

namespace Console
{
	void SetCursorPosition(int x, int y);

	void SetColor(Color bg, Color  tx);

	void Cursor(bool enabled);
}
