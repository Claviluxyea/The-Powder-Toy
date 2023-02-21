#include "simulation/ElementCommon.h"

void Element::Element_CAKE()
{
    Identifier = "DEFAULT_PT_CAKE";
    Name = "CAKE";
    Colour = PIXPACK(0x9C661F);
    MenuVisible = 1;
    MenuSection = SC_SOLIDS;
    Enabled = 1;

    Advection = 0.0f;
    AirDrag = 0.0f;
    AirLoss = 1.0f;
    Loss = 0.0f;
    Collision = 0.0f;
    Gravity = 0.0f;
    Diffusion = 0.0f;
    HotAir = 0.0f;
    Falldown = 0;

    Flammable = 0;
    Explosive = 0;
    Meltable = 0;
    Hardness = 25;

    Weight = 100;

    HeatConduct = 50;
    Description = "A delicious dessert made of flour, sugar, and other ingredients.";

    Properties = TYPE_SOLID | PROP_LIFE_DEC;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = 373.0f;
    HighTemperatureTransition = NT;

}
