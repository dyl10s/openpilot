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
void car_err_fun(double *nom_x, double *delta_x, double *out_8838314869193199803);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1156535968876491631);
void car_H_mod_fun(double *state, double *out_7297179764193114402);
void car_f_fun(double *state, double dt, double *out_6025394122966474126);
void car_F_fun(double *state, double dt, double *out_2902406519648293307);
void car_h_25(double *state, double *unused, double *out_3236700917680503454);
void car_H_25(double *state, double *unused, double *out_1896008461719122835);
void car_h_24(double *state, double *unused, double *out_457181241716230531);
void car_H_24(double *state, double *unused, double *out_4068658060724622401);
void car_h_30(double *state, double *unused, double *out_7446777899208375721);
void car_H_30(double *state, double *unused, double *out_5020681879772493920);
void car_h_26(double *state, double *unused, double *out_8390287752110038156);
void car_H_26(double *state, double *unused, double *out_5637511780593179059);
void car_h_27(double *state, double *unused, double *out_7774899721600347349);
void car_H_27(double *state, double *unused, double *out_2845918567972069009);
void car_h_29(double *state, double *unused, double *out_8050093783884853238);
void car_H_29(double *state, double *unused, double *out_1132555841102517976);
void car_h_28(double *state, double *unused, double *out_1375858204186498203);
void car_H_28(double *state, double *unused, double *out_3949843175967012598);
void car_h_31(double *state, double *unused, double *out_7176856938506309920);
void car_H_31(double *state, double *unused, double *out_1865362499842162407);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}