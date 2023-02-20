#include "simulation/ElementCommon.h"


void Element::Element_INK()
{
Identifier = "DEFAULT_PT_INK";
Name = "INK";
Colour = PIXPACK(0x1A1A1A);
MenuVisible = 1;
MenuSection = SC_LIQUID;
Enabled = 1;
Advection = 0.6f;
AirDrag = 0.01f * CFDS;
AirLoss = 0.98f;
Loss = 0.95f;
Collision = 0.0f;
Gravity = 0.1f;
Diffusion = 0.05f;
HotAir = 0.000f	* CFDS;
Falldown = 2;

Flammable = 0;
Explosive = 0;
Meltable = 0;
Hardness = 0;

Weight = 31;

DefaultProperties.temp = 25.0f + 273.15f;
HeatConduct = 251;
Description = "Ink. A black liquid used for writing or drawing.";

Properties = TYPE_LIQUID;

LowPressure = IPL;
LowPressureTransition = NT;
HighPressure = IPH;
HighPressureTransition = NT;
LowTemperature = 273.15f;
LowTemperatureTransition = NT;
HighTemperature = 373.15f;
HighTemperatureTransition = NT;

DefaultProperties.tmp4 = 0;
}

