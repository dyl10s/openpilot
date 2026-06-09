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
void car_err_fun(double *nom_x, double *delta_x, double *out_5171593721555630090);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8159896824054378862);
void car_H_mod_fun(double *state, double *out_2621434864577473374);
void car_f_fun(double *state, double dt, double *out_5898225613213012342);
void car_F_fun(double *state, double dt, double *out_289209120563918309);
void car_h_25(double *state, double *unused, double *out_1048536752434567181);
void car_H_25(double *state, double *unused, double *out_6632120983219841005);
void car_h_24(double *state, double *unused, double *out_7601461491001714773);
void car_H_24(double *state, double *unused, double *out_4459471384214341439);
void car_h_30(double *state, double *unused, double *out_4685986280688589531);
void car_H_30(double *state, double *unused, double *out_9150453941727089632);
void car_h_26(double *state, double *unused, double *out_4082670396012112014);
void car_H_26(double *state, double *unused, double *out_8510097120728910010);
void car_h_27(double *state, double *unused, double *out_9178210209371601407);
void car_H_27(double *state, double *unused, double *out_7072696060798518767);
void car_h_29(double *state, double *unused, double *out_8534850577185637138);
void car_H_29(double *state, double *unused, double *out_8786058787668069800);
void car_h_28(double *state, double *unused, double *out_2931759151911427939);
void car_H_28(double *state, double *unused, double *out_4578286268971951242);
void car_h_31(double *state, double *unused, double *out_5027768451407450342);
void car_H_31(double *state, double *unused, double *out_4737947839977893358);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}