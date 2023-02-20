#include "common/tpt-minmax.h"
#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_CHSE()
{
Identifier = "DEFAULT_PT_CHSE";
Name = "CHSE";
Colour = PIXPACK(0xFFE599);
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
HotAir = 0.000f	* CFDS;
Falldown = 0;

Flammable = 10;
Explosive = 0;
Meltable = 0;
Hardness = 10;

Weight = 90;

HeatConduct = 50;
Description = "Cheese, delicious.";

Properties = TYPE_SOLID | PROP_NEUTPENETRATE;

LowPressure = IPL;
LowPressureTransition = NT;
HighPressure = IPH;
HighPressureTransition = NT;
LowTemperature = ITL;
LowTemperatureTransition = PT_ICEI;
HighTemperature = 373.0f;
HighTemperatureTransition = PT_FIRE;

Update = &update;
Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
if (parts[i].temp > 450 && parts[i].temp > parts[i].tmp)
parts[i].tmp = (int)parts[i].temp;
if (parts[i].temp > 373.0f && sim->pv[y/CELL][x/CELL] <= -10.0f)
{
	float temp = parts[i].temp;
	sim->create_part(i, x, y, PT_BCOL);
	parts[i].temp = temp;
}

return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
float maxtemp = std::max((float)cpart->tmp, cpart->temp);
if (maxtemp > 400)
{
*colr -= (int)restrict_flt((maxtemp-400)/3,0,172);
*colg -= (int)restrict_flt((maxtemp-400)/4,0,140);
*colb -= (int)restrict_flt((maxtemp-400)/20,0,44);
}
if (maxtemp < 273)
{
*colr -= (int)restrict_flt((273-maxtemp)/5,0,40);
*colg += (int)restrict_flt((273-maxtemp)/4,0,40);
*colb += (int)restrict_flt((273-maxtemp)/1.5,0,150);
}
return 0;
}
