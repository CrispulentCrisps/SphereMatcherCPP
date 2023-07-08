#include "LevelEditor.h"

void LevelEditor::Editor_Start()
{
	Path newpath;
	Path::Vector2 p0 = {120, 120};
	Path::Vector2 p1 = {220, 220};
	Path::Vector2 p2 = {120, 120};
	Path::Vector2 p3 = {220, 220};
	newpath.AddBezier(p0, p1, p2, p3, 0);
	paths.push_back(newpath);
}
