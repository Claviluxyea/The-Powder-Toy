#include "common/tpt-minmax.h"
#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_FLSH()
{
    Identifier = "DEFAULT_PT_FLSH";
    Name = "FLSH";
    Colour = PIXPACK(0xE6B8B7);
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
    HotAir = 0.000f    * CFDS;
    Falldown = 0;

    Flammable = 0;
    Explosive = 0;
    Meltable = 0;
    Hardness = 10;

    Weight = 100;

    HeatConduct = 30;
    Description = "Flesh, soft tissue.";

    Properties = TYPE_SOLID | PROP_NEUTPENETRATE;

    LowPressure = IPL;
    LowPressureTransition = PT_GAS;
    HighPressure = IPH;
    HighPressureTransition = PT_BLD;
    LowTemperature = ITL;
    LowTemperatureTransition = PT_ICEI;
    HighTemperature = 310.0f;
    HighTemperatureTransition = PT_BLD;

    Update = &update;
    Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
    return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
    float maxtemp = std::max((float)cpart->tmp, cpart->temp);
    if (maxtemp > 300)
    {
        *colr += (int)restrict_flt((maxtemp-300)/2,0,50);
        *colg -= (int)restrict_flt((maxtemp-300)/3,0,100);
        *colb -= (int)restrict_flt((maxtemp-300)/3,0,100);
    }
    if (maxtemp < 273)
    {
        *colr -= (int)restrict_flt((273-maxtemp)/5,0,40);
        *colg += (int)restrict_flt((273-maxtemp)/4,0,40);
        *colb += (int)restrict_flt((273-maxtemp)/1.5,0,150);
    }
    return 0;
}
