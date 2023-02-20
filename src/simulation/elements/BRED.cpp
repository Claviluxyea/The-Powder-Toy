#include "common/tpt-minmax.h"
#include "simulation/ElementCommon.h"


void Element::Element_BRED()
{
Identifier = "DEFAULT_PT_BRED";
Name = "BRED";
Colour = PIXPACK(0xE6C78C);
MenuVisible = 1;
MenuSection = SC_SOLIDS;
Enabled = 1;
Advection = 0.0f;
AirDrag = 0.00f * CFDS;
AirLoss = 0.90f;
Loss = 0.00f;
Collision = 0.0f;
Gravity = 0.0f;
Diffusion = 0.00f;
HotAir = 0.000f * CFDS;
Falldown = 0;

Flammable = 15;
Explosive = 0;
Meltable = 0;
Hardness = 20;

Weight = 100;

HeatConduct = 12;
Description = "Bread, a baked food.";

Properties = TYPE_SOLID | PROP_NEUTPENETRATE;

LowPressure = IPL;
LowPressureTransition = NT;
HighPressure = IPH;
HighPressureTransition = NT;
LowTemperature = ITL;
LowTemperatureTransition = NT;
HighTemperature = 473.0f;
HighTemperatureTransition = PT_FIRE;

}