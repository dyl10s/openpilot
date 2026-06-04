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
void err_fun(double *nom_x, double *delta_x, double *out_2765937094321424100) {
   out_2765937094321424100[0] = delta_x[0] + nom_x[0];
   out_2765937094321424100[1] = delta_x[1] + nom_x[1];
   out_2765937094321424100[2] = delta_x[2] + nom_x[2];
   out_2765937094321424100[3] = delta_x[3] + nom_x[3];
   out_2765937094321424100[4] = delta_x[4] + nom_x[4];
   out_2765937094321424100[5] = delta_x[5] + nom_x[5];
   out_2765937094321424100[6] = delta_x[6] + nom_x[6];
   out_2765937094321424100[7] = delta_x[7] + nom_x[7];
   out_2765937094321424100[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1382255689110899984) {
   out_1382255689110899984[0] = -nom_x[0] + true_x[0];
   out_1382255689110899984[1] = -nom_x[1] + true_x[1];
   out_1382255689110899984[2] = -nom_x[2] + true_x[2];
   out_1382255689110899984[3] = -nom_x[3] + true_x[3];
   out_1382255689110899984[4] = -nom_x[4] + true_x[4];
   out_1382255689110899984[5] = -nom_x[5] + true_x[5];
   out_1382255689110899984[6] = -nom_x[6] + true_x[6];
   out_1382255689110899984[7] = -nom_x[7] + true_x[7];
   out_1382255689110899984[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6175643942212596402) {
   out_6175643942212596402[0] = 1.0;
   out_6175643942212596402[1] = 0.0;
   out_6175643942212596402[2] = 0.0;
   out_6175643942212596402[3] = 0.0;
   out_6175643942212596402[4] = 0.0;
   out_6175643942212596402[5] = 0.0;
   out_6175643942212596402[6] = 0.0;
   out_6175643942212596402[7] = 0.0;
   out_6175643942212596402[8] = 0.0;
   out_6175643942212596402[9] = 0.0;
   out_6175643942212596402[10] = 1.0;
   out_6175643942212596402[11] = 0.0;
   out_6175643942212596402[12] = 0.0;
   out_6175643942212596402[13] = 0.0;
   out_6175643942212596402[14] = 0.0;
   out_6175643942212596402[15] = 0.0;
   out_6175643942212596402[16] = 0.0;
   out_6175643942212596402[17] = 0.0;
   out_6175643942212596402[18] = 0.0;
   out_6175643942212596402[19] = 0.0;
   out_6175643942212596402[20] = 1.0;
   out_6175643942212596402[21] = 0.0;
   out_6175643942212596402[22] = 0.0;
   out_6175643942212596402[23] = 0.0;
   out_6175643942212596402[24] = 0.0;
   out_6175643942212596402[25] = 0.0;
   out_6175643942212596402[26] = 0.0;
   out_6175643942212596402[27] = 0.0;
   out_6175643942212596402[28] = 0.0;
   out_6175643942212596402[29] = 0.0;
   out_6175643942212596402[30] = 1.0;
   out_6175643942212596402[31] = 0.0;
   out_6175643942212596402[32] = 0.0;
   out_6175643942212596402[33] = 0.0;
   out_6175643942212596402[34] = 0.0;
   out_6175643942212596402[35] = 0.0;
   out_6175643942212596402[36] = 0.0;
   out_6175643942212596402[37] = 0.0;
   out_6175643942212596402[38] = 0.0;
   out_6175643942212596402[39] = 0.0;
   out_6175643942212596402[40] = 1.0;
   out_6175643942212596402[41] = 0.0;
   out_6175643942212596402[42] = 0.0;
   out_6175643942212596402[43] = 0.0;
   out_6175643942212596402[44] = 0.0;
   out_6175643942212596402[45] = 0.0;
   out_6175643942212596402[46] = 0.0;
   out_6175643942212596402[47] = 0.0;
   out_6175643942212596402[48] = 0.0;
   out_6175643942212596402[49] = 0.0;
   out_6175643942212596402[50] = 1.0;
   out_6175643942212596402[51] = 0.0;
   out_6175643942212596402[52] = 0.0;
   out_6175643942212596402[53] = 0.0;
   out_6175643942212596402[54] = 0.0;
   out_6175643942212596402[55] = 0.0;
   out_6175643942212596402[56] = 0.0;
   out_6175643942212596402[57] = 0.0;
   out_6175643942212596402[58] = 0.0;
   out_6175643942212596402[59] = 0.0;
   out_6175643942212596402[60] = 1.0;
   out_6175643942212596402[61] = 0.0;
   out_6175643942212596402[62] = 0.0;
   out_6175643942212596402[63] = 0.0;
   out_6175643942212596402[64] = 0.0;
   out_6175643942212596402[65] = 0.0;
   out_6175643942212596402[66] = 0.0;
   out_6175643942212596402[67] = 0.0;
   out_6175643942212596402[68] = 0.0;
   out_6175643942212596402[69] = 0.0;
   out_6175643942212596402[70] = 1.0;
   out_6175643942212596402[71] = 0.0;
   out_6175643942212596402[72] = 0.0;
   out_6175643942212596402[73] = 0.0;
   out_6175643942212596402[74] = 0.0;
   out_6175643942212596402[75] = 0.0;
   out_6175643942212596402[76] = 0.0;
   out_6175643942212596402[77] = 0.0;
   out_6175643942212596402[78] = 0.0;
   out_6175643942212596402[79] = 0.0;
   out_6175643942212596402[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2437881867604815540) {
   out_2437881867604815540[0] = state[0];
   out_2437881867604815540[1] = state[1];
   out_2437881867604815540[2] = state[2];
   out_2437881867604815540[3] = state[3];
   out_2437881867604815540[4] = state[4];
   out_2437881867604815540[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2437881867604815540[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2437881867604815540[7] = state[7];
   out_2437881867604815540[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3645925778664752399) {
   out_3645925778664752399[0] = 1;
   out_3645925778664752399[1] = 0;
   out_3645925778664752399[2] = 0;
   out_3645925778664752399[3] = 0;
   out_3645925778664752399[4] = 0;
   out_3645925778664752399[5] = 0;
   out_3645925778664752399[6] = 0;
   out_3645925778664752399[7] = 0;
   out_3645925778664752399[8] = 0;
   out_3645925778664752399[9] = 0;
   out_3645925778664752399[10] = 1;
   out_3645925778664752399[11] = 0;
   out_3645925778664752399[12] = 0;
   out_3645925778664752399[13] = 0;
   out_3645925778664752399[14] = 0;
   out_3645925778664752399[15] = 0;
   out_3645925778664752399[16] = 0;
   out_3645925778664752399[17] = 0;
   out_3645925778664752399[18] = 0;
   out_3645925778664752399[19] = 0;
   out_3645925778664752399[20] = 1;
   out_3645925778664752399[21] = 0;
   out_3645925778664752399[22] = 0;
   out_3645925778664752399[23] = 0;
   out_3645925778664752399[24] = 0;
   out_3645925778664752399[25] = 0;
   out_3645925778664752399[26] = 0;
   out_3645925778664752399[27] = 0;
   out_3645925778664752399[28] = 0;
   out_3645925778664752399[29] = 0;
   out_3645925778664752399[30] = 1;
   out_3645925778664752399[31] = 0;
   out_3645925778664752399[32] = 0;
   out_3645925778664752399[33] = 0;
   out_3645925778664752399[34] = 0;
   out_3645925778664752399[35] = 0;
   out_3645925778664752399[36] = 0;
   out_3645925778664752399[37] = 0;
   out_3645925778664752399[38] = 0;
   out_3645925778664752399[39] = 0;
   out_3645925778664752399[40] = 1;
   out_3645925778664752399[41] = 0;
   out_3645925778664752399[42] = 0;
   out_3645925778664752399[43] = 0;
   out_3645925778664752399[44] = 0;
   out_3645925778664752399[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3645925778664752399[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3645925778664752399[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3645925778664752399[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3645925778664752399[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3645925778664752399[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3645925778664752399[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3645925778664752399[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3645925778664752399[53] = -9.8100000000000005*dt;
   out_3645925778664752399[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3645925778664752399[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3645925778664752399[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3645925778664752399[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3645925778664752399[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3645925778664752399[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3645925778664752399[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3645925778664752399[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3645925778664752399[62] = 0;
   out_3645925778664752399[63] = 0;
   out_3645925778664752399[64] = 0;
   out_3645925778664752399[65] = 0;
   out_3645925778664752399[66] = 0;
   out_3645925778664752399[67] = 0;
   out_3645925778664752399[68] = 0;
   out_3645925778664752399[69] = 0;
   out_3645925778664752399[70] = 1;
   out_3645925778664752399[71] = 0;
   out_3645925778664752399[72] = 0;
   out_3645925778664752399[73] = 0;
   out_3645925778664752399[74] = 0;
   out_3645925778664752399[75] = 0;
   out_3645925778664752399[76] = 0;
   out_3645925778664752399[77] = 0;
   out_3645925778664752399[78] = 0;
   out_3645925778664752399[79] = 0;
   out_3645925778664752399[80] = 1;
}
void h_25(double *state, double *unused, double *out_1347552076965832871) {
   out_1347552076965832871[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6035190491488835800) {
   out_6035190491488835800[0] = 0;
   out_6035190491488835800[1] = 0;
   out_6035190491488835800[2] = 0;
   out_6035190491488835800[3] = 0;
   out_6035190491488835800[4] = 0;
   out_6035190491488835800[5] = 0;
   out_6035190491488835800[6] = 1;
   out_6035190491488835800[7] = 0;
   out_6035190491488835800[8] = 0;
}
void h_24(double *state, double *unused, double *out_7176999251413506765) {
   out_7176999251413506765[0] = state[4];
   out_7176999251413506765[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6210520902369554390) {
   out_6210520902369554390[0] = 0;
   out_6210520902369554390[1] = 0;
   out_6210520902369554390[2] = 0;
   out_6210520902369554390[3] = 0;
   out_6210520902369554390[4] = 1;
   out_6210520902369554390[5] = 0;
   out_6210520902369554390[6] = 0;
   out_6210520902369554390[7] = 0;
   out_6210520902369554390[8] = 0;
   out_6210520902369554390[9] = 0;
   out_6210520902369554390[10] = 0;
   out_6210520902369554390[11] = 0;
   out_6210520902369554390[12] = 0;
   out_6210520902369554390[13] = 0;
   out_6210520902369554390[14] = 1;
   out_6210520902369554390[15] = 0;
   out_6210520902369554390[16] = 0;
   out_6210520902369554390[17] = 0;
}
void h_30(double *state, double *unused, double *out_2798183469594716038) {
   out_2798183469594716038[0] = state[4];
}
void H_30(double *state, double *unused, double *out_881499850002780955) {
   out_881499850002780955[0] = 0;
   out_881499850002780955[1] = 0;
   out_881499850002780955[2] = 0;
   out_881499850002780955[3] = 0;
   out_881499850002780955[4] = 1;
   out_881499850002780955[5] = 0;
   out_881499850002780955[6] = 0;
   out_881499850002780955[7] = 0;
   out_881499850002780955[8] = 0;
}
void h_26(double *state, double *unused, double *out_7428563492211452550) {
   out_7428563492211452550[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8670050263346659592) {
   out_8670050263346659592[0] = 0;
   out_8670050263346659592[1] = 0;
   out_8670050263346659592[2] = 0;
   out_8670050263346659592[3] = 0;
   out_8670050263346659592[4] = 0;
   out_8670050263346659592[5] = 0;
   out_8670050263346659592[6] = 0;
   out_8670050263346659592[7] = 1;
   out_8670050263346659592[8] = 0;
}
void h_27(double *state, double *unused, double *out_3654121190695012774) {
   out_3654121190695012774[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8339292750432500781) {
   out_8339292750432500781[0] = 0;
   out_8339292750432500781[1] = 0;
   out_8339292750432500781[2] = 0;
   out_8339292750432500781[3] = 1;
   out_8339292750432500781[4] = 0;
   out_8339292750432500781[5] = 0;
   out_8339292750432500781[6] = 0;
   out_8339292750432500781[7] = 0;
   out_8339292750432500781[8] = 0;
}
void h_29(double *state, double *unused, double *out_2203489798066129607) {
   out_2203489798066129607[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5654298094317683686) {
   out_5654298094317683686[0] = 0;
   out_5654298094317683686[1] = 1;
   out_5654298094317683686[2] = 0;
   out_5654298094317683686[3] = 0;
   out_5654298094317683686[4] = 0;
   out_5654298094317683686[5] = 0;
   out_5654298094317683686[6] = 0;
   out_5654298094317683686[7] = 0;
   out_5654298094317683686[8] = 0;
}
void h_28(double *state, double *unused, double *out_3781022243733688039) {
   out_3781022243733688039[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3690667822752357435) {
   out_3690667822752357435[0] = 1;
   out_3690667822752357435[1] = 0;
   out_3690667822752357435[2] = 0;
   out_3690667822752357435[3] = 0;
   out_3690667822752357435[4] = 0;
   out_3690667822752357435[5] = 0;
   out_3690667822752357435[6] = 0;
   out_3690667822752357435[7] = 0;
   out_3690667822752357435[8] = 0;
}
void h_31(double *state, double *unused, double *out_5423283149384518065) {
   out_5423283149384518065[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6004544529611875372) {
   out_6004544529611875372[0] = 0;
   out_6004544529611875372[1] = 0;
   out_6004544529611875372[2] = 0;
   out_6004544529611875372[3] = 0;
   out_6004544529611875372[4] = 0;
   out_6004544529611875372[5] = 0;
   out_6004544529611875372[6] = 0;
   out_6004544529611875372[7] = 0;
   out_6004544529611875372[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_2765937094321424100) {
  err_fun(nom_x, delta_x, out_2765937094321424100);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1382255689110899984) {
  inv_err_fun(nom_x, true_x, out_1382255689110899984);
}
void car_H_mod_fun(double *state, double *out_6175643942212596402) {
  H_mod_fun(state, out_6175643942212596402);
}
void car_f_fun(double *state, double dt, double *out_2437881867604815540) {
  f_fun(state,  dt, out_2437881867604815540);
}
void car_F_fun(double *state, double dt, double *out_3645925778664752399) {
  F_fun(state,  dt, out_3645925778664752399);
}
void car_h_25(double *state, double *unused, double *out_1347552076965832871) {
  h_25(state, unused, out_1347552076965832871);
}
void car_H_25(double *state, double *unused, double *out_6035190491488835800) {
  H_25(state, unused, out_6035190491488835800);
}
void car_h_24(double *state, double *unused, double *out_7176999251413506765) {
  h_24(state, unused, out_7176999251413506765);
}
void car_H_24(double *state, double *unused, double *out_6210520902369554390) {
  H_24(state, unused, out_6210520902369554390);
}
void car_h_30(double *state, double *unused, double *out_2798183469594716038) {
  h_30(state, unused, out_2798183469594716038);
}
void car_H_30(double *state, double *unused, double *out_881499850002780955) {
  H_30(state, unused, out_881499850002780955);
}
void car_h_26(double *state, double *unused, double *out_7428563492211452550) {
  h_26(state, unused, out_7428563492211452550);
}
void car_H_26(double *state, double *unused, double *out_8670050263346659592) {
  H_26(state, unused, out_8670050263346659592);
}
void car_h_27(double *state, double *unused, double *out_3654121190695012774) {
  h_27(state, unused, out_3654121190695012774);
}
void car_H_27(double *state, double *unused, double *out_8339292750432500781) {
  H_27(state, unused, out_8339292750432500781);
}
void car_h_29(double *state, double *unused, double *out_2203489798066129607) {
  h_29(state, unused, out_2203489798066129607);
}
void car_H_29(double *state, double *unused, double *out_5654298094317683686) {
  H_29(state, unused, out_5654298094317683686);
}
void car_h_28(double *state, double *unused, double *out_3781022243733688039) {
  h_28(state, unused, out_3781022243733688039);
}
void car_H_28(double *state, double *unused, double *out_3690667822752357435) {
  H_28(state, unused, out_3690667822752357435);
}
void car_h_31(double *state, double *unused, double *out_5423283149384518065) {
  h_31(state, unused, out_5423283149384518065);
}
void car_H_31(double *state, double *unused, double *out_6004544529611875372) {
  H_31(state, unused, out_6004544529611875372);
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
