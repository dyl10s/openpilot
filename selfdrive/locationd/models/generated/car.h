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
void car_err_fun(double *nom_x, double *delta_x, double *out_8318180392745555938);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5934219001129015779);
void car_H_mod_fun(double *state, double *out_1926641469114901966);
void car_f_fun(double *state, double dt, double *out_5221835679523029107);
void car_F_fun(double *state, double dt, double *out_1809598832794027362);
void car_h_25(double *state, double *unused, double *out_1465140640781784100);
void car_H_25(double *state, double *unused, double *out_4563198394130328160);
void car_h_24(double *state, double *unused, double *out_1585421017382478864);
void car_H_24(double *state, double *unused, double *out_6440871086590507136);
void car_h_30(double *state, double *unused, double *out_1189946578497278211);
void car_H_30(double *state, double *unused, double *out_4692537341273568230);
void car_h_26(double *state, double *unused, double *out_1793262463173755728);
void car_H_26(double *state, double *unused, double *out_8304701713004384384);
void car_h_27(double *state, double *unused, double *out_7864182158195633246);
void car_H_27(double *state, double *unused, double *out_6867300653073993141);
void car_h_29(double *state, double *unused, double *out_4002498681767131594);
void car_H_29(double *state, double *unused, double *out_8580663379943544174);
void car_h_28(double *state, double *unused, double *out_8807692011097295681);
void car_H_28(double *state, double *unused, double *out_4783681676696476868);
void car_h_31(double *state, double *unused, double *out_7031520040481955892);
void car_H_31(double *state, double *unused, double *out_4532552432253367732);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}