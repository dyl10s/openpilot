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
void car_err_fun(double *nom_x, double *delta_x, double *out_8928034227051207060);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4996368579389837639);
void car_H_mod_fun(double *state, double *out_8354260345920403618);
void car_f_fun(double *state, double dt, double *out_18975094040046356);
void car_F_fun(double *state, double dt, double *out_8298920985484652828);
void car_h_25(double *state, double *unused, double *out_3416906007265727326);
void car_H_25(double *state, double *unused, double *out_6569503077799656321);
void car_h_24(double *state, double *unused, double *out_6593726717602388151);
void car_H_24(double *state, double *unused, double *out_3011577478997333185);
void car_h_30(double *state, double *unused, double *out_4267886705157640301);
void car_H_30(double *state, double *unused, double *out_6698842024942896391);
void car_h_26(double *state, double *unused, double *out_9177184100891065670);
void car_H_26(double *state, double *unused, double *out_8135737677035839071);
void car_h_27(double *state, double *unused, double *out_6233528602177827150);
void car_H_27(double *state, double *unused, double *out_8873605336743321302);
void car_h_29(double *state, double *unused, double *out_3440336872306683482);
void car_H_29(double *state, double *unused, double *out_6188610680628504207);
void car_h_28(double *state, double *unused, double *out_2162754552967525717);
void car_H_28(double *state, double *unused, double *out_2777376993027148707);
void car_h_31(double *state, double *unused, double *out_8180530295696168540);
void car_H_31(double *state, double *unused, double *out_6538857115922695893);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}