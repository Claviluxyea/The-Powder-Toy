#include "simulation/ElementCommon.h"
// kinda useless element
static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_TPST() {
	Identifier = "DEFAULT_PT_TPST";
	Name = "TPST";
	Colour = PIXPACK(0xFFFFFF);
	MenuVisible = 0;
	MenuSection = SC_SPECIAL;
	Enabled = 1;

	Advection = 0.5f;
	AirDrag = 0.02f * CFDS;
	AirLoss = 0.95f;
	Loss = 0.70f;
	Collision = 0.0f;
	Gravity = 0.05f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 40;

	Weight = 24;

	HeatConduct = 60;
	Description = "Toothpaste. Cleans teeth, not particles.";
	DefaultProperties.life = 300;

	Properties = TYPE_PART | PROP_NEUTPASS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = PT_ICEI;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
	Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS) {
	if (fabs(sim->pv[y / CELL][x / CELL]) > 5.0f || parts[i].temp < 273.15f || parts[i].temp > 373.15f) {
		sim->kill_part(i);
		return 1;
	}

	if (parts[i].tmp > 0 && RNG::Ref().chance(1, 20)) {
		int rx, ry, r;
		for (rx = -1; rx <= 1; rx++)
			for (ry = -1; ry <= 1; ry++)
				if (BOUNDS_CHECK && (rx || ry)) {
					if (parts[i].tmp <= 0) return 0;

					r = pmap[y + ry][x + rx];
					if (!r) {
						int ni = sim->create_part(-1, x + rx, y + ry, PT_TPST);
						if (ni >= 0) {
							parts[ni].tmp = parts[i].tmp - 1;
							parts[i].tmp--;
						}
						continue;
					}

					if (TYP(r) == PT_WATR || TYP(r) == PT_ACID) {
						sim->kill_part(i);
						return 1;
					}
				}
	}

	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS) {
	*pixel_mode |= PMODE_BLUR;

	*pixel_mode |= FIRE_BLEND;
	*firer = *fireg = *fireb = 200;
	*firea = 50;

	return 0;
}
