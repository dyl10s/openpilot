#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3328634486354213070);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2068367058924519839);
void pose_H_mod_fun(double *state, double *out_5273281981643743211);
void pose_f_fun(double *state, double dt, double *out_3798976948542527989);
void pose_F_fun(double *state, double dt, double *out_5376087696404799721);
void pose_h_4(double *state, double *unused, double *out_6100547545538860384);
void pose_H_4(double *state, double *unused, double *out_9045089191487650783);
void pose_h_10(double *state, double *unused, double *out_7661539883733460450);
void pose_H_10(double *state, double *unused, double *out_2752907549792722588);
void pose_h_13(double *state, double *unused, double *out_4247381704481051963);
void pose_H_13(double *state, double *unused, double *out_1791023673905199904);
void pose_h_14(double *state, double *unused, double *out_7786063953392294783);
void pose_H_14(double *state, double *unused, double *out_5438414025882416304);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}