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
void car_err_fun(double *nom_x, double *delta_x, double *out_575866575379183764);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5616167858322380498);
void car_H_mod_fun(double *state, double *out_6639538403135995006);
void car_f_fun(double *state, double dt, double *out_6721417124249708482);
void car_F_fun(double *state, double dt, double *out_2916284287213904038);
void car_h_25(double *state, double *unused, double *out_2044795451145406261);
void car_H_25(double *state, double *unused, double *out_8284225020584064933);
void car_h_24(double *state, double *unused, double *out_1441131931248447039);
void car_H_24(double *state, double *unused, double *out_4726299421781741797);
void car_h_30(double *state, double *unused, double *out_8638683365743472914);
void car_H_30(double *state, double *unused, double *out_8413563967727305003);
void car_h_26(double *state, double *unused, double *out_989338192432138572);
void car_H_26(double *state, double *unused, double *out_6421015734251430459);
void car_h_27(double *state, double *unused, double *out_7375345222001897423);
void car_H_27(double *state, double *unused, double *out_7858416794181821702);
void car_h_29(double *state, double *unused, double *out_4806387440305233057);
void car_H_29(double *state, double *unused, double *out_6145054067312270669);
void car_h_28(double *state, double *unused, double *out_6025091355491401381);
void car_H_28(double *state, double *unused, double *out_8108684338877596920);
void car_h_31(double *state, double *unused, double *out_2208042107618306896);
void car_H_31(double *state, double *unused, double *out_8253579058707104505);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}