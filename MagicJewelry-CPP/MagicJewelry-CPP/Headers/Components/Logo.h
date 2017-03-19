#pragma once

#include "Engine\Types\Actor.h"

class Logo : public Actor
{
public:
	enum LogoColor {Orange = 1, Gray = 2, Violet = 3, Aqua = 4, Pink = 5, Green = 6, Yellow = 7, Blue = 8};
	Logo(int X, int Y, bool Animate);
	virtual void Tick(int DeltaTime) override;
	virtual void Refresh() override;
	bool ChangeColor(LogoColor Color);
private:
	LogoColor currentColor;
	bool animate;
	int timeFromChange;
};

