#include "simulation/ElementCommon.h"


void Element::Element_POLY()
{
    Identifier = "DEFAULT_PT_POLY";
    Name = "POLY";
    Colour = PIXPACK(0xC8A2C8);
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
    Falldown = 1;

    Flammable = 0;
    Explosive = 0;
    Meltable = 1;
    Hardness = 25;

    Weight = 100;

    HeatConduct = 0.12f;
    Description = "Synthetic polymer used in clothing and fabrics.";

    Properties = TYPE_SOLID|PROP_CONDUCTS|PROP_LIFE_DEC;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = 573.0f;
    HighTemperatureTransition = PT_FIRE;
}

// todo: make it burn
