#include "simulation/ElementCommon.h"

void Element::Element_SYRP()
{
    Identifier = "DEFAULT_PT_SYRP";
    Name = "SYRP";
    Colour = PIXPACK(0x964B00);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;

    Advection = 0.6f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.98f;
    Loss = 0.8f;
    Collision = 0.0f;
    Gravity = 0.2f;
    Diffusion = 0.1f;
    HotAir = 0.000f * CFDS;
    Falldown = 2;

    Flammable = 5;
    Explosive = 0;
    Meltable = 0;
    Hardness = 2;

    Weight = 40;

    HeatConduct = 20;
    Description = "Viscous liquid, can stick to some materials.";

    Properties = TYPE_LIQUID | PROP_STICKY | PROP_NEUTPASS;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = 373.0f;
    HighTemperatureTransition = NT;
}

// todo
// add stickiness