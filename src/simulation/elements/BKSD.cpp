#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_BKSD()
{
    Identifier = "DEFAULT_PT_BKSD";
    Name = "BKSD";
    Colour = PIXPACK(0xE0E0E0);
    MenuVisible = 1;
    MenuSection = SC_POWDERS;
    Enabled = 1;

    Advection = 0.6f;
    AirDrag = 0.02f * CFDS;
    AirLoss = 0.98f;
    Loss = 0.8f;
    Collision = 0.0f;
    Gravity = 0.1f;
    Diffusion = 0.00f;
    HotAir = 0.000f * CFDS;
    Falldown = 1;

    Flammable = 10;
    Explosive = 0;
    Meltable = 0;
    Hardness = 15;
    Weight = 80;

    HeatConduct = 10;
    Description = "Baking soda. Reacts with acids to produce carbon dioxide gas.";

    Properties = TYPE_PART | PROP_NEUTPASS;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = ITH;
    HighTemperatureTransition = NT;

    Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for (rx = -1; rx < 2; rx++) {
        for (ry = -1; ry < 2; ry++) {
            if (BOUNDS_CHECK && (rx || ry)) {
                r = pmap[y + ry][x + rx];
                if (TYP(r) == PT_VNGR) {
                    sim->part_change_type(i, x, y, PT_CO2);
                    return 1;
                }
            }
        }
    }
    return 0;
}
