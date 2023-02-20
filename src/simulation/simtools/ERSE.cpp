// no idea if it works so for now im gonna put it into comments

/*
#include "simulation/ToolCommon.h"

static int perform(Simulation * sim, Particle * cpart, int x, int y, int brushX, int brushY, float strength);

void SimTool::Tool_ERSE()
{
	Identifier = "DEFAULT_TOOL_ERSE";
	Name = "ERSE";
	Colour = PIXPACK(0x000000);
	Description = "Erases particles.";
	Perform = &perform;
}

static int perform(Simulation * sim, Particle * cpart, int x, int y, int brushX, int brushY, float strength)
{
	Particle *part = sim->get_part(x, y);
	if (part != NULL)
	{
		part->kill();
	}
	return 1;
}
/*