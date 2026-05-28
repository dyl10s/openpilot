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
void car_err_fun(double *nom_x, double *delta_x, double *out_7019737380087612192);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5837591879726777447);
void car_H_mod_fun(double *state, double *out_7212341887433844410);
void car_f_fun(double *state, double dt, double *out_884422573903963140);
void car_F_fun(double *state, double dt, double *out_7930257990036637257);
void car_h_25(double *state, double *unused, double *out_7492620826943930634);
void car_H_25(double *state, double *unused, double *out_6439571343347838097);
void car_h_24(double *state, double *unused, double *out_4985338018763469281);
void car_H_24(double *state, double *unused, double *out_7852599591386246934);
void car_h_30(double *state, double *unused, double *out_3190857989944948541);
void car_H_30(double *state, double *unused, double *out_8957904301855086724);
void car_h_26(double *state, double *unused, double *out_1810815277715897104);
void car_H_26(double *state, double *unused, double *out_2698068024473781873);
void car_h_27(double *state, double *unused, double *out_1225216092924761692);
void car_H_27(double *state, double *unused, double *out_6783140990054661813);
void car_h_29(double *state, double *unused, double *out_8192531257605794186);
void car_H_29(double *state, double *unused, double *out_8978608427540072708);
void car_h_28(double *state, double *unused, double *out_6973827342419625862);
void car_H_28(double *state, double *unused, double *out_4385736629099948334);
void car_h_31(double *state, double *unused, double *out_7638140651164585605);
void car_H_31(double *state, double *unused, double *out_2071859922240430397);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}