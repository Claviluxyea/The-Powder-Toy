#include "simulation/ElementCommon.h"

static int graphics(GRAPHICS_FUNC_ARGS);
static void update(UPDATE_FUNC_ARGS);
static void serialize(SERIALIZE_FUNC_ARGS);

void Element::Element_EPOX()
{
    Identifier = "DEFAULT_PT_EPOX";
    Name = "EPOX";
    Colour = PIXPACK(0x808080);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;

    Advection = 0.8f;
    AirDrag = 0.02f * CFDS;
    AirLoss = 0.99f;
    Loss = 0.0f;
    Collision = 0.0f;
    Gravity = 0.5f;
    Diffusion = 0.5f;
    HotAir = 0.005f * CFDS;
    Falldown = 2;

    Flammable = 0;
    Explosive = 0;
    Meltable = 0;
    Hardness = 0;

    Weight = 60;

    HeatConduct = 100;
    Description = "Epoxy. A liquid adhesive resin.";

    Properties = TYPE_LIQUID | PROP_NEUTPASS | PROP_CONDUCTS;

    LowPressure = IPL;
    LowPressureTransition = PT_GAS;
    HighPressure = 100;
    HighPressureTransition = NT;
    LowTemperature = 273;
    LowTemperatureTransition = PT_ICEI;
    HighTemperature = 453;
    HighTemperatureTransition = PT_GAS;

    Graphics = &graphics;
    Update = &update;
    Serialize = &serialize;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
    *pixel_mode = 0;
    *colr = 128;
    *colg = 128;
    *colb = 128;
    return 0;
}

static void update(UPDATE_FUNC_ARGS)
{
    for (int i = 0; i < 4; i++)
    {
        int npos = sim->photons[x][y][i];
        if (!npos) continue;
        if (sim->pv[npos] != PT_GAS) continue;
        int npx = npos % sim->xres;
        int npy = npos / sim->xres;
        sim->create_part(npx, npy, PT_EPOX);
    }
}

static void serialize(SERIALIZE_FUNC_ARGS)
{
    SERIALIZE_DEFAULT_ELEMENT_VARS();
}
