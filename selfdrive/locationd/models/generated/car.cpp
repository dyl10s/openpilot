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
void err_fun(double *nom_x, double *delta_x, double *out_6892109097522362188) {
   out_6892109097522362188[0] = delta_x[0] + nom_x[0];
   out_6892109097522362188[1] = delta_x[1] + nom_x[1];
   out_6892109097522362188[2] = delta_x[2] + nom_x[2];
   out_6892109097522362188[3] = delta_x[3] + nom_x[3];
   out_6892109097522362188[4] = delta_x[4] + nom_x[4];
   out_6892109097522362188[5] = delta_x[5] + nom_x[5];
   out_6892109097522362188[6] = delta_x[6] + nom_x[6];
   out_6892109097522362188[7] = delta_x[7] + nom_x[7];
   out_6892109097522362188[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5432001000781993507) {
   out_5432001000781993507[0] = -nom_x[0] + true_x[0];
   out_5432001000781993507[1] = -nom_x[1] + true_x[1];
   out_5432001000781993507[2] = -nom_x[2] + true_x[2];
   out_5432001000781993507[3] = -nom_x[3] + true_x[3];
   out_5432001000781993507[4] = -nom_x[4] + true_x[4];
   out_5432001000781993507[5] = -nom_x[5] + true_x[5];
   out_5432001000781993507[6] = -nom_x[6] + true_x[6];
   out_5432001000781993507[7] = -nom_x[7] + true_x[7];
   out_5432001000781993507[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1134362066478752987) {
   out_1134362066478752987[0] = 1.0;
   out_1134362066478752987[1] = 0.0;
   out_1134362066478752987[2] = 0.0;
   out_1134362066478752987[3] = 0.0;
   out_1134362066478752987[4] = 0.0;
   out_1134362066478752987[5] = 0.0;
   out_1134362066478752987[6] = 0.0;
   out_1134362066478752987[7] = 0.0;
   out_1134362066478752987[8] = 0.0;
   out_1134362066478752987[9] = 0.0;
   out_1134362066478752987[10] = 1.0;
   out_1134362066478752987[11] = 0.0;
   out_1134362066478752987[12] = 0.0;
   out_1134362066478752987[13] = 0.0;
   out_1134362066478752987[14] = 0.0;
   out_1134362066478752987[15] = 0.0;
   out_1134362066478752987[16] = 0.0;
   out_1134362066478752987[17] = 0.0;
   out_1134362066478752987[18] = 0.0;
   out_1134362066478752987[19] = 0.0;
   out_1134362066478752987[20] = 1.0;
   out_1134362066478752987[21] = 0.0;
   out_1134362066478752987[22] = 0.0;
   out_1134362066478752987[23] = 0.0;
   out_1134362066478752987[24] = 0.0;
   out_1134362066478752987[25] = 0.0;
   out_1134362066478752987[26] = 0.0;
   out_1134362066478752987[27] = 0.0;
   out_1134362066478752987[28] = 0.0;
   out_1134362066478752987[29] = 0.0;
   out_1134362066478752987[30] = 1.0;
   out_1134362066478752987[31] = 0.0;
   out_1134362066478752987[32] = 0.0;
   out_1134362066478752987[33] = 0.0;
   out_1134362066478752987[34] = 0.0;
   out_1134362066478752987[35] = 0.0;
   out_1134362066478752987[36] = 0.0;
   out_1134362066478752987[37] = 0.0;
   out_1134362066478752987[38] = 0.0;
   out_1134362066478752987[39] = 0.0;
   out_1134362066478752987[40] = 1.0;
   out_1134362066478752987[41] = 0.0;
   out_1134362066478752987[42] = 0.0;
   out_1134362066478752987[43] = 0.0;
   out_1134362066478752987[44] = 0.0;
   out_1134362066478752987[45] = 0.0;
   out_1134362066478752987[46] = 0.0;
   out_1134362066478752987[47] = 0.0;
   out_1134362066478752987[48] = 0.0;
   out_1134362066478752987[49] = 0.0;
   out_1134362066478752987[50] = 1.0;
   out_1134362066478752987[51] = 0.0;
   out_1134362066478752987[52] = 0.0;
   out_1134362066478752987[53] = 0.0;
   out_1134362066478752987[54] = 0.0;
   out_1134362066478752987[55] = 0.0;
   out_1134362066478752987[56] = 0.0;
   out_1134362066478752987[57] = 0.0;
   out_1134362066478752987[58] = 0.0;
   out_1134362066478752987[59] = 0.0;
   out_1134362066478752987[60] = 1.0;
   out_1134362066478752987[61] = 0.0;
   out_1134362066478752987[62] = 0.0;
   out_1134362066478752987[63] = 0.0;
   out_1134362066478752987[64] = 0.0;
   out_1134362066478752987[65] = 0.0;
   out_1134362066478752987[66] = 0.0;
   out_1134362066478752987[67] = 0.0;
   out_1134362066478752987[68] = 0.0;
   out_1134362066478752987[69] = 0.0;
   out_1134362066478752987[70] = 1.0;
   out_1134362066478752987[71] = 0.0;
   out_1134362066478752987[72] = 0.0;
   out_1134362066478752987[73] = 0.0;
   out_1134362066478752987[74] = 0.0;
   out_1134362066478752987[75] = 0.0;
   out_1134362066478752987[76] = 0.0;
   out_1134362066478752987[77] = 0.0;
   out_1134362066478752987[78] = 0.0;
   out_1134362066478752987[79] = 0.0;
   out_1134362066478752987[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_9123630075498474389) {
   out_9123630075498474389[0] = state[0];
   out_9123630075498474389[1] = state[1];
   out_9123630075498474389[2] = state[2];
   out_9123630075498474389[3] = state[3];
   out_9123630075498474389[4] = state[4];
   out_9123630075498474389[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_9123630075498474389[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_9123630075498474389[7] = state[7];
   out_9123630075498474389[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5012636381780854897) {
   out_5012636381780854897[0] = 1;
   out_5012636381780854897[1] = 0;
   out_5012636381780854897[2] = 0;
   out_5012636381780854897[3] = 0;
   out_5012636381780854897[4] = 0;
   out_5012636381780854897[5] = 0;
   out_5012636381780854897[6] = 0;
   out_5012636381780854897[7] = 0;
   out_5012636381780854897[8] = 0;
   out_5012636381780854897[9] = 0;
   out_5012636381780854897[10] = 1;
   out_5012636381780854897[11] = 0;
   out_5012636381780854897[12] = 0;
   out_5012636381780854897[13] = 0;
   out_5012636381780854897[14] = 0;
   out_5012636381780854897[15] = 0;
   out_5012636381780854897[16] = 0;
   out_5012636381780854897[17] = 0;
   out_5012636381780854897[18] = 0;
   out_5012636381780854897[19] = 0;
   out_5012636381780854897[20] = 1;
   out_5012636381780854897[21] = 0;
   out_5012636381780854897[22] = 0;
   out_5012636381780854897[23] = 0;
   out_5012636381780854897[24] = 0;
   out_5012636381780854897[25] = 0;
   out_5012636381780854897[26] = 0;
   out_5012636381780854897[27] = 0;
   out_5012636381780854897[28] = 0;
   out_5012636381780854897[29] = 0;
   out_5012636381780854897[30] = 1;
   out_5012636381780854897[31] = 0;
   out_5012636381780854897[32] = 0;
   out_5012636381780854897[33] = 0;
   out_5012636381780854897[34] = 0;
   out_5012636381780854897[35] = 0;
   out_5012636381780854897[36] = 0;
   out_5012636381780854897[37] = 0;
   out_5012636381780854897[38] = 0;
   out_5012636381780854897[39] = 0;
   out_5012636381780854897[40] = 1;
   out_5012636381780854897[41] = 0;
   out_5012636381780854897[42] = 0;
   out_5012636381780854897[43] = 0;
   out_5012636381780854897[44] = 0;
   out_5012636381780854897[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5012636381780854897[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5012636381780854897[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5012636381780854897[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5012636381780854897[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5012636381780854897[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5012636381780854897[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5012636381780854897[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5012636381780854897[53] = -9.8100000000000005*dt;
   out_5012636381780854897[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5012636381780854897[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5012636381780854897[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5012636381780854897[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5012636381780854897[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5012636381780854897[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5012636381780854897[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5012636381780854897[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5012636381780854897[62] = 0;
   out_5012636381780854897[63] = 0;
   out_5012636381780854897[64] = 0;
   out_5012636381780854897[65] = 0;
   out_5012636381780854897[66] = 0;
   out_5012636381780854897[67] = 0;
   out_5012636381780854897[68] = 0;
   out_5012636381780854897[69] = 0;
   out_5012636381780854897[70] = 1;
   out_5012636381780854897[71] = 0;
   out_5012636381780854897[72] = 0;
   out_5012636381780854897[73] = 0;
   out_5012636381780854897[74] = 0;
   out_5012636381780854897[75] = 0;
   out_5012636381780854897[76] = 0;
   out_5012636381780854897[77] = 0;
   out_5012636381780854897[78] = 0;
   out_5012636381780854897[79] = 0;
   out_5012636381780854897[80] = 1;
}
void h_25(double *state, double *unused, double *out_5169748066208681951) {
   out_5169748066208681951[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6786975966495106818) {
   out_6786975966495106818[0] = 0;
   out_6786975966495106818[1] = 0;
   out_6786975966495106818[2] = 0;
   out_6786975966495106818[3] = 0;
   out_6786975966495106818[4] = 0;
   out_6786975966495106818[5] = 0;
   out_6786975966495106818[6] = 1;
   out_6786975966495106818[7] = 0;
   out_6786975966495106818[8] = 0;
}
void h_24(double *state, double *unused, double *out_6620362679693609370) {
   out_6620362679693609370[0] = state[4];
   out_6620362679693609370[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8101842508412121662) {
   out_8101842508412121662[0] = 0;
   out_8101842508412121662[1] = 0;
   out_8101842508412121662[2] = 0;
   out_8101842508412121662[3] = 0;
   out_8101842508412121662[4] = 1;
   out_8101842508412121662[5] = 0;
   out_8101842508412121662[6] = 0;
   out_8101842508412121662[7] = 0;
   out_8101842508412121662[8] = 0;
   out_8101842508412121662[9] = 0;
   out_8101842508412121662[10] = 0;
   out_8101842508412121662[11] = 0;
   out_8101842508412121662[12] = 0;
   out_8101842508412121662[13] = 0;
   out_8101842508412121662[14] = 1;
   out_8101842508412121662[15] = 0;
   out_8101842508412121662[16] = 0;
   out_8101842508412121662[17] = 0;
}
void h_30(double *state, double *unused, double *out_5326934734559811096) {
   out_5326934734559811096[0] = state[4];
}
void H_30(double *state, double *unused, double *out_9141435148707196171) {
   out_9141435148707196171[0] = 0;
   out_9141435148707196171[1] = 0;
   out_9141435148707196171[2] = 0;
   out_9141435148707196171[3] = 0;
   out_9141435148707196171[4] = 1;
   out_9141435148707196171[5] = 0;
   out_9141435148707196171[6] = 0;
   out_9141435148707196171[7] = 0;
   out_9141435148707196171[8] = 0;
}
void h_26(double *state, double *unused, double *out_5930250619236288613) {
   out_5930250619236288613[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3045472647621050594) {
   out_3045472647621050594[0] = 0;
   out_3045472647621050594[1] = 0;
   out_3045472647621050594[2] = 0;
   out_3045472647621050594[3] = 0;
   out_3045472647621050594[4] = 0;
   out_3045472647621050594[5] = 0;
   out_3045472647621050594[6] = 0;
   out_3045472647621050594[7] = 1;
   out_3045472647621050594[8] = 0;
}
void h_27(double *state, double *unused, double *out_7982300169478535334) {
   out_7982300169478535334[0] = state[3];
}
void H_27(double *state, double *unused, double *out_84516324567073709) {
   out_84516324567073709[0] = 0;
   out_84516324567073709[1] = 0;
   out_84516324567073709[2] = 0;
   out_84516324567073709[3] = 1;
   out_84516324567073709[4] = 0;
   out_84516324567073709[5] = 0;
   out_84516324567073709[6] = 0;
   out_84516324567073709[7] = 0;
   out_84516324567073709[8] = 0;
}
void h_29(double *state, double *unused, double *out_3693608677880665346) {
   out_3693608677880665346[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2769510980681890804) {
   out_2769510980681890804[0] = 0;
   out_2769510980681890804[1] = 1;
   out_2769510980681890804[2] = 0;
   out_2769510980681890804[3] = 0;
   out_2769510980681890804[4] = 0;
   out_2769510980681890804[5] = 0;
   out_2769510980681890804[6] = 0;
   out_2769510980681890804[7] = 0;
   out_2769510980681890804[8] = 0;
}
void h_28(double *state, double *unused, double *out_9150043970554677071) {
   out_9150043970554677071[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4733141252247217055) {
   out_4733141252247217055[0] = 1;
   out_4733141252247217055[1] = 0;
   out_4733141252247217055[2] = 0;
   out_4733141252247217055[3] = 0;
   out_4733141252247217055[4] = 0;
   out_4733141252247217055[5] = 0;
   out_4733141252247217055[6] = 0;
   out_4733141252247217055[7] = 0;
   out_4733141252247217055[8] = 0;
}
void h_31(double *state, double *unused, double *out_1601087160141668985) {
   out_1601087160141668985[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2419264545387699118) {
   out_2419264545387699118[0] = 0;
   out_2419264545387699118[1] = 0;
   out_2419264545387699118[2] = 0;
   out_2419264545387699118[3] = 0;
   out_2419264545387699118[4] = 0;
   out_2419264545387699118[5] = 0;
   out_2419264545387699118[6] = 0;
   out_2419264545387699118[7] = 0;
   out_2419264545387699118[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6892109097522362188) {
  err_fun(nom_x, delta_x, out_6892109097522362188);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5432001000781993507) {
  inv_err_fun(nom_x, true_x, out_5432001000781993507);
}
void car_H_mod_fun(double *state, double *out_1134362066478752987) {
  H_mod_fun(state, out_1134362066478752987);
}
void car_f_fun(double *state, double dt, double *out_9123630075498474389) {
  f_fun(state,  dt, out_9123630075498474389);
}
void car_F_fun(double *state, double dt, double *out_5012636381780854897) {
  F_fun(state,  dt, out_5012636381780854897);
}
void car_h_25(double *state, double *unused, double *out_5169748066208681951) {
  h_25(state, unused, out_5169748066208681951);
}
void car_H_25(double *state, double *unused, double *out_6786975966495106818) {
  H_25(state, unused, out_6786975966495106818);
}
void car_h_24(double *state, double *unused, double *out_6620362679693609370) {
  h_24(state, unused, out_6620362679693609370);
}
void car_H_24(double *state, double *unused, double *out_8101842508412121662) {
  H_24(state, unused, out_8101842508412121662);
}
void car_h_30(double *state, double *unused, double *out_5326934734559811096) {
  h_30(state, unused, out_5326934734559811096);
}
void car_H_30(double *state, double *unused, double *out_9141435148707196171) {
  H_30(state, unused, out_9141435148707196171);
}
void car_h_26(double *state, double *unused, double *out_5930250619236288613) {
  h_26(state, unused, out_5930250619236288613);
}
void car_H_26(double *state, double *unused, double *out_3045472647621050594) {
  H_26(state, unused, out_3045472647621050594);
}
void car_h_27(double *state, double *unused, double *out_7982300169478535334) {
  h_27(state, unused, out_7982300169478535334);
}
void car_H_27(double *state, double *unused, double *out_84516324567073709) {
  H_27(state, unused, out_84516324567073709);
}
void car_h_29(double *state, double *unused, double *out_3693608677880665346) {
  h_29(state, unused, out_3693608677880665346);
}
void car_H_29(double *state, double *unused, double *out_2769510980681890804) {
  H_29(state, unused, out_2769510980681890804);
}
void car_h_28(double *state, double *unused, double *out_9150043970554677071) {
  h_28(state, unused, out_9150043970554677071);
}
void car_H_28(double *state, double *unused, double *out_4733141252247217055) {
  H_28(state, unused, out_4733141252247217055);
}
void car_h_31(double *state, double *unused, double *out_1601087160141668985) {
  h_31(state, unused, out_1601087160141668985);
}
void car_H_31(double *state, double *unused, double *out_2419264545387699118) {
  H_31(state, unused, out_2419264545387699118);
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
