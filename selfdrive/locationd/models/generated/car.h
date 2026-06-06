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
void car_err_fun(double *nom_x, double *delta_x, double *out_6669412735228971409);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6779967762183071907);
void car_H_mod_fun(double *state, double *out_6491699675187271682);
void car_f_fun(double *state, double dt, double *out_2858314681790673269);
void car_F_fun(double *state, double dt, double *out_1519249616957804461);
void car_h_25(double *state, double *unused, double *out_7032479070992890953);
void car_H_25(double *state, double *unused, double *out_2968651036541906534);
void car_h_24(double *state, double *unused, double *out_5672934374792452147);
void car_H_24(double *state, double *unused, double *out_5194358820520775096);
void car_h_30(double *state, double *unused, double *out_6875292402641761808);
void car_H_30(double *state, double *unused, double *out_8561402695676028327);
void car_h_26(double *state, double *unused, double *out_5172410153653940662);
void car_H_26(double *state, double *unused, double *out_6273177006302707135);
void car_h_27(double *state, double *unused, double *out_402664363435809860);
void car_H_27(double *state, double *unused, double *out_7710578066233098378);
void car_h_29(double *state, double *unused, double *out_7173499589786160796);
void car_H_29(double *state, double *unused, double *out_8051171351361636143);
void car_h_28(double *state, double *unused, double *out_1346174216337472295);
void car_H_28(double *state, double *unused, double *out_5313173705278384899);
void car_h_31(double *state, double *unused, double *out_6757285008708385064);
void car_H_31(double *state, double *unused, double *out_2999296998418866962);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}