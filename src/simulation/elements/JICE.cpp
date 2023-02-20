#include "simulation/ElementCommon.h"

void Element::Element_JICE()
{
	Identifier = "DEFAULT_PT_JICE";
	Name = "JICE";
	Colour = PIXPACK(0xFFA500);
	MenuVisible = 1;
	MenuSection = SC_LIQUID;
	Enabled = 1;

	Advection = 0.6f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 2;

	Flammable = 10;
	Explosive = 0;
	Meltable = 0;
	Hardness = 1;

	Weight = 10;

	HeatConduct = 42;
	Description = "A delicious, sweet and sticky liquid.";

	Properties = TYPE_LIQUID | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = PT_ICEI;
	HighTemperature = 333.0f;
	HighTemperatureTransition = NT;
}
