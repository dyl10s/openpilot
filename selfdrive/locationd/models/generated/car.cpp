#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7026316075073471994) {
   out_7026316075073471994[0] = delta_x[0] + nom_x[0];
   out_7026316075073471994[1] = delta_x[1] + nom_x[1];
   out_7026316075073471994[2] = delta_x[2] + nom_x[2];
   out_7026316075073471994[3] = delta_x[3] + nom_x[3];
   out_7026316075073471994[4] = delta_x[4] + nom_x[4];
   out_7026316075073471994[5] = delta_x[5] + nom_x[5];
   out_7026316075073471994[6] = delta_x[6] + nom_x[6];
   out_7026316075073471994[7] = delta_x[7] + nom_x[7];
   out_7026316075073471994[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4587773260780687079) {
   out_4587773260780687079[0] = -nom_x[0] + true_x[0];
   out_4587773260780687079[1] = -nom_x[1] + true_x[1];
   out_4587773260780687079[2] = -nom_x[2] + true_x[2];
   out_4587773260780687079[3] = -nom_x[3] + true_x[3];
   out_4587773260780687079[4] = -nom_x[4] + true_x[4];
   out_4587773260780687079[5] = -nom_x[5] + true_x[5];
   out_4587773260780687079[6] = -nom_x[6] + true_x[6];
   out_4587773260780687079[7] = -nom_x[7] + true_x[7];
   out_4587773260780687079[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_255548955770617621) {
   out_255548955770617621[0] = 1.0;
   out_255548955770617621[1] = 0.0;
   out_255548955770617621[2] = 0.0;
   out_255548955770617621[3] = 0.0;
   out_255548955770617621[4] = 0.0;
   out_255548955770617621[5] = 0.0;
   out_255548955770617621[6] = 0.0;
   out_255548955770617621[7] = 0.0;
   out_255548955770617621[8] = 0.0;
   out_255548955770617621[9] = 0.0;
   out_255548955770617621[10] = 1.0;
   out_255548955770617621[11] = 0.0;
   out_255548955770617621[12] = 0.0;
   out_255548955770617621[13] = 0.0;
   out_255548955770617621[14] = 0.0;
   out_255548955770617621[15] = 0.0;
   out_255548955770617621[16] = 0.0;
   out_255548955770617621[17] = 0.0;
   out_255548955770617621[18] = 0.0;
   out_255548955770617621[19] = 0.0;
   out_255548955770617621[20] = 1.0;
   out_255548955770617621[21] = 0.0;
   out_255548955770617621[22] = 0.0;
   out_255548955770617621[23] = 0.0;
   out_255548955770617621[24] = 0.0;
   out_255548955770617621[25] = 0.0;
   out_255548955770617621[26] = 0.0;
   out_255548955770617621[27] = 0.0;
   out_255548955770617621[28] = 0.0;
   out_255548955770617621[29] = 0.0;
   out_255548955770617621[30] = 1.0;
   out_255548955770617621[31] = 0.0;
   out_255548955770617621[32] = 0.0;
   out_255548955770617621[33] = 0.0;
   out_255548955770617621[34] = 0.0;
   out_255548955770617621[35] = 0.0;
   out_255548955770617621[36] = 0.0;
   out_255548955770617621[37] = 0.0;
   out_255548955770617621[38] = 0.0;
   out_255548955770617621[39] = 0.0;
   out_255548955770617621[40] = 1.0;
   out_255548955770617621[41] = 0.0;
   out_255548955770617621[42] = 0.0;
   out_255548955770617621[43] = 0.0;
   out_255548955770617621[44] = 0.0;
   out_255548955770617621[45] = 0.0;
   out_255548955770617621[46] = 0.0;
   out_255548955770617621[47] = 0.0;
   out_255548955770617621[48] = 0.0;
   out_255548955770617621[49] = 0.0;
   out_255548955770617621[50] = 1.0;
   out_255548955770617621[51] = 0.0;
   out_255548955770617621[52] = 0.0;
   out_255548955770617621[53] = 0.0;
   out_255548955770617621[54] = 0.0;
   out_255548955770617621[55] = 0.0;
   out_255548955770617621[56] = 0.0;
   out_255548955770617621[57] = 0.0;
   out_255548955770617621[58] = 0.0;
   out_255548955770617621[59] = 0.0;
   out_255548955770617621[60] = 1.0;
   out_255548955770617621[61] = 0.0;
   out_255548955770617621[62] = 0.0;
   out_255548955770617621[63] = 0.0;
   out_255548955770617621[64] = 0.0;
   out_255548955770617621[65] = 0.0;
   out_255548955770617621[66] = 0.0;
   out_255548955770617621[67] = 0.0;
   out_255548955770617621[68] = 0.0;
   out_255548955770617621[69] = 0.0;
   out_255548955770617621[70] = 1.0;
   out_255548955770617621[71] = 0.0;
   out_255548955770617621[72] = 0.0;
   out_255548955770617621[73] = 0.0;
   out_255548955770617621[74] = 0.0;
   out_255548955770617621[75] = 0.0;
   out_255548955770617621[76] = 0.0;
   out_255548955770617621[77] = 0.0;
   out_255548955770617621[78] = 0.0;
   out_255548955770617621[79] = 0.0;
   out_255548955770617621[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5905678958362697737) {
   out_5905678958362697737[0] = state[0];
   out_5905678958362697737[1] = state[1];
   out_5905678958362697737[2] = state[2];
   out_5905678958362697737[3] = state[3];
   out_5905678958362697737[4] = state[4];
   out_5905678958362697737[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5905678958362697737[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5905678958362697737[7] = state[7];
   out_5905678958362697737[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2348542156060617804) {
   out_2348542156060617804[0] = 1;
   out_2348542156060617804[1] = 0;
   out_2348542156060617804[2] = 0;
   out_2348542156060617804[3] = 0;
   out_2348542156060617804[4] = 0;
   out_2348542156060617804[5] = 0;
   out_2348542156060617804[6] = 0;
   out_2348542156060617804[7] = 0;
   out_2348542156060617804[8] = 0;
   out_2348542156060617804[9] = 0;
   out_2348542156060617804[10] = 1;
   out_2348542156060617804[11] = 0;
   out_2348542156060617804[12] = 0;
   out_2348542156060617804[13] = 0;
   out_2348542156060617804[14] = 0;
   out_2348542156060617804[15] = 0;
   out_2348542156060617804[16] = 0;
   out_2348542156060617804[17] = 0;
   out_2348542156060617804[18] = 0;
   out_2348542156060617804[19] = 0;
   out_2348542156060617804[20] = 1;
   out_2348542156060617804[21] = 0;
   out_2348542156060617804[22] = 0;
   out_2348542156060617804[23] = 0;
   out_2348542156060617804[24] = 0;
   out_2348542156060617804[25] = 0;
   out_2348542156060617804[26] = 0;
   out_2348542156060617804[27] = 0;
   out_2348542156060617804[28] = 0;
   out_2348542156060617804[29] = 0;
   out_2348542156060617804[30] = 1;
   out_2348542156060617804[31] = 0;
   out_2348542156060617804[32] = 0;
   out_2348542156060617804[33] = 0;
   out_2348542156060617804[34] = 0;
   out_2348542156060617804[35] = 0;
   out_2348542156060617804[36] = 0;
   out_2348542156060617804[37] = 0;
   out_2348542156060617804[38] = 0;
   out_2348542156060617804[39] = 0;
   out_2348542156060617804[40] = 1;
   out_2348542156060617804[41] = 0;
   out_2348542156060617804[42] = 0;
   out_2348542156060617804[43] = 0;
   out_2348542156060617804[44] = 0;
   out_2348542156060617804[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2348542156060617804[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2348542156060617804[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2348542156060617804[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2348542156060617804[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2348542156060617804[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2348542156060617804[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2348542156060617804[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2348542156060617804[53] = -9.8100000000000005*dt;
   out_2348542156060617804[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2348542156060617804[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2348542156060617804[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2348542156060617804[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2348542156060617804[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2348542156060617804[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2348542156060617804[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2348542156060617804[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2348542156060617804[62] = 0;
   out_2348542156060617804[63] = 0;
   out_2348542156060617804[64] = 0;
   out_2348542156060617804[65] = 0;
   out_2348542156060617804[66] = 0;
   out_2348542156060617804[67] = 0;
   out_2348542156060617804[68] = 0;
   out_2348542156060617804[69] = 0;
   out_2348542156060617804[70] = 1;
   out_2348542156060617804[71] = 0;
   out_2348542156060617804[72] = 0;
   out_2348542156060617804[73] = 0;
   out_2348542156060617804[74] = 0;
   out_2348542156060617804[75] = 0;
   out_2348542156060617804[76] = 0;
   out_2348542156060617804[77] = 0;
   out_2348542156060617804[78] = 0;
   out_2348542156060617804[79] = 0;
   out_2348542156060617804[80] = 1;
}
void h_25(double *state, double *unused, double *out_5870924613014703511) {
   out_5870924613014703511[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7665789077203242184) {
   out_7665789077203242184[0] = 0;
   out_7665789077203242184[1] = 0;
   out_7665789077203242184[2] = 0;
   out_7665789077203242184[3] = 0;
   out_7665789077203242184[4] = 0;
   out_7665789077203242184[5] = 0;
   out_7665789077203242184[6] = 1;
   out_7665789077203242184[7] = 0;
   out_7665789077203242184[8] = 0;
}
void h_24(double *state, double *unused, double *out_7175962086981114995) {
   out_7175962086981114995[0] = state[4];
   out_7175962086981114995[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2919279750236733150) {
   out_2919279750236733150[0] = 0;
   out_2919279750236733150[1] = 0;
   out_2919279750236733150[2] = 0;
   out_2919279750236733150[3] = 0;
   out_2919279750236733150[4] = 1;
   out_2919279750236733150[5] = 0;
   out_2919279750236733150[6] = 0;
   out_2919279750236733150[7] = 0;
   out_2919279750236733150[8] = 0;
   out_2919279750236733150[9] = 0;
   out_2919279750236733150[10] = 0;
   out_2919279750236733150[11] = 0;
   out_2919279750236733150[12] = 0;
   out_2919279750236733150[13] = 0;
   out_2919279750236733150[14] = 1;
   out_2919279750236733150[15] = 0;
   out_2919279750236733150[16] = 0;
   out_2919279750236733150[17] = 0;
}
void h_30(double *state, double *unused, double *out_619120766018658974) {
   out_619120766018658974[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8262622037999060805) {
   out_8262622037999060805[0] = 0;
   out_8262622037999060805[1] = 0;
   out_8262622037999060805[2] = 0;
   out_8262622037999060805[3] = 0;
   out_8262622037999060805[4] = 1;
   out_8262622037999060805[5] = 0;
   out_8262622037999060805[6] = 0;
   out_8262622037999060805[7] = 0;
   out_8262622037999060805[8] = 0;
}
void h_26(double *state, double *unused, double *out_2561596907152652789) {
   out_2561596907152652789[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3924285758329185960) {
   out_3924285758329185960[0] = 0;
   out_3924285758329185960[1] = 0;
   out_3924285758329185960[2] = 0;
   out_3924285758329185960[3] = 0;
   out_3924285758329185960[4] = 0;
   out_3924285758329185960[5] = 0;
   out_3924285758329185960[6] = 0;
   out_3924285758329185960[7] = 1;
   out_3924285758329185960[8] = 0;
}
void h_27(double *state, double *unused, double *out_6474240497691181028) {
   out_6474240497691181028[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6039027966815117588) {
   out_6039027966815117588[0] = 0;
   out_6039027966815117588[1] = 0;
   out_6039027966815117588[2] = 0;
   out_6039027966815117588[3] = 1;
   out_6039027966815117588[4] = 0;
   out_6039027966815117588[5] = 0;
   out_6039027966815117588[6] = 0;
   out_6039027966815117588[7] = 0;
   out_6039027966815117588[8] = 0;
}
void h_29(double *state, double *unused, double *out_5627330291441514494) {
   out_5627330291441514494[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7752390693684668621) {
   out_7752390693684668621[0] = 0;
   out_7752390693684668621[1] = 1;
   out_7752390693684668621[2] = 0;
   out_7752390693684668621[3] = 0;
   out_7752390693684668621[4] = 0;
   out_7752390693684668621[5] = 0;
   out_7752390693684668621[6] = 0;
   out_7752390693684668621[7] = 0;
   out_7752390693684668621[8] = 0;
}
void h_28(double *state, double *unused, double *out_3437454446246848343) {
   out_3437454446246848343[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5611954362955352421) {
   out_5611954362955352421[0] = 1;
   out_5611954362955352421[1] = 0;
   out_5611954362955352421[2] = 0;
   out_5611954362955352421[3] = 0;
   out_5611954362955352421[4] = 0;
   out_5611954362955352421[5] = 0;
   out_5611954362955352421[6] = 0;
   out_5611954362955352421[7] = 0;
   out_5611954362955352421[8] = 0;
}
void h_31(double *state, double *unused, double *out_556316564325718304) {
   out_556316564325718304[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3298077656095834484) {
   out_3298077656095834484[0] = 0;
   out_3298077656095834484[1] = 0;
   out_3298077656095834484[2] = 0;
   out_3298077656095834484[3] = 0;
   out_3298077656095834484[4] = 0;
   out_3298077656095834484[5] = 0;
   out_3298077656095834484[6] = 0;
   out_3298077656095834484[7] = 0;
   out_3298077656095834484[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7026316075073471994) {
  err_fun(nom_x, delta_x, out_7026316075073471994);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4587773260780687079) {
  inv_err_fun(nom_x, true_x, out_4587773260780687079);
}
void car_H_mod_fun(double *state, double *out_255548955770617621) {
  H_mod_fun(state, out_255548955770617621);
}
void car_f_fun(double *state, double dt, double *out_5905678958362697737) {
  f_fun(state,  dt, out_5905678958362697737);
}
void car_F_fun(double *state, double dt, double *out_2348542156060617804) {
  F_fun(state,  dt, out_2348542156060617804);
}
void car_h_25(double *state, double *unused, double *out_5870924613014703511) {
  h_25(state, unused, out_5870924613014703511);
}
void car_H_25(double *state, double *unused, double *out_7665789077203242184) {
  H_25(state, unused, out_7665789077203242184);
}
void car_h_24(double *state, double *unused, double *out_7175962086981114995) {
  h_24(state, unused, out_7175962086981114995);
}
void car_H_24(double *state, double *unused, double *out_2919279750236733150) {
  H_24(state, unused, out_2919279750236733150);
}
void car_h_30(double *state, double *unused, double *out_619120766018658974) {
  h_30(state, unused, out_619120766018658974);
}
void car_H_30(double *state, double *unused, double *out_8262622037999060805) {
  H_30(state, unused, out_8262622037999060805);
}
void car_h_26(double *state, double *unused, double *out_2561596907152652789) {
  h_26(state, unused, out_2561596907152652789);
}
void car_H_26(double *state, double *unused, double *out_3924285758329185960) {
  H_26(state, unused, out_3924285758329185960);
}
void car_h_27(double *state, double *unused, double *out_6474240497691181028) {
  h_27(state, unused, out_6474240497691181028);
}
void car_H_27(double *state, double *unused, double *out_6039027966815117588) {
  H_27(state, unused, out_6039027966815117588);
}
void car_h_29(double *state, double *unused, double *out_5627330291441514494) {
  h_29(state, unused, out_5627330291441514494);
}
void car_H_29(double *state, double *unused, double *out_7752390693684668621) {
  H_29(state, unused, out_7752390693684668621);
}
void car_h_28(double *state, double *unused, double *out_3437454446246848343) {
  h_28(state, unused, out_3437454446246848343);
}
void car_H_28(double *state, double *unused, double *out_5611954362955352421) {
  H_28(state, unused, out_5611954362955352421);
}
void car_h_31(double *state, double *unused, double *out_556316564325718304) {
  h_31(state, unused, out_556316564325718304);
}
void car_H_31(double *state, double *unused, double *out_3298077656095834484) {
  H_31(state, unused, out_3298077656095834484);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
