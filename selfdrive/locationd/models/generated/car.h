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
void car_err_fun(double *nom_x, double *delta_x, double *out_5572165619661696722);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1924778118840772208);
void car_H_mod_fun(double *state, double *out_5209558866032184805);
void car_f_fun(double *state, double dt, double *out_8731244167447695934);
void car_F_fun(double *state, double dt, double *out_5438267541501267753);
void car_h_25(double *state, double *unused, double *out_4244982229226314297);
void car_H_25(double *state, double *unused, double *out_1686578216042693128);
void car_h_24(double *state, double *unused, double *out_197553727547805858);
void car_H_24(double *state, double *unused, double *out_6506899720698681391);
void car_h_30(double *state, double *unused, double *out_4099462405005659326);
void car_H_30(double *state, double *unused, double *out_1815917163185933198);
void car_h_26(double *state, double *unused, double *out_9101135672666504971);
void car_H_26(double *state, double *unused, double *out_5428081534916749352);
void car_h_27(double *state, double *unused, double *out_756691038434531348);
void car_H_27(double *state, double *unused, double *out_3990680474986358109);
void car_h_29(double *state, double *unused, double *out_7739969642829208644);
void car_H_29(double *state, double *unused, double *out_1305685818871541014);
void car_h_28(double *state, double *unused, double *out_186818814467131087);
void car_H_28(double *state, double *unused, double *out_7660301854784111900);
void car_h_31(double *state, double *unused, double *out_3518283027594358144);
void car_H_31(double *state, double *unused, double *out_1655932254165732700);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}