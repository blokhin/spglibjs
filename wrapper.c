#include <spglib.h>
#include <stdio.h>
#include <emscripten.h>

void wrap_spg_get_syminfo(double flat_lattice[], double flat_position[], double dbl_types[], int num_atom, double tolerance, int dry_run);
void wrap_spg_get_syminfo(double flat_lattice[], double flat_position[], double dbl_types[], int num_atom, double tolerance, int dry_run)
{
	if (dry_run == 1) return;

	double lattice[3][3];
	int i, j, n;
	n = 0;
	for (i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			lattice[i][j] = flat_lattice[n];
			n++;
		}
	}

	double position[num_atom][3];
	i = 0;
	j = 0;
	n = 0;
	for (i = 0; i < num_atom; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			position[i][j] = flat_position[n];
			n++;
		}
	}

	int types[num_atom];
	i = 0;
	for (i = 0; i < num_atom; i++)
	{
		types[i] = (int) dbl_types[i];
	}

	SpglibDataset *dataset = spg_get_dataset(lattice, position, types, num_atom, tolerance);

	EM_ASM_({
		window.wrap_spg_handle_result($0, $1);
	}, dataset->spacegroup_number, dataset->international_symbol);
}

int main(void)
{
	double l[] = {4.9039976924631548, 0.0, 0.0, 0.0, 4.9039976924631548, 0.0, 0.0, 0.0, 4.9039976924631548};
	double p[] = {
	0.25, 0.25, 0.25,
	0.25, 0.75, 0.75,
	0.75, 0.75, 0.25,
	0.75, 0.25, 0.75,
	0.50, 0.0, 0.0,
	0.0, 0.50, 0.50,
	0.50, 0.0, 0.50,
	0.50, 0.50, 0.0,
	0.0, 0.50, 0.0,
	0.0, 0.0, 0.50
	};
	double t[] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	wrap_spg_get_syminfo(l, p, t, 10, 1e-5, 1);

	return 0;
}
