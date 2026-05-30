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
void car_err_fun(double *nom_x, double *delta_x, double *out_4770141140221383025);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8267480455965364332);
void car_H_mod_fun(double *state, double *out_4700437164455479144);
void car_f_fun(double *state, double dt, double *out_2370248777466162255);
void car_F_fun(double *state, double dt, double *out_7809506053810665802);
void car_h_25(double *state, double *unused, double *out_2714863388055632273);
void car_H_25(double *state, double *unused, double *out_5824968876280212667);
void car_h_24(double *state, double *unused, double *out_8643275185285187003);
void car_H_24(double *state, double *unused, double *out_3403096309788982558);
void car_h_30(double *state, double *unused, double *out_4165494780684515440);
void car_H_30(double *state, double *unused, double *out_8094078867301730751);
void car_h_26(double *state, double *unused, double *out_749221491035445424);
void car_H_26(double *state, double *unused, double *out_8880271878555282725);
void car_h_27(double *state, double *unused, double *out_8472848302049370229);
void car_H_27(double *state, double *unused, double *out_5919315555501305840);
void car_h_29(double *state, double *unused, double *out_836178486976330205);
void car_H_29(double *state, double *unused, double *out_8604310211616122935);
void car_h_28(double *state, double *unused, double *out_5838057092722024830);
void car_H_28(double *state, double *unused, double *out_7878803590528102430);
void car_h_31(double *state, double *unused, double *out_5711256312889543433);
void car_H_31(double *state, double *unused, double *out_8254063776321931249);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}