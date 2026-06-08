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
void car_err_fun(double *nom_x, double *delta_x, double *out_5319131797443970272);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3644993322176215676);
void car_H_mod_fun(double *state, double *out_3163511227028018782);
void car_f_fun(double *state, double dt, double *out_1546760495327089109);
void car_F_fun(double *state, double dt, double *out_3348391828080031822);
void car_h_25(double *state, double *unused, double *out_4471759016602712561);
void car_H_25(double *state, double *unused, double *out_1740180598156646058);
void car_h_24(double *state, double *unused, double *out_3126254991737006136);
void car_H_24(double *state, double *unused, double *out_1269723116113307334);
void car_h_30(double *state, double *unused, double *out_4168118460115829323);
void car_H_30(double *state, double *unused, double *out_1610841651013405988);
void car_h_26(double *state, double *unused, double *out_2045289894744513329);
void car_H_26(double *state, double *unused, double *out_2001322720717410166);
void car_h_27(double *state, double *unused, double *out_1927282500811136585);
void car_H_27(double *state, double *unused, double *out_563921660787018923);
void car_h_29(double *state, double *unused, double *out_8022800891634675039);
void car_H_29(double *state, double *unused, double *out_2277284387656569956);
void car_h_28(double *state, double *unused, double *out_4964068552255469270);
void car_H_28(double *state, double *unused, double *out_313654116091243705);
void car_h_31(double *state, double *unused, double *out_834309488348690211);
void car_H_31(double *state, double *unused, double *out_1770826560033606486);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}