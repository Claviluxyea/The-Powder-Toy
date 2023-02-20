#include "Appearance.h"
#include "graphics/Graphics.h"
#include <iostream>

namespace ui
{
	Appearance::Appearance():
		texture(NULL),

		VerticalAlign(AlignMiddle),
		HorizontalAlign(AlignCentre),

		BackgroundHover(50, 50, 50),
		BackgroundInactive(30, 30, 30),
		BackgroundActive(70, 130, 180),
		BackgroundDisabled(70, 70, 70),

		TextHover(255, 255, 255),
		TextInactive(200, 200, 200),
		TextActive(255, 255, 255),
		TextDisabled(150, 150, 150),

		BorderHover(255, 255, 255),
		BorderInactive(100, 100, 100),
		BorderActive(255, 255, 255),
		BorderDisabled(70, 70, 70),

		Margin(2, 8),
		Border(1),

		icon(NoIcon)
	{}

	VideoBuffer * Appearance::GetTexture()
	{
		return texture;
	}

	void Appearance::SetTexture(VideoBuffer * texture)
	{
		delete this->texture;
		if(texture)
			this->texture = new VideoBuffer(texture);
		else
			this->texture = NULL;
	}

	Appearance::~Appearance()
	{
		delete texture;
	}

}
