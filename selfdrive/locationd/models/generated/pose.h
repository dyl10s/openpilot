#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4890483987619646593);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8601483282449025419);
void pose_H_mod_fun(double *state, double *out_998439548454101499);
void pose_f_fun(double *state, double dt, double *out_8602115666091671706);
void pose_F_fun(double *state, double dt, double *out_2374776546689160763);
void pose_h_4(double *state, double *unused, double *out_3610197400448725788);
void pose_H_4(double *state, double *unused, double *out_3341399300644519511);
void pose_h_10(double *state, double *unused, double *out_7074632649049224399);
void pose_H_10(double *state, double *unused, double *out_2352139524921342803);
void pose_h_13(double *state, double *unused, double *out_4134075991249929964);
void pose_H_13(double *state, double *unused, double *out_7494713564748331176);
void pose_h_14(double *state, double *unused, double *out_7088367226319057364);
void pose_H_14(double *state, double *unused, double *out_258610868349147215);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}