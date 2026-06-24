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
void car_err_fun(double *nom_x, double *delta_x, double *out_8227521165613923208);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5130787649833322574);
void car_H_mod_fun(double *state, double *out_7022051272719162928);
void car_f_fun(double *state, double dt, double *out_2984704176532588452);
void car_F_fun(double *state, double dt, double *out_314948888837440074);
void car_h_25(double *state, double *unused, double *out_26482314378299030);
void car_H_25(double *state, double *unused, double *out_3499070622729671251);
void car_h_24(double *state, double *unused, double *out_7613998408709405751);
void car_H_24(double *state, double *unused, double *out_1273362838750802689);
void car_h_30(double *state, double *unused, double *out_7907754965132348215);
void car_H_30(double *state, double *unused, double *out_3417619718761945504);
void car_h_26(double *state, double *unused, double *out_7304439080455870698);
void car_H_26(double *state, double *unused, double *out_2842216558619359347);
void car_h_27(double *state, double *unused, double *out_8106273622613022122);
void car_H_27(double *state, double *unused, double *out_1242856406961520593);
void car_h_29(double *state, double *unused, double *out_1742679644311206261);
void car_H_29(double *state, double *unused, double *out_3927851063076337688);
void car_h_28(double *state, double *unused, double *out_6626345518038675162);
void car_H_28(double *state, double *unused, double *out_1154547953993192886);
void car_h_31(double *state, double *unused, double *out_1477113707007182197);
void car_H_31(double *state, double *unused, double *out_3468424660852710823);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}