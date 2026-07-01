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
void err_fun(double *nom_x, double *delta_x, double *out_5572165619661696722) {
   out_5572165619661696722[0] = delta_x[0] + nom_x[0];
   out_5572165619661696722[1] = delta_x[1] + nom_x[1];
   out_5572165619661696722[2] = delta_x[2] + nom_x[2];
   out_5572165619661696722[3] = delta_x[3] + nom_x[3];
   out_5572165619661696722[4] = delta_x[4] + nom_x[4];
   out_5572165619661696722[5] = delta_x[5] + nom_x[5];
   out_5572165619661696722[6] = delta_x[6] + nom_x[6];
   out_5572165619661696722[7] = delta_x[7] + nom_x[7];
   out_5572165619661696722[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1924778118840772208) {
   out_1924778118840772208[0] = -nom_x[0] + true_x[0];
   out_1924778118840772208[1] = -nom_x[1] + true_x[1];
   out_1924778118840772208[2] = -nom_x[2] + true_x[2];
   out_1924778118840772208[3] = -nom_x[3] + true_x[3];
   out_1924778118840772208[4] = -nom_x[4] + true_x[4];
   out_1924778118840772208[5] = -nom_x[5] + true_x[5];
   out_1924778118840772208[6] = -nom_x[6] + true_x[6];
   out_1924778118840772208[7] = -nom_x[7] + true_x[7];
   out_1924778118840772208[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5209558866032184805) {
   out_5209558866032184805[0] = 1.0;
   out_5209558866032184805[1] = 0.0;
   out_5209558866032184805[2] = 0.0;
   out_5209558866032184805[3] = 0.0;
   out_5209558866032184805[4] = 0.0;
   out_5209558866032184805[5] = 0.0;
   out_5209558866032184805[6] = 0.0;
   out_5209558866032184805[7] = 0.0;
   out_5209558866032184805[8] = 0.0;
   out_5209558866032184805[9] = 0.0;
   out_5209558866032184805[10] = 1.0;
   out_5209558866032184805[11] = 0.0;
   out_5209558866032184805[12] = 0.0;
   out_5209558866032184805[13] = 0.0;
   out_5209558866032184805[14] = 0.0;
   out_5209558866032184805[15] = 0.0;
   out_5209558866032184805[16] = 0.0;
   out_5209558866032184805[17] = 0.0;
   out_5209558866032184805[18] = 0.0;
   out_5209558866032184805[19] = 0.0;
   out_5209558866032184805[20] = 1.0;
   out_5209558866032184805[21] = 0.0;
   out_5209558866032184805[22] = 0.0;
   out_5209558866032184805[23] = 0.0;
   out_5209558866032184805[24] = 0.0;
   out_5209558866032184805[25] = 0.0;
   out_5209558866032184805[26] = 0.0;
   out_5209558866032184805[27] = 0.0;
   out_5209558866032184805[28] = 0.0;
   out_5209558866032184805[29] = 0.0;
   out_5209558866032184805[30] = 1.0;
   out_5209558866032184805[31] = 0.0;
   out_5209558866032184805[32] = 0.0;
   out_5209558866032184805[33] = 0.0;
   out_5209558866032184805[34] = 0.0;
   out_5209558866032184805[35] = 0.0;
   out_5209558866032184805[36] = 0.0;
   out_5209558866032184805[37] = 0.0;
   out_5209558866032184805[38] = 0.0;
   out_5209558866032184805[39] = 0.0;
   out_5209558866032184805[40] = 1.0;
   out_5209558866032184805[41] = 0.0;
   out_5209558866032184805[42] = 0.0;
   out_5209558866032184805[43] = 0.0;
   out_5209558866032184805[44] = 0.0;
   out_5209558866032184805[45] = 0.0;
   out_5209558866032184805[46] = 0.0;
   out_5209558866032184805[47] = 0.0;
   out_5209558866032184805[48] = 0.0;
   out_5209558866032184805[49] = 0.0;
   out_5209558866032184805[50] = 1.0;
   out_5209558866032184805[51] = 0.0;
   out_5209558866032184805[52] = 0.0;
   out_5209558866032184805[53] = 0.0;
   out_5209558866032184805[54] = 0.0;
   out_5209558866032184805[55] = 0.0;
   out_5209558866032184805[56] = 0.0;
   out_5209558866032184805[57] = 0.0;
   out_5209558866032184805[58] = 0.0;
   out_5209558866032184805[59] = 0.0;
   out_5209558866032184805[60] = 1.0;
   out_5209558866032184805[61] = 0.0;
   out_5209558866032184805[62] = 0.0;
   out_5209558866032184805[63] = 0.0;
   out_5209558866032184805[64] = 0.0;
   out_5209558866032184805[65] = 0.0;
   out_5209558866032184805[66] = 0.0;
   out_5209558866032184805[67] = 0.0;
   out_5209558866032184805[68] = 0.0;
   out_5209558866032184805[69] = 0.0;
   out_5209558866032184805[70] = 1.0;
   out_5209558866032184805[71] = 0.0;
   out_5209558866032184805[72] = 0.0;
   out_5209558866032184805[73] = 0.0;
   out_5209558866032184805[74] = 0.0;
   out_5209558866032184805[75] = 0.0;
   out_5209558866032184805[76] = 0.0;
   out_5209558866032184805[77] = 0.0;
   out_5209558866032184805[78] = 0.0;
   out_5209558866032184805[79] = 0.0;
   out_5209558866032184805[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8731244167447695934) {
   out_8731244167447695934[0] = state[0];
   out_8731244167447695934[1] = state[1];
   out_8731244167447695934[2] = state[2];
   out_8731244167447695934[3] = state[3];
   out_8731244167447695934[4] = state[4];
   out_8731244167447695934[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8731244167447695934[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8731244167447695934[7] = state[7];
   out_8731244167447695934[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5438267541501267753) {
   out_5438267541501267753[0] = 1;
   out_5438267541501267753[1] = 0;
   out_5438267541501267753[2] = 0;
   out_5438267541501267753[3] = 0;
   out_5438267541501267753[4] = 0;
   out_5438267541501267753[5] = 0;
   out_5438267541501267753[6] = 0;
   out_5438267541501267753[7] = 0;
   out_5438267541501267753[8] = 0;
   out_5438267541501267753[9] = 0;
   out_5438267541501267753[10] = 1;
   out_5438267541501267753[11] = 0;
   out_5438267541501267753[12] = 0;
   out_5438267541501267753[13] = 0;
   out_5438267541501267753[14] = 0;
   out_5438267541501267753[15] = 0;
   out_5438267541501267753[16] = 0;
   out_5438267541501267753[17] = 0;
   out_5438267541501267753[18] = 0;
   out_5438267541501267753[19] = 0;
   out_5438267541501267753[20] = 1;
   out_5438267541501267753[21] = 0;
   out_5438267541501267753[22] = 0;
   out_5438267541501267753[23] = 0;
   out_5438267541501267753[24] = 0;
   out_5438267541501267753[25] = 0;
   out_5438267541501267753[26] = 0;
   out_5438267541501267753[27] = 0;
   out_5438267541501267753[28] = 0;
   out_5438267541501267753[29] = 0;
   out_5438267541501267753[30] = 1;
   out_5438267541501267753[31] = 0;
   out_5438267541501267753[32] = 0;
   out_5438267541501267753[33] = 0;
   out_5438267541501267753[34] = 0;
   out_5438267541501267753[35] = 0;
   out_5438267541501267753[36] = 0;
   out_5438267541501267753[37] = 0;
   out_5438267541501267753[38] = 0;
   out_5438267541501267753[39] = 0;
   out_5438267541501267753[40] = 1;
   out_5438267541501267753[41] = 0;
   out_5438267541501267753[42] = 0;
   out_5438267541501267753[43] = 0;
   out_5438267541501267753[44] = 0;
   out_5438267541501267753[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5438267541501267753[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5438267541501267753[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5438267541501267753[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5438267541501267753[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5438267541501267753[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5438267541501267753[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5438267541501267753[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5438267541501267753[53] = -9.8100000000000005*dt;
   out_5438267541501267753[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5438267541501267753[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5438267541501267753[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5438267541501267753[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5438267541501267753[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5438267541501267753[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5438267541501267753[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5438267541501267753[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5438267541501267753[62] = 0;
   out_5438267541501267753[63] = 0;
   out_5438267541501267753[64] = 0;
   out_5438267541501267753[65] = 0;
   out_5438267541501267753[66] = 0;
   out_5438267541501267753[67] = 0;
   out_5438267541501267753[68] = 0;
   out_5438267541501267753[69] = 0;
   out_5438267541501267753[70] = 1;
   out_5438267541501267753[71] = 0;
   out_5438267541501267753[72] = 0;
   out_5438267541501267753[73] = 0;
   out_5438267541501267753[74] = 0;
   out_5438267541501267753[75] = 0;
   out_5438267541501267753[76] = 0;
   out_5438267541501267753[77] = 0;
   out_5438267541501267753[78] = 0;
   out_5438267541501267753[79] = 0;
   out_5438267541501267753[80] = 1;
}
void h_25(double *state, double *unused, double *out_4244982229226314297) {
   out_4244982229226314297[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1686578216042693128) {
   out_1686578216042693128[0] = 0;
   out_1686578216042693128[1] = 0;
   out_1686578216042693128[2] = 0;
   out_1686578216042693128[3] = 0;
   out_1686578216042693128[4] = 0;
   out_1686578216042693128[5] = 0;
   out_1686578216042693128[6] = 1;
   out_1686578216042693128[7] = 0;
   out_1686578216042693128[8] = 0;
}
void h_24(double *state, double *unused, double *out_197553727547805858) {
   out_197553727547805858[0] = state[4];
   out_197553727547805858[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6506899720698681391) {
   out_6506899720698681391[0] = 0;
   out_6506899720698681391[1] = 0;
   out_6506899720698681391[2] = 0;
   out_6506899720698681391[3] = 0;
   out_6506899720698681391[4] = 1;
   out_6506899720698681391[5] = 0;
   out_6506899720698681391[6] = 0;
   out_6506899720698681391[7] = 0;
   out_6506899720698681391[8] = 0;
   out_6506899720698681391[9] = 0;
   out_6506899720698681391[10] = 0;
   out_6506899720698681391[11] = 0;
   out_6506899720698681391[12] = 0;
   out_6506899720698681391[13] = 0;
   out_6506899720698681391[14] = 1;
   out_6506899720698681391[15] = 0;
   out_6506899720698681391[16] = 0;
   out_6506899720698681391[17] = 0;
}
void h_30(double *state, double *unused, double *out_4099462405005659326) {
   out_4099462405005659326[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1815917163185933198) {
   out_1815917163185933198[0] = 0;
   out_1815917163185933198[1] = 0;
   out_1815917163185933198[2] = 0;
   out_1815917163185933198[3] = 0;
   out_1815917163185933198[4] = 1;
   out_1815917163185933198[5] = 0;
   out_1815917163185933198[6] = 0;
   out_1815917163185933198[7] = 0;
   out_1815917163185933198[8] = 0;
}
void h_26(double *state, double *unused, double *out_9101135672666504971) {
   out_9101135672666504971[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5428081534916749352) {
   out_5428081534916749352[0] = 0;
   out_5428081534916749352[1] = 0;
   out_5428081534916749352[2] = 0;
   out_5428081534916749352[3] = 0;
   out_5428081534916749352[4] = 0;
   out_5428081534916749352[5] = 0;
   out_5428081534916749352[6] = 0;
   out_5428081534916749352[7] = 1;
   out_5428081534916749352[8] = 0;
}
void h_27(double *state, double *unused, double *out_756691038434531348) {
   out_756691038434531348[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3990680474986358109) {
   out_3990680474986358109[0] = 0;
   out_3990680474986358109[1] = 0;
   out_3990680474986358109[2] = 0;
   out_3990680474986358109[3] = 1;
   out_3990680474986358109[4] = 0;
   out_3990680474986358109[5] = 0;
   out_3990680474986358109[6] = 0;
   out_3990680474986358109[7] = 0;
   out_3990680474986358109[8] = 0;
}
void h_29(double *state, double *unused, double *out_7739969642829208644) {
   out_7739969642829208644[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1305685818871541014) {
   out_1305685818871541014[0] = 0;
   out_1305685818871541014[1] = 1;
   out_1305685818871541014[2] = 0;
   out_1305685818871541014[3] = 0;
   out_1305685818871541014[4] = 0;
   out_1305685818871541014[5] = 0;
   out_1305685818871541014[6] = 0;
   out_1305685818871541014[7] = 0;
   out_1305685818871541014[8] = 0;
}
void h_28(double *state, double *unused, double *out_186818814467131087) {
   out_186818814467131087[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7660301854784111900) {
   out_7660301854784111900[0] = 1;
   out_7660301854784111900[1] = 0;
   out_7660301854784111900[2] = 0;
   out_7660301854784111900[3] = 0;
   out_7660301854784111900[4] = 0;
   out_7660301854784111900[5] = 0;
   out_7660301854784111900[6] = 0;
   out_7660301854784111900[7] = 0;
   out_7660301854784111900[8] = 0;
}
void h_31(double *state, double *unused, double *out_3518283027594358144) {
   out_3518283027594358144[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1655932254165732700) {
   out_1655932254165732700[0] = 0;
   out_1655932254165732700[1] = 0;
   out_1655932254165732700[2] = 0;
   out_1655932254165732700[3] = 0;
   out_1655932254165732700[4] = 0;
   out_1655932254165732700[5] = 0;
   out_1655932254165732700[6] = 0;
   out_1655932254165732700[7] = 0;
   out_1655932254165732700[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5572165619661696722) {
  err_fun(nom_x, delta_x, out_5572165619661696722);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1924778118840772208) {
  inv_err_fun(nom_x, true_x, out_1924778118840772208);
}
void car_H_mod_fun(double *state, double *out_5209558866032184805) {
  H_mod_fun(state, out_5209558866032184805);
}
void car_f_fun(double *state, double dt, double *out_8731244167447695934) {
  f_fun(state,  dt, out_8731244167447695934);
}
void car_F_fun(double *state, double dt, double *out_5438267541501267753) {
  F_fun(state,  dt, out_5438267541501267753);
}
void car_h_25(double *state, double *unused, double *out_4244982229226314297) {
  h_25(state, unused, out_4244982229226314297);
}
void car_H_25(double *state, double *unused, double *out_1686578216042693128) {
  H_25(state, unused, out_1686578216042693128);
}
void car_h_24(double *state, double *unused, double *out_197553727547805858) {
  h_24(state, unused, out_197553727547805858);
}
void car_H_24(double *state, double *unused, double *out_6506899720698681391) {
  H_24(state, unused, out_6506899720698681391);
}
void car_h_30(double *state, double *unused, double *out_4099462405005659326) {
  h_30(state, unused, out_4099462405005659326);
}
void car_H_30(double *state, double *unused, double *out_1815917163185933198) {
  H_30(state, unused, out_1815917163185933198);
}
void car_h_26(double *state, double *unused, double *out_9101135672666504971) {
  h_26(state, unused, out_9101135672666504971);
}
void car_H_26(double *state, double *unused, double *out_5428081534916749352) {
  H_26(state, unused, out_5428081534916749352);
}
void car_h_27(double *state, double *unused, double *out_756691038434531348) {
  h_27(state, unused, out_756691038434531348);
}
void car_H_27(double *state, double *unused, double *out_3990680474986358109) {
  H_27(state, unused, out_3990680474986358109);
}
void car_h_29(double *state, double *unused, double *out_7739969642829208644) {
  h_29(state, unused, out_7739969642829208644);
}
void car_H_29(double *state, double *unused, double *out_1305685818871541014) {
  H_29(state, unused, out_1305685818871541014);
}
void car_h_28(double *state, double *unused, double *out_186818814467131087) {
  h_28(state, unused, out_186818814467131087);
}
void car_H_28(double *state, double *unused, double *out_7660301854784111900) {
  H_28(state, unused, out_7660301854784111900);
}
void car_h_31(double *state, double *unused, double *out_3518283027594358144) {
  h_31(state, unused, out_3518283027594358144);
}
void car_H_31(double *state, double *unused, double *out_1655932254165732700) {
  H_31(state, unused, out_1655932254165732700);
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
