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
void car_err_fun(double *nom_x, double *delta_x, double *out_284207352707246819);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_494072413816411138);
void car_H_mod_fun(double *state, double *out_4975994215663677500);
void car_f_fun(double *state, double dt, double *out_1721040043494422786);
void car_F_fun(double *state, double dt, double *out_6408657319260780093);
void car_h_25(double *state, double *unused, double *out_8679682106878424978);
void car_H_25(double *state, double *unused, double *out_4470659773463380788);
void car_h_24(double *state, double *unused, double *out_5665719925403943373);
void car_H_24(double *state, double *unused, double *out_7514976983467728980);
void car_h_30(double *state, double *unused, double *out_6129612438577104288);
void car_H_30(double *state, double *unused, double *out_4599998720606620858);
void car_h_26(double *state, double *unused, double *out_6887462583737923098);
void car_H_26(double *state, double *unused, double *out_3813805709353068884);
void car_h_27(double *state, double *unused, double *out_3337814870992394415);
void car_H_27(double *state, double *unused, double *out_6774762032407045769);
void car_h_29(double *state, double *unused, double *out_5302062605726147469);
void car_H_29(double *state, double *unused, double *out_4089767376292228674);
void car_h_28(double *state, double *unused, double *out_301028819548061730);
void car_H_28(double *state, double *unused, double *out_2126137104726902423);
void car_h_31(double *state, double *unused, double *out_213227004039568063);
void car_H_31(double *state, double *unused, double *out_4440013811586420360);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}