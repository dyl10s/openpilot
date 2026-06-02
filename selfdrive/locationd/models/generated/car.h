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
void car_err_fun(double *nom_x, double *delta_x, double *out_6333242559483084265);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_829248915283082072);
void car_H_mod_fun(double *state, double *out_8283696179185346057);
void car_f_fun(double *state, double dt, double *out_3453347444055346076);
void car_F_fun(double *state, double dt, double *out_1825222330008905672);
void car_h_25(double *state, double *unused, double *out_7364871104219513908);
void car_H_25(double *state, double *unused, double *out_5259356069339540719);
void car_h_24(double *state, double *unused, double *out_6181950591427252357);
void car_H_24(double *state, double *unused, double *out_1316215737251977382);
void car_h_30(double *state, double *unused, double *out_4311037743139686772);
void car_H_30(double *state, double *unused, double *out_1657334272152076036);
void car_h_26(double *state, double *unused, double *out_8569605146509354979);
void car_H_26(double *state, double *unused, double *out_9000859388213596943);
void car_h_27(double *state, double *unused, double *out_2363197836558668263);
void car_H_27(double *state, double *unused, double *out_517429039648348875);
void car_h_29(double *state, double *unused, double *out_1498485639869833389);
void car_H_29(double *state, double *unused, double *out_2230791766517899908);
void car_h_28(double *state, double *unused, double *out_6657345575881808179);
void car_H_28(double *state, double *unused, double *out_7313190783587430482);
void car_h_31(double *state, double *unused, double *out_398394152601158533);
void car_H_31(double *state, double *unused, double *out_5228710107462580291);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}