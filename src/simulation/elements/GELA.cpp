#include "simulation/ElementCommon.h"

int Element_JELLO_update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);
static void create(ELEMENT_CREATE_FUNC_ARGS);

void Element::Element_GELA()
{
    Identifier = "DEFAULT_PT_GELA";
    Name = "GELA";
    Colour = PIXPACK(0xFF00FF);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;

    Advection = 0.3f;
    AirDrag = 0.02f * CFDS;
    AirLoss = 0.95f;
    Loss = 0.80f;
    Collision = 0.0f;
    Gravity = 0.15f;
    Diffusion = 0.00f;
    HotAir = 0.0003f * CFDS;
    Falldown = 2;

    Flammable = 0;
    Explosive = 0;
    Meltable = 0;
    Hardness = 2;
    PhotonReflectWavelengths = 0xFFFFFFFF;

    Weight = 45;

    DefaultProperties.temp = R_TEMP + 298.15f;
    HeatConduct = 0.15f;
    Description = "Gelatin dessert that jiggles when shaken.";

    Properties = TYPE_LIQUID | PROP_NEUTPASS;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = ITH;
    HighTemperatureTransition = NT;

    Update = &Element_GELA_update;
    Graphics = &graphics;
    Create = &create;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
    *colr = 0xFF;
    *colg = 0;
    *colb = 0xFF;
    *firea = 0;
    *firer = 0;
    *fireg = 0;
    *fireb = 0;
    *pixel_mode &= ~PMODE_BLUR;
    *pixel_mode &= ~FIRE_ADD;
    // Returning 0 means dynamic, do not cache
    return 0;
}

static void create(ELEMENT_CREATE_FUNC_ARGS)
{
    sim->parts[i].temp = RNG::Ref().between(290.15f, 310.15f);
    sim->parts[i].life = RNG::Ref().between(240, 359);
}
