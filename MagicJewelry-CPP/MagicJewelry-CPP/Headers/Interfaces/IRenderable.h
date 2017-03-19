#pragma once

#include "Engine\Types\Viewport.h"

class IRenderable
{
public:
	virtual void Refresh() = 0;
	virtual bool NeedRefresh() = 0;
	virtual Viewport* GetViewport() = 0;
protected:
	Viewport* viewport;
};