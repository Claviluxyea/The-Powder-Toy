#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_BEER()
{
	Identifier = "DEFAULT_PT_BEER";
	Name = "BEER";
	Colour = PIXPACK(0xD5A54A);
	MenuVisible = 1;
	MenuSection = SC_LIQUID;
	Enabled = 1;

	Advection = 0.6f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 2;

	Flammable = 8;
	Explosive = 0;
	Meltable = 0;
	Hardness = 10;

	Weight = 28;

	DefaultProperties.temp = R_TEMP - 2.0f + 273.15f;
	HeatConduct = 25;
	Description = "A liquid that contains alcohol. Conducts electricity, and extinguishes fires.";

	Properties = TYPE_LIQUID | PROP_LIFE_DEC | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 273.15f;
	LowTemperatureTransition = PT_ICEI;
	HighTemperature = 373.0f;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for (rx = -1; rx < 2; rx++)
	{
		for (ry = -1; ry < 2; ry++)
		{
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y + ry][x + rx];
				if (!r)
					continue;
				if (TYP(r) == PT_FIRE && parts[ID(r)].ctype != PT_BEER)
				{
					sim->kill_part(ID(r));
					if (RNG::Ref().chance(1, 30))
					{
						sim->kill_part(i);
						return 1;
					}
				}
				else if (TYP(r) == PT_ROCK && fabs(parts[i].vx) + fabs(parts[i].vy) >= 0.5 && RNG::Ref().chance(1, 1000))
				{
					if (RNG::Ref().chance(1, 3))
						sim->part_change_type(ID(r), x + rx, y + ry, PT_SAND);
					else
						sim->part_change_type(ID(r), x + rx, y + ry, PT_STNE);
				}
			}
		}
	}
	return 0;
}
