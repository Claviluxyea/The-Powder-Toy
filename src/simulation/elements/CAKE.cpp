#include "simulation/ElementCommon.h"

int Element_CAKE_update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);
static void create(ELEMENT_CREATE_FUNC_ARGS);

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

    Update = &Element_CAKE_update;
    Graphics = &graphics;
    Create = &create;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
    int colr = 0x9C;
    int colg = 0x66;
    int colb = 0x1F;
    *firea = 0;
    *firer = colr;
    *fireg = colg;
    *fireb = colb;
    *pixel_mode = 0;
    return 0;
}

int Element_CAKE_update(UPDATE_FUNC_ARGS)
{
    return 0;
}

static void create(ELEMENT_CREATE_FUNC_ARGS)
{
    sim->parts[i].life = 1000;
}
