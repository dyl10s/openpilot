#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3574067617578089570);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1515328263168530495);
void pose_H_mod_fun(double *state, double *out_207229337745545750);
void pose_f_fun(double *state, double dt, double *out_3493541226789963130);
void pose_F_fun(double *state, double dt, double *out_5154051058888586616);
void pose_h_4(double *state, double *unused, double *out_5970382648807117116);
void pose_H_4(double *state, double *unused, double *out_4945289047293534985);
void pose_h_10(double *state, double *unused, double *out_520088425664385209);
void pose_H_10(double *state, double *unused, double *out_4050335309714945768);
void pose_h_13(double *state, double *unused, double *out_1434579794425570866);
void pose_H_13(double *state, double *unused, double *out_1111533583991010961);
void pose_h_14(double *state, double *unused, double *out_5370135948753942539);
void pose_H_14(double *state, double *unused, double *out_1862500614998162689);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}