#include "simulation/ElementCommon.h"

void Element::Element_MUD()
{
    Identifier = "DEFAULT_PT_MUD";
    Name = "MUD";
    Colour = PIXPACK(0x6b3f2f);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;

    Advection = 0.4f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.99f;
    Loss = 0.99f;
    Collision = 0.0f;
    Gravity = 0.4f;
    Diffusion = 0.04f;
    HotAir = 0.000f * CFDS;
    Falldown = 3;

    Flammable = 0;
    Explosive = 0;
    Meltable = 1;
    Hardness = 3;

    Weight = 25;

    HeatConduct = 12;
    Description = "Meltable, viscous liquid made from clay and water.";

    Properties = TYPE_LIQUID | PROP_NEUTPASS;

    LowPressure = IPL;
    LowPressureTransition = PT_DUST;
    HighPressure = IPH;
    HighPressureTransition = PT_STNE;
    LowTemperature = ITL;
    LowTemperatureTransition = PT_ICEI;
    HighTemperature = 473.0f;
    HighTemperatureTransition = PT_WTRV;
}
