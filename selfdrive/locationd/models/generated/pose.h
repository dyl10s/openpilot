#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2755267697534836281);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4688414877314135206);
void pose_H_mod_fun(double *state, double *out_7837152669402150713);
void pose_f_fun(double *state, double dt, double *out_8293850048606202954);
void pose_F_fun(double *state, double dt, double *out_1277983044864762150);
void pose_h_4(double *state, double *unused, double *out_6167073772337384283);
void pose_H_4(double *state, double *unused, double *out_4761509597555442182);
void pose_h_10(double *state, double *unused, double *out_3137948981903642358);
void pose_H_10(double *state, double *unused, double *out_6455930617601822676);
void pose_h_13(double *state, double *unused, double *out_1578870771935541941);
void pose_H_13(double *state, double *unused, double *out_7973783422887774983);
void pose_h_14(double *state, double *unused, double *out_7672211974709550584);
void pose_H_14(double *state, double *unused, double *out_4326393070910558583);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}