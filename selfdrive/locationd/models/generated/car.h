#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1263767819732456823);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3529295667634364975);
void car_H_mod_fun(double *state, double *out_5031874340838454569);
void car_f_fun(double *state, double dt, double *out_1529561136835295758);
void car_F_fun(double *state, double dt, double *out_665605705060988729);
void car_h_25(double *state, double *unused, double *out_2720961962516974745);
void car_H_25(double *state, double *unused, double *out_5863506002035943510);
void car_h_24(double *state, double *unused, double *out_1485787421513289501);
void car_H_24(double *state, double *unused, double *out_1554885631640983383);
void car_h_30(double *state, double *unused, double *out_2878148630868103890);
void car_H_30(double *state, double *unused, double *out_5992844949179183580);
void car_h_26(double *state, double *unused, double *out_158637420576228795);
void car_H_26(double *state, double *unused, double *out_8841734752799551882);
void car_h_27(double *state, double *unused, double *out_2280711305143870900);
void car_H_27(double *state, double *unused, double *out_8167608260979608491);
void car_h_29(double *state, double *unused, double *out_6142394781572372552);
void car_H_29(double *state, double *unused, double *out_5482613604864791396);
void car_h_28(double *state, double *unused, double *out_6701257866862969865);
void car_H_28(double *state, double *unused, double *out_7881731451775229646);
void car_h_31(double *state, double *unused, double *out_4049873263833376191);
void car_H_31(double *state, double *unused, double *out_5832860040158983082);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}