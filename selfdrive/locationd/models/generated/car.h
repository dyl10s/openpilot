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
void car_err_fun(double *nom_x, double *delta_x, double *out_8544853402428642963);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4966147196229178357);
void car_H_mod_fun(double *state, double *out_5259284650049385741);
void car_f_fun(double *state, double dt, double *out_5571654789601065205);
void car_F_fun(double *state, double dt, double *out_7466465670683569774);
void car_h_25(double *state, double *unused, double *out_7657999268865908143);
void car_H_25(double *state, double *unused, double *out_8283767598475501035);
void car_h_24(double *state, double *unused, double *out_8959567811302299328);
void car_H_24(double *state, double *unused, double *out_1708195791883982934);
void car_h_30(double *state, double *unused, double *out_4661606344031996983);
void car_H_30(double *state, double *unused, double *out_5765434639968252408);
void car_h_26(double *state, double *unused, double *out_668943426824494179);
void car_H_26(double *state, double *unused, double *out_6421473156359994357);
void car_h_27(double *state, double *unused, double *out_4581587017363022418);
void car_H_27(double *state, double *unused, double *out_3541840568784309191);
void car_h_29(double *state, double *unused, double *out_3311352477521500941);
void car_H_29(double *state, double *unused, double *out_5255203295653860224);
void car_h_28(double *state, double *unused, double *out_1769034914093169035);
void car_H_28(double *state, double *unused, double *out_8109141760986160818);
void car_h_31(double *state, double *unused, double *out_3703077070402039012);
void car_H_31(double *state, double *unused, double *out_8253121636598540607);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}