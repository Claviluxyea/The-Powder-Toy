#include "common/tpt-minmax.h"
#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_SCH()
{
Identifier = "DEFAULT_PT_SCH";
Name = "SCH";
Colour = PIXPACK(0x5E2612);
MenuVisible = 1;
MenuSection = SC_SOLIDS;
Enabled = 1;
Advection = 0.0f;
AirDrag = 0.00f * CFDS;
AirLoss = 0.90f;
Loss = 0.00f;
Collision = 1.0f;
Gravity = 0.3f;
Diffusion = 0.00f;
HotAir = 0.000f    * CFDS;
Falldown = 1;

Flammable = 0;
Explosive = 0;
Meltable = 1;
Hardness = 50;

Weight = 100;

HeatConduct = 20;
Description = "Solid chocolate, meltable.";

Properties = TYPE_SOLID | PROP_NEUTPASS;

LowPressure = IPL;
LowPressureTransition = NT;
HighPressure = IPH;
HighPressureTransition = NT;
LowTemperature = ITL;
LowTemperatureTransition = ICEI;
HighTemperature = 373.0f;
HighTemperatureTransition = PT_CHOC;

Update = &update;
Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
if (parts[i].temp > 373.0f)
{
sim->create_part(i, x, y, PT_CHOCOLATE);
return 1;
}
return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
int temperature = (int)cpart->temp;
int r = 94, g = 38, b = 18;
// adjust color based on temperature
if (temperature > 300)
{
    r -= restrict_flt((temperature - 300) / 4.0f, 0, 76);
    g -= restrict_flt((temperature - 300) / 6.0f, 0, 30);
    b -= restrict_flt((temperature - 300) / 10.0f, 0, 12);
}

*colr = r;
*colg = g;
*colb = b;
return 0;
}