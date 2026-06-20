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
void car_err_fun(double *nom_x, double *delta_x, double *out_3928719841740981699);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5321639104726738897);
void car_H_mod_fun(double *state, double *out_8540419750358065319);
void car_f_fun(double *state, double dt, double *out_5791363154948922080);
void car_F_fun(double *state, double dt, double *out_4207718710431964525);
void car_h_25(double *state, double *unused, double *out_6333669642167287903);
void car_H_25(double *state, double *unused, double *out_619081717384205514);
void car_h_24(double *state, double *unused, double *out_8914852456241702348);
void car_H_24(double *state, double *unused, double *out_6035123740723980243);
void car_h_30(double *state, double *unused, double *out_6608863704451793792);
void car_H_30(double *state, double *unused, double *out_5146778047511813712);
void car_h_26(double *state, double *unused, double *out_730578216893078704);
void car_H_26(double *state, double *unused, double *out_4360585036258261738);
void car_h_27(double *state, double *unused, double *out_7111401163881418068);
void car_H_27(double *state, double *unused, double *out_7321541359312238623);
void car_h_29(double *state, double *unused, double *out_3249717687452916416);
void car_H_29(double *state, double *unused, double *out_4636546703197421528);
void car_h_28(double *state, double *unused, double *out_8801848998617099028);
void car_H_28(double *state, double *unused, double *out_2672916431632095277);
void car_h_31(double *state, double *unused, double *out_178222446326627774);
void car_H_31(double *state, double *unused, double *out_4986793138491613214);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}