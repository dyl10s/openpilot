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
void car_err_fun(double *nom_x, double *delta_x, double *out_8297833156591934141);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5141050122927326429);
void car_H_mod_fun(double *state, double *out_3136124430455300167);
void car_f_fun(double *state, double dt, double *out_1448995956687043074);
void car_F_fun(double *state, double dt, double *out_8554411337332249015);
void car_h_25(double *state, double *unused, double *out_5109543262436323086);
void car_H_25(double *state, double *unused, double *out_3972534066578099913);
void car_h_24(double *state, double *unused, double *out_4829050840884247589);
void car_H_24(double *state, double *unused, double *out_7530459665380423049);
void car_h_30(double *state, double *unused, double *out_5876642047024340205);
void car_H_30(double *state, double *unused, double *out_3843195119434859843);
void car_h_26(double *state, double *unused, double *out_874968779363494560);
void car_H_26(double *state, double *unused, double *out_231030747704043689);
void car_h_27(double *state, double *unused, double *out_107869994775477441);
void car_H_27(double *state, double *unused, double *out_1668431807634434932);
void car_h_29(double *state, double *unused, double *out_2839855995580007520);
void car_H_29(double *state, double *unused, double *out_4353426463749252027);
void car_h_28(double *state, double *unused, double *out_1051379847677139876);
void car_H_28(double *state, double *unused, double *out_6317056735314578278);
void car_h_31(double *state, double *unused, double *out_2653721994384349355);
void car_H_31(double *state, double *unused, double *out_4003180028455060341);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}