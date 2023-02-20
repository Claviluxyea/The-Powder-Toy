#include "simulation/ElementCommon.h"

void Element::Element_CHOC()
{
    Identifier = "DEFAULT_PT_CHOC";
    Name = "CHOC";
    Colour = PIXPACK(0x5A3018);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;

    Advection = 0.8f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.98f;
    Loss = 0.95f;
    Collision = 0.0f;
    Gravity = 0.3f;
    Diffusion = 0.08f;
    HotAir = 0.000f * CFDS;
    Falldown = 2;

    Flammable = 0;
    Explosive = 0;
    Meltable = 1;
    Hardness = 10;

    Weight = 30;

    HeatConduct = 28;
    Description = "A liquid chocolate with high viscosity and temperature dependent melting point.";

    Properties = TYPE_LIQUID | PROP_NEUTPASS;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = 280.0f;
    LowTemperatureTransition = PT_SCH;
    HighTemperature = 345.0f;
    HighTemperatureTransition = NT;
}
