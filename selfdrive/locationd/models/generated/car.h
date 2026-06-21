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
void car_err_fun(double *nom_x, double *delta_x, double *out_4621547673265240374);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4527069186343691966);
void car_H_mod_fun(double *state, double *out_6693843632392876727);
void car_f_fun(double *state, double dt, double *out_6624366898111013898);
void car_F_fun(double *state, double dt, double *out_6958933586889171013);
void car_h_25(double *state, double *unused, double *out_5696314533542565340);
void car_H_25(double *state, double *unused, double *out_5255877481426644938);
void car_h_24(double *state, double *unused, double *out_5128055596476793433);
void car_H_24(double *state, double *unused, double *out_4785419999383306214);
void car_h_30(double *state, double *unused, double *out_8810273519341179810);
void car_H_30(double *state, double *unused, double *out_728181151299036740);
void car_h_26(double *state, double *unused, double *out_93223108268356141);
void car_H_26(double *state, double *unused, double *out_1514374162552588714);
void car_h_27(double *state, double *unused, double *out_3729886127726509834);
void car_H_27(double *state, double *unused, double *out_2951775222482979957);
void car_h_29(double *state, double *unused, double *out_3887072796077638979);
void car_H_29(double *state, double *unused, double *out_1238412495613428924);
void car_h_28(double *state, double *unused, double *out_1271787139934335811);
void car_H_28(double *state, double *unused, double *out_3843986521456101650);
void car_h_31(double *state, double *unused, double *out_5853501201893694485);
void car_H_31(double *state, double *unused, double *out_5286523443303605366);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}