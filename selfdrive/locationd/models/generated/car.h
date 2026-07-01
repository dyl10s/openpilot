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
void car_err_fun(double *nom_x, double *delta_x, double *out_6318981254884856825);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6625913990707465652);
void car_H_mod_fun(double *state, double *out_6152129630444976452);
void car_f_fun(double *state, double dt, double *out_6830787204701444163);
void car_F_fun(double *state, double dt, double *out_2889206061873137605);
void car_h_25(double *state, double *unused, double *out_489826982790321982);
void car_H_25(double *state, double *unused, double *out_3101426217352337927);
void car_h_24(double *state, double *unused, double *out_8333585936499166595);
void car_H_24(double *state, double *unused, double *out_8374920500265350521);
void car_h_30(double *state, double *unused, double *out_7403112512094201377);
void car_H_30(double *state, double *unused, double *out_5619759175859586554);
void car_h_26(double *state, double *unused, double *out_6041958293954504594);
void car_H_26(double *state, double *unused, double *out_640077101521718297);
void car_h_27(double *state, double *unused, double *out_8492142189216518783);
void car_H_27(double *state, double *unused, double *out_3444995864059161643);
void car_h_29(double *state, double *unused, double *out_610869538462469598);
void car_H_29(double *state, double *unused, double *out_6129990520173978738);
void car_h_28(double *state, double *unused, double *out_3490468921555673138);
void car_H_28(double *state, double *unused, double *out_1047591503104448164);
void car_h_31(double *state, double *unused, double *out_1315479088578164838);
void car_H_31(double *state, double *unused, double *out_1266285203755069773);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}