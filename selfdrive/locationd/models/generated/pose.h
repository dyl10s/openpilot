#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8259662850093450970);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7477554158578246383);
void pose_H_mod_fun(double *state, double *out_6622639630704307229);
void pose_f_fun(double *state, double dt, double *out_2747407686181114080);
void pose_F_fun(double *state, double dt, double *out_5168326300746653192);
void pose_h_4(double *state, double *unused, double *out_8670716112105694718);
void pose_H_4(double *state, double *unused, double *out_1470121245665226494);
void pose_h_10(double *state, double *unused, double *out_6106389642402371296);
void pose_H_10(double *state, double *unused, double *out_8155893514424523240);
void pose_h_13(double *state, double *unused, double *out_8157156466131107868);
void pose_H_13(double *state, double *unused, double *out_1742152579667106307);
void pose_h_14(double *state, double *unused, double *out_568036792274749064);
void pose_H_14(double *state, double *unused, double *out_4552909677960598790);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}