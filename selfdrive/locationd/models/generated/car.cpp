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
void err_fun(double *nom_x, double *delta_x, double *out_4413943037710355540) {
   out_4413943037710355540[0] = delta_x[0] + nom_x[0];
   out_4413943037710355540[1] = delta_x[1] + nom_x[1];
   out_4413943037710355540[2] = delta_x[2] + nom_x[2];
   out_4413943037710355540[3] = delta_x[3] + nom_x[3];
   out_4413943037710355540[4] = delta_x[4] + nom_x[4];
   out_4413943037710355540[5] = delta_x[5] + nom_x[5];
   out_4413943037710355540[6] = delta_x[6] + nom_x[6];
   out_4413943037710355540[7] = delta_x[7] + nom_x[7];
   out_4413943037710355540[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_896653973664715101) {
   out_896653973664715101[0] = -nom_x[0] + true_x[0];
   out_896653973664715101[1] = -nom_x[1] + true_x[1];
   out_896653973664715101[2] = -nom_x[2] + true_x[2];
   out_896653973664715101[3] = -nom_x[3] + true_x[3];
   out_896653973664715101[4] = -nom_x[4] + true_x[4];
   out_896653973664715101[5] = -nom_x[5] + true_x[5];
   out_896653973664715101[6] = -nom_x[6] + true_x[6];
   out_896653973664715101[7] = -nom_x[7] + true_x[7];
   out_896653973664715101[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5267188789104253679) {
   out_5267188789104253679[0] = 1.0;
   out_5267188789104253679[1] = 0.0;
   out_5267188789104253679[2] = 0.0;
   out_5267188789104253679[3] = 0.0;
   out_5267188789104253679[4] = 0.0;
   out_5267188789104253679[5] = 0.0;
   out_5267188789104253679[6] = 0.0;
   out_5267188789104253679[7] = 0.0;
   out_5267188789104253679[8] = 0.0;
   out_5267188789104253679[9] = 0.0;
   out_5267188789104253679[10] = 1.0;
   out_5267188789104253679[11] = 0.0;
   out_5267188789104253679[12] = 0.0;
   out_5267188789104253679[13] = 0.0;
   out_5267188789104253679[14] = 0.0;
   out_5267188789104253679[15] = 0.0;
   out_5267188789104253679[16] = 0.0;
   out_5267188789104253679[17] = 0.0;
   out_5267188789104253679[18] = 0.0;
   out_5267188789104253679[19] = 0.0;
   out_5267188789104253679[20] = 1.0;
   out_5267188789104253679[21] = 0.0;
   out_5267188789104253679[22] = 0.0;
   out_5267188789104253679[23] = 0.0;
   out_5267188789104253679[24] = 0.0;
   out_5267188789104253679[25] = 0.0;
   out_5267188789104253679[26] = 0.0;
   out_5267188789104253679[27] = 0.0;
   out_5267188789104253679[28] = 0.0;
   out_5267188789104253679[29] = 0.0;
   out_5267188789104253679[30] = 1.0;
   out_5267188789104253679[31] = 0.0;
   out_5267188789104253679[32] = 0.0;
   out_5267188789104253679[33] = 0.0;
   out_5267188789104253679[34] = 0.0;
   out_5267188789104253679[35] = 0.0;
   out_5267188789104253679[36] = 0.0;
   out_5267188789104253679[37] = 0.0;
   out_5267188789104253679[38] = 0.0;
   out_5267188789104253679[39] = 0.0;
   out_5267188789104253679[40] = 1.0;
   out_5267188789104253679[41] = 0.0;
   out_5267188789104253679[42] = 0.0;
   out_5267188789104253679[43] = 0.0;
   out_5267188789104253679[44] = 0.0;
   out_5267188789104253679[45] = 0.0;
   out_5267188789104253679[46] = 0.0;
   out_5267188789104253679[47] = 0.0;
   out_5267188789104253679[48] = 0.0;
   out_5267188789104253679[49] = 0.0;
   out_5267188789104253679[50] = 1.0;
   out_5267188789104253679[51] = 0.0;
   out_5267188789104253679[52] = 0.0;
   out_5267188789104253679[53] = 0.0;
   out_5267188789104253679[54] = 0.0;
   out_5267188789104253679[55] = 0.0;
   out_5267188789104253679[56] = 0.0;
   out_5267188789104253679[57] = 0.0;
   out_5267188789104253679[58] = 0.0;
   out_5267188789104253679[59] = 0.0;
   out_5267188789104253679[60] = 1.0;
   out_5267188789104253679[61] = 0.0;
   out_5267188789104253679[62] = 0.0;
   out_5267188789104253679[63] = 0.0;
   out_5267188789104253679[64] = 0.0;
   out_5267188789104253679[65] = 0.0;
   out_5267188789104253679[66] = 0.0;
   out_5267188789104253679[67] = 0.0;
   out_5267188789104253679[68] = 0.0;
   out_5267188789104253679[69] = 0.0;
   out_5267188789104253679[70] = 1.0;
   out_5267188789104253679[71] = 0.0;
   out_5267188789104253679[72] = 0.0;
   out_5267188789104253679[73] = 0.0;
   out_5267188789104253679[74] = 0.0;
   out_5267188789104253679[75] = 0.0;
   out_5267188789104253679[76] = 0.0;
   out_5267188789104253679[77] = 0.0;
   out_5267188789104253679[78] = 0.0;
   out_5267188789104253679[79] = 0.0;
   out_5267188789104253679[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1590758894307502735) {
   out_1590758894307502735[0] = state[0];
   out_1590758894307502735[1] = state[1];
   out_1590758894307502735[2] = state[2];
   out_1590758894307502735[3] = state[3];
   out_1590758894307502735[4] = state[4];
   out_1590758894307502735[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1590758894307502735[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1590758894307502735[7] = state[7];
   out_1590758894307502735[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4932077017586128960) {
   out_4932077017586128960[0] = 1;
   out_4932077017586128960[1] = 0;
   out_4932077017586128960[2] = 0;
   out_4932077017586128960[3] = 0;
   out_4932077017586128960[4] = 0;
   out_4932077017586128960[5] = 0;
   out_4932077017586128960[6] = 0;
   out_4932077017586128960[7] = 0;
   out_4932077017586128960[8] = 0;
   out_4932077017586128960[9] = 0;
   out_4932077017586128960[10] = 1;
   out_4932077017586128960[11] = 0;
   out_4932077017586128960[12] = 0;
   out_4932077017586128960[13] = 0;
   out_4932077017586128960[14] = 0;
   out_4932077017586128960[15] = 0;
   out_4932077017586128960[16] = 0;
   out_4932077017586128960[17] = 0;
   out_4932077017586128960[18] = 0;
   out_4932077017586128960[19] = 0;
   out_4932077017586128960[20] = 1;
   out_4932077017586128960[21] = 0;
   out_4932077017586128960[22] = 0;
   out_4932077017586128960[23] = 0;
   out_4932077017586128960[24] = 0;
   out_4932077017586128960[25] = 0;
   out_4932077017586128960[26] = 0;
   out_4932077017586128960[27] = 0;
   out_4932077017586128960[28] = 0;
   out_4932077017586128960[29] = 0;
   out_4932077017586128960[30] = 1;
   out_4932077017586128960[31] = 0;
   out_4932077017586128960[32] = 0;
   out_4932077017586128960[33] = 0;
   out_4932077017586128960[34] = 0;
   out_4932077017586128960[35] = 0;
   out_4932077017586128960[36] = 0;
   out_4932077017586128960[37] = 0;
   out_4932077017586128960[38] = 0;
   out_4932077017586128960[39] = 0;
   out_4932077017586128960[40] = 1;
   out_4932077017586128960[41] = 0;
   out_4932077017586128960[42] = 0;
   out_4932077017586128960[43] = 0;
   out_4932077017586128960[44] = 0;
   out_4932077017586128960[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4932077017586128960[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4932077017586128960[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4932077017586128960[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4932077017586128960[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4932077017586128960[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4932077017586128960[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4932077017586128960[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4932077017586128960[53] = -9.8100000000000005*dt;
   out_4932077017586128960[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4932077017586128960[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4932077017586128960[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4932077017586128960[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4932077017586128960[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4932077017586128960[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4932077017586128960[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4932077017586128960[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4932077017586128960[62] = 0;
   out_4932077017586128960[63] = 0;
   out_4932077017586128960[64] = 0;
   out_4932077017586128960[65] = 0;
   out_4932077017586128960[66] = 0;
   out_4932077017586128960[67] = 0;
   out_4932077017586128960[68] = 0;
   out_4932077017586128960[69] = 0;
   out_4932077017586128960[70] = 1;
   out_4932077017586128960[71] = 0;
   out_4932077017586128960[72] = 0;
   out_4932077017586128960[73] = 0;
   out_4932077017586128960[74] = 0;
   out_4932077017586128960[75] = 0;
   out_4932077017586128960[76] = 0;
   out_4932077017586128960[77] = 0;
   out_4932077017586128960[78] = 0;
   out_4932077017586128960[79] = 0;
   out_4932077017586128960[80] = 1;
}
void h_25(double *state, double *unused, double *out_2151142981028497358) {
   out_2151142981028497358[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5796040611085329032) {
   out_5796040611085329032[0] = 0;
   out_5796040611085329032[1] = 0;
   out_5796040611085329032[2] = 0;
   out_5796040611085329032[3] = 0;
   out_5796040611085329032[4] = 0;
   out_5796040611085329032[5] = 0;
   out_5796040611085329032[6] = 1;
   out_5796040611085329032[7] = 0;
   out_5796040611085329032[8] = 0;
}
void h_24(double *state, double *unused, double *out_7809478958388963293) {
   out_7809478958388963293[0] = state[4];
   out_7809478958388963293[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1813717459687561134) {
   out_1813717459687561134[0] = 0;
   out_1813717459687561134[1] = 0;
   out_1813717459687561134[2] = 0;
   out_1813717459687561134[3] = 0;
   out_1813717459687561134[4] = 1;
   out_1813717459687561134[5] = 0;
   out_1813717459687561134[6] = 0;
   out_1813717459687561134[7] = 0;
   out_1813717459687561134[8] = 0;
   out_1813717459687561134[9] = 0;
   out_1813717459687561134[10] = 0;
   out_1813717459687561134[11] = 0;
   out_1813717459687561134[12] = 0;
   out_1813717459687561134[13] = 0;
   out_1813717459687561134[14] = 1;
   out_1813717459687561134[15] = 0;
   out_1813717459687561134[16] = 0;
   out_1813717459687561134[17] = 0;
}
void h_30(double *state, double *unused, double *out_8921978207378848294) {
   out_8921978207378848294[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5734013121132605829) {
   out_5734013121132605829[0] = 0;
   out_5734013121132605829[1] = 0;
   out_5734013121132605829[2] = 0;
   out_5734013121132605829[3] = 0;
   out_5734013121132605829[4] = 1;
   out_5734013121132605829[5] = 0;
   out_5734013121132605829[6] = 0;
   out_5734013121132605829[7] = 0;
   out_5734013121132605829[8] = 0;
}
void h_26(double *state, double *unused, double *out_3355877023318338429) {
   out_3355877023318338429[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6452894675195640936) {
   out_6452894675195640936[0] = 0;
   out_6452894675195640936[1] = 0;
   out_6452894675195640936[2] = 0;
   out_6452894675195640936[3] = 0;
   out_6452894675195640936[4] = 0;
   out_6452894675195640936[5] = 0;
   out_6452894675195640936[6] = 0;
   out_6452894675195640936[7] = 1;
   out_6452894675195640936[8] = 0;
}
void h_27(double *state, double *unused, double *out_6869400431411979084) {
   out_6869400431411979084[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7908776432933030740) {
   out_7908776432933030740[0] = 0;
   out_7908776432933030740[1] = 0;
   out_7908776432933030740[2] = 0;
   out_7908776432933030740[3] = 1;
   out_7908776432933030740[4] = 0;
   out_7908776432933030740[5] = 0;
   out_7908776432933030740[6] = 0;
   out_7908776432933030740[7] = 0;
   out_7908776432933030740[8] = 0;
}
void h_29(double *state, double *unused, double *out_3696070991543523347) {
   out_3696070991543523347[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5223781776818213645) {
   out_5223781776818213645[0] = 0;
   out_5223781776818213645[1] = 1;
   out_5223781776818213645[2] = 0;
   out_5223781776818213645[3] = 0;
   out_5223781776818213645[4] = 0;
   out_5223781776818213645[5] = 0;
   out_5223781776818213645[6] = 0;
   out_5223781776818213645[7] = 0;
   out_5223781776818213645[8] = 0;
}
void h_28(double *state, double *unused, double *out_6575670374636726887) {
   out_6575670374636726887[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8140563279821807397) {
   out_8140563279821807397[0] = 1;
   out_8140563279821807397[1] = 0;
   out_8140563279821807397[2] = 0;
   out_8140563279821807397[3] = 0;
   out_8140563279821807397[4] = 0;
   out_8140563279821807397[5] = 0;
   out_8140563279821807397[6] = 0;
   out_8140563279821807397[7] = 0;
   out_8140563279821807397[8] = 0;
}
void h_31(double *state, double *unused, double *out_5612122275792175083) {
   out_5612122275792175083[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5826686572962289460) {
   out_5826686572962289460[0] = 0;
   out_5826686572962289460[1] = 0;
   out_5826686572962289460[2] = 0;
   out_5826686572962289460[3] = 0;
   out_5826686572962289460[4] = 0;
   out_5826686572962289460[5] = 0;
   out_5826686572962289460[6] = 0;
   out_5826686572962289460[7] = 0;
   out_5826686572962289460[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4413943037710355540) {
  err_fun(nom_x, delta_x, out_4413943037710355540);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_896653973664715101) {
  inv_err_fun(nom_x, true_x, out_896653973664715101);
}
void car_H_mod_fun(double *state, double *out_5267188789104253679) {
  H_mod_fun(state, out_5267188789104253679);
}
void car_f_fun(double *state, double dt, double *out_1590758894307502735) {
  f_fun(state,  dt, out_1590758894307502735);
}
void car_F_fun(double *state, double dt, double *out_4932077017586128960) {
  F_fun(state,  dt, out_4932077017586128960);
}
void car_h_25(double *state, double *unused, double *out_2151142981028497358) {
  h_25(state, unused, out_2151142981028497358);
}
void car_H_25(double *state, double *unused, double *out_5796040611085329032) {
  H_25(state, unused, out_5796040611085329032);
}
void car_h_24(double *state, double *unused, double *out_7809478958388963293) {
  h_24(state, unused, out_7809478958388963293);
}
void car_H_24(double *state, double *unused, double *out_1813717459687561134) {
  H_24(state, unused, out_1813717459687561134);
}
void car_h_30(double *state, double *unused, double *out_8921978207378848294) {
  h_30(state, unused, out_8921978207378848294);
}
void car_H_30(double *state, double *unused, double *out_5734013121132605829) {
  H_30(state, unused, out_5734013121132605829);
}
void car_h_26(double *state, double *unused, double *out_3355877023318338429) {
  h_26(state, unused, out_3355877023318338429);
}
void car_H_26(double *state, double *unused, double *out_6452894675195640936) {
  H_26(state, unused, out_6452894675195640936);
}
void car_h_27(double *state, double *unused, double *out_6869400431411979084) {
  h_27(state, unused, out_6869400431411979084);
}
void car_H_27(double *state, double *unused, double *out_7908776432933030740) {
  H_27(state, unused, out_7908776432933030740);
}
void car_h_29(double *state, double *unused, double *out_3696070991543523347) {
  h_29(state, unused, out_3696070991543523347);
}
void car_H_29(double *state, double *unused, double *out_5223781776818213645) {
  H_29(state, unused, out_5223781776818213645);
}
void car_h_28(double *state, double *unused, double *out_6575670374636726887) {
  h_28(state, unused, out_6575670374636726887);
}
void car_H_28(double *state, double *unused, double *out_8140563279821807397) {
  H_28(state, unused, out_8140563279821807397);
}
void car_h_31(double *state, double *unused, double *out_5612122275792175083) {
  h_31(state, unused, out_5612122275792175083);
}
void car_H_31(double *state, double *unused, double *out_5826686572962289460) {
  H_31(state, unused, out_5826686572962289460);
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
