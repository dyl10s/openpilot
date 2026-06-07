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
void car_err_fun(double *nom_x, double *delta_x, double *out_3499577995962015470);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7704661140039100406);
void car_H_mod_fun(double *state, double *out_3593592511346668572);
void car_f_fun(double *state, double dt, double *out_5138495986546656101);
void car_F_fun(double *state, double dt, double *out_9094696385837044219);
void car_h_25(double *state, double *unused, double *out_1209975406708631015);
void car_H_25(double *state, double *unused, double *out_4098926953546965284);
void car_h_24(double *state, double *unused, double *out_5058461778376183297);
void car_H_24(double *state, double *unused, double *out_4943923562330660683);
void car_h_30(double *state, double *unused, double *out_5560859819641719921);
void car_H_30(double *state, double *unused, double *out_7431126778670969577);
void car_h_26(double *state, double *unused, double *out_4617349966740057486);
void car_H_26(double *state, double *unused, double *out_4755781017657277188);
void car_h_27(double *state, double *unused, double *out_6211648674369476660);
void car_H_27(double *state, double *unused, double *out_8840853983238157128);
void car_h_29(double *state, double *unused, double *out_559186551980874276);
void car_H_29(double *state, double *unused, double *out_6920895434356577393);
void car_h_28(double *state, double *unused, double *out_7233422131679229311);
void car_H_28(double *state, double *unused, double *out_6443449622283443649);
void car_h_31(double *state, double *unused, double *out_8973240663529303456);
void car_H_31(double *state, double *unused, double *out_4129572915423925712);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}