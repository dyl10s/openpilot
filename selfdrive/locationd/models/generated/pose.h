#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_609976965150865312);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8281732551506992950);
void pose_H_mod_fun(double *state, double *out_4168561321210011185);
void pose_f_fun(double *state, double dt, double *out_7595162637232814159);
void pose_F_fun(double *state, double dt, double *out_1091902965475609973);
void pose_h_4(double *state, double *unused, double *out_4271893182613978797);
void pose_H_4(double *state, double *unused, double *out_5265198332585855939);
void pose_h_10(double *state, double *unused, double *out_6068675735727225828);
void pose_H_10(double *state, double *unused, double *out_4012474741247108873);
void pose_h_13(double *state, double *unused, double *out_860321329376649767);
void pose_H_13(double *state, double *unused, double *out_2052924507253523138);
void pose_h_14(double *state, double *unused, double *out_5677441075365347292);
void pose_H_14(double *state, double *unused, double *out_1301957476246371410);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}