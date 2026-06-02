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
void err_fun(double *nom_x, double *delta_x, double *out_6333242559483084265) {
   out_6333242559483084265[0] = delta_x[0] + nom_x[0];
   out_6333242559483084265[1] = delta_x[1] + nom_x[1];
   out_6333242559483084265[2] = delta_x[2] + nom_x[2];
   out_6333242559483084265[3] = delta_x[3] + nom_x[3];
   out_6333242559483084265[4] = delta_x[4] + nom_x[4];
   out_6333242559483084265[5] = delta_x[5] + nom_x[5];
   out_6333242559483084265[6] = delta_x[6] + nom_x[6];
   out_6333242559483084265[7] = delta_x[7] + nom_x[7];
   out_6333242559483084265[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_829248915283082072) {
   out_829248915283082072[0] = -nom_x[0] + true_x[0];
   out_829248915283082072[1] = -nom_x[1] + true_x[1];
   out_829248915283082072[2] = -nom_x[2] + true_x[2];
   out_829248915283082072[3] = -nom_x[3] + true_x[3];
   out_829248915283082072[4] = -nom_x[4] + true_x[4];
   out_829248915283082072[5] = -nom_x[5] + true_x[5];
   out_829248915283082072[6] = -nom_x[6] + true_x[6];
   out_829248915283082072[7] = -nom_x[7] + true_x[7];
   out_829248915283082072[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8283696179185346057) {
   out_8283696179185346057[0] = 1.0;
   out_8283696179185346057[1] = 0.0;
   out_8283696179185346057[2] = 0.0;
   out_8283696179185346057[3] = 0.0;
   out_8283696179185346057[4] = 0.0;
   out_8283696179185346057[5] = 0.0;
   out_8283696179185346057[6] = 0.0;
   out_8283696179185346057[7] = 0.0;
   out_8283696179185346057[8] = 0.0;
   out_8283696179185346057[9] = 0.0;
   out_8283696179185346057[10] = 1.0;
   out_8283696179185346057[11] = 0.0;
   out_8283696179185346057[12] = 0.0;
   out_8283696179185346057[13] = 0.0;
   out_8283696179185346057[14] = 0.0;
   out_8283696179185346057[15] = 0.0;
   out_8283696179185346057[16] = 0.0;
   out_8283696179185346057[17] = 0.0;
   out_8283696179185346057[18] = 0.0;
   out_8283696179185346057[19] = 0.0;
   out_8283696179185346057[20] = 1.0;
   out_8283696179185346057[21] = 0.0;
   out_8283696179185346057[22] = 0.0;
   out_8283696179185346057[23] = 0.0;
   out_8283696179185346057[24] = 0.0;
   out_8283696179185346057[25] = 0.0;
   out_8283696179185346057[26] = 0.0;
   out_8283696179185346057[27] = 0.0;
   out_8283696179185346057[28] = 0.0;
   out_8283696179185346057[29] = 0.0;
   out_8283696179185346057[30] = 1.0;
   out_8283696179185346057[31] = 0.0;
   out_8283696179185346057[32] = 0.0;
   out_8283696179185346057[33] = 0.0;
   out_8283696179185346057[34] = 0.0;
   out_8283696179185346057[35] = 0.0;
   out_8283696179185346057[36] = 0.0;
   out_8283696179185346057[37] = 0.0;
   out_8283696179185346057[38] = 0.0;
   out_8283696179185346057[39] = 0.0;
   out_8283696179185346057[40] = 1.0;
   out_8283696179185346057[41] = 0.0;
   out_8283696179185346057[42] = 0.0;
   out_8283696179185346057[43] = 0.0;
   out_8283696179185346057[44] = 0.0;
   out_8283696179185346057[45] = 0.0;
   out_8283696179185346057[46] = 0.0;
   out_8283696179185346057[47] = 0.0;
   out_8283696179185346057[48] = 0.0;
   out_8283696179185346057[49] = 0.0;
   out_8283696179185346057[50] = 1.0;
   out_8283696179185346057[51] = 0.0;
   out_8283696179185346057[52] = 0.0;
   out_8283696179185346057[53] = 0.0;
   out_8283696179185346057[54] = 0.0;
   out_8283696179185346057[55] = 0.0;
   out_8283696179185346057[56] = 0.0;
   out_8283696179185346057[57] = 0.0;
   out_8283696179185346057[58] = 0.0;
   out_8283696179185346057[59] = 0.0;
   out_8283696179185346057[60] = 1.0;
   out_8283696179185346057[61] = 0.0;
   out_8283696179185346057[62] = 0.0;
   out_8283696179185346057[63] = 0.0;
   out_8283696179185346057[64] = 0.0;
   out_8283696179185346057[65] = 0.0;
   out_8283696179185346057[66] = 0.0;
   out_8283696179185346057[67] = 0.0;
   out_8283696179185346057[68] = 0.0;
   out_8283696179185346057[69] = 0.0;
   out_8283696179185346057[70] = 1.0;
   out_8283696179185346057[71] = 0.0;
   out_8283696179185346057[72] = 0.0;
   out_8283696179185346057[73] = 0.0;
   out_8283696179185346057[74] = 0.0;
   out_8283696179185346057[75] = 0.0;
   out_8283696179185346057[76] = 0.0;
   out_8283696179185346057[77] = 0.0;
   out_8283696179185346057[78] = 0.0;
   out_8283696179185346057[79] = 0.0;
   out_8283696179185346057[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3453347444055346076) {
   out_3453347444055346076[0] = state[0];
   out_3453347444055346076[1] = state[1];
   out_3453347444055346076[2] = state[2];
   out_3453347444055346076[3] = state[3];
   out_3453347444055346076[4] = state[4];
   out_3453347444055346076[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3453347444055346076[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3453347444055346076[7] = state[7];
   out_3453347444055346076[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1825222330008905672) {
   out_1825222330008905672[0] = 1;
   out_1825222330008905672[1] = 0;
   out_1825222330008905672[2] = 0;
   out_1825222330008905672[3] = 0;
   out_1825222330008905672[4] = 0;
   out_1825222330008905672[5] = 0;
   out_1825222330008905672[6] = 0;
   out_1825222330008905672[7] = 0;
   out_1825222330008905672[8] = 0;
   out_1825222330008905672[9] = 0;
   out_1825222330008905672[10] = 1;
   out_1825222330008905672[11] = 0;
   out_1825222330008905672[12] = 0;
   out_1825222330008905672[13] = 0;
   out_1825222330008905672[14] = 0;
   out_1825222330008905672[15] = 0;
   out_1825222330008905672[16] = 0;
   out_1825222330008905672[17] = 0;
   out_1825222330008905672[18] = 0;
   out_1825222330008905672[19] = 0;
   out_1825222330008905672[20] = 1;
   out_1825222330008905672[21] = 0;
   out_1825222330008905672[22] = 0;
   out_1825222330008905672[23] = 0;
   out_1825222330008905672[24] = 0;
   out_1825222330008905672[25] = 0;
   out_1825222330008905672[26] = 0;
   out_1825222330008905672[27] = 0;
   out_1825222330008905672[28] = 0;
   out_1825222330008905672[29] = 0;
   out_1825222330008905672[30] = 1;
   out_1825222330008905672[31] = 0;
   out_1825222330008905672[32] = 0;
   out_1825222330008905672[33] = 0;
   out_1825222330008905672[34] = 0;
   out_1825222330008905672[35] = 0;
   out_1825222330008905672[36] = 0;
   out_1825222330008905672[37] = 0;
   out_1825222330008905672[38] = 0;
   out_1825222330008905672[39] = 0;
   out_1825222330008905672[40] = 1;
   out_1825222330008905672[41] = 0;
   out_1825222330008905672[42] = 0;
   out_1825222330008905672[43] = 0;
   out_1825222330008905672[44] = 0;
   out_1825222330008905672[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1825222330008905672[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1825222330008905672[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1825222330008905672[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1825222330008905672[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1825222330008905672[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1825222330008905672[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1825222330008905672[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1825222330008905672[53] = -9.8100000000000005*dt;
   out_1825222330008905672[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1825222330008905672[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1825222330008905672[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1825222330008905672[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1825222330008905672[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1825222330008905672[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1825222330008905672[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1825222330008905672[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1825222330008905672[62] = 0;
   out_1825222330008905672[63] = 0;
   out_1825222330008905672[64] = 0;
   out_1825222330008905672[65] = 0;
   out_1825222330008905672[66] = 0;
   out_1825222330008905672[67] = 0;
   out_1825222330008905672[68] = 0;
   out_1825222330008905672[69] = 0;
   out_1825222330008905672[70] = 1;
   out_1825222330008905672[71] = 0;
   out_1825222330008905672[72] = 0;
   out_1825222330008905672[73] = 0;
   out_1825222330008905672[74] = 0;
   out_1825222330008905672[75] = 0;
   out_1825222330008905672[76] = 0;
   out_1825222330008905672[77] = 0;
   out_1825222330008905672[78] = 0;
   out_1825222330008905672[79] = 0;
   out_1825222330008905672[80] = 1;
}
void h_25(double *state, double *unused, double *out_7364871104219513908) {
   out_7364871104219513908[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5259356069339540719) {
   out_5259356069339540719[0] = 0;
   out_5259356069339540719[1] = 0;
   out_5259356069339540719[2] = 0;
   out_5259356069339540719[3] = 0;
   out_5259356069339540719[4] = 0;
   out_5259356069339540719[5] = 0;
   out_5259356069339540719[6] = 1;
   out_5259356069339540719[7] = 0;
   out_5259356069339540719[8] = 0;
}
void h_24(double *state, double *unused, double *out_6181950591427252357) {
   out_6181950591427252357[0] = state[4];
   out_6181950591427252357[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1316215737251977382) {
   out_1316215737251977382[0] = 0;
   out_1316215737251977382[1] = 0;
   out_1316215737251977382[2] = 0;
   out_1316215737251977382[3] = 0;
   out_1316215737251977382[4] = 1;
   out_1316215737251977382[5] = 0;
   out_1316215737251977382[6] = 0;
   out_1316215737251977382[7] = 0;
   out_1316215737251977382[8] = 0;
   out_1316215737251977382[9] = 0;
   out_1316215737251977382[10] = 0;
   out_1316215737251977382[11] = 0;
   out_1316215737251977382[12] = 0;
   out_1316215737251977382[13] = 0;
   out_1316215737251977382[14] = 1;
   out_1316215737251977382[15] = 0;
   out_1316215737251977382[16] = 0;
   out_1316215737251977382[17] = 0;
}
void h_30(double *state, double *unused, double *out_4311037743139686772) {
   out_4311037743139686772[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1657334272152076036) {
   out_1657334272152076036[0] = 0;
   out_1657334272152076036[1] = 0;
   out_1657334272152076036[2] = 0;
   out_1657334272152076036[3] = 0;
   out_1657334272152076036[4] = 1;
   out_1657334272152076036[5] = 0;
   out_1657334272152076036[6] = 0;
   out_1657334272152076036[7] = 0;
   out_1657334272152076036[8] = 0;
}
void h_26(double *state, double *unused, double *out_8569605146509354979) {
   out_8569605146509354979[0] = state[7];
}
void H_26(double *state, double *unused, double *out_9000859388213596943) {
   out_9000859388213596943[0] = 0;
   out_9000859388213596943[1] = 0;
   out_9000859388213596943[2] = 0;
   out_9000859388213596943[3] = 0;
   out_9000859388213596943[4] = 0;
   out_9000859388213596943[5] = 0;
   out_9000859388213596943[6] = 0;
   out_9000859388213596943[7] = 1;
   out_9000859388213596943[8] = 0;
}
void h_27(double *state, double *unused, double *out_2363197836558668263) {
   out_2363197836558668263[0] = state[3];
}
void H_27(double *state, double *unused, double *out_517429039648348875) {
   out_517429039648348875[0] = 0;
   out_517429039648348875[1] = 0;
   out_517429039648348875[2] = 0;
   out_517429039648348875[3] = 1;
   out_517429039648348875[4] = 0;
   out_517429039648348875[5] = 0;
   out_517429039648348875[6] = 0;
   out_517429039648348875[7] = 0;
   out_517429039648348875[8] = 0;
}
void h_29(double *state, double *unused, double *out_1498485639869833389) {
   out_1498485639869833389[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2230791766517899908) {
   out_2230791766517899908[0] = 0;
   out_2230791766517899908[1] = 1;
   out_2230791766517899908[2] = 0;
   out_2230791766517899908[3] = 0;
   out_2230791766517899908[4] = 0;
   out_2230791766517899908[5] = 0;
   out_2230791766517899908[6] = 0;
   out_2230791766517899908[7] = 0;
   out_2230791766517899908[8] = 0;
}
void h_28(double *state, double *unused, double *out_6657345575881808179) {
   out_6657345575881808179[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7313190783587430482) {
   out_7313190783587430482[0] = 1;
   out_7313190783587430482[1] = 0;
   out_7313190783587430482[2] = 0;
   out_7313190783587430482[3] = 0;
   out_7313190783587430482[4] = 0;
   out_7313190783587430482[5] = 0;
   out_7313190783587430482[6] = 0;
   out_7313190783587430482[7] = 0;
   out_7313190783587430482[8] = 0;
}
void h_31(double *state, double *unused, double *out_398394152601158533) {
   out_398394152601158533[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5228710107462580291) {
   out_5228710107462580291[0] = 0;
   out_5228710107462580291[1] = 0;
   out_5228710107462580291[2] = 0;
   out_5228710107462580291[3] = 0;
   out_5228710107462580291[4] = 0;
   out_5228710107462580291[5] = 0;
   out_5228710107462580291[6] = 0;
   out_5228710107462580291[7] = 0;
   out_5228710107462580291[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6333242559483084265) {
  err_fun(nom_x, delta_x, out_6333242559483084265);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_829248915283082072) {
  inv_err_fun(nom_x, true_x, out_829248915283082072);
}
void car_H_mod_fun(double *state, double *out_8283696179185346057) {
  H_mod_fun(state, out_8283696179185346057);
}
void car_f_fun(double *state, double dt, double *out_3453347444055346076) {
  f_fun(state,  dt, out_3453347444055346076);
}
void car_F_fun(double *state, double dt, double *out_1825222330008905672) {
  F_fun(state,  dt, out_1825222330008905672);
}
void car_h_25(double *state, double *unused, double *out_7364871104219513908) {
  h_25(state, unused, out_7364871104219513908);
}
void car_H_25(double *state, double *unused, double *out_5259356069339540719) {
  H_25(state, unused, out_5259356069339540719);
}
void car_h_24(double *state, double *unused, double *out_6181950591427252357) {
  h_24(state, unused, out_6181950591427252357);
}
void car_H_24(double *state, double *unused, double *out_1316215737251977382) {
  H_24(state, unused, out_1316215737251977382);
}
void car_h_30(double *state, double *unused, double *out_4311037743139686772) {
  h_30(state, unused, out_4311037743139686772);
}
void car_H_30(double *state, double *unused, double *out_1657334272152076036) {
  H_30(state, unused, out_1657334272152076036);
}
void car_h_26(double *state, double *unused, double *out_8569605146509354979) {
  h_26(state, unused, out_8569605146509354979);
}
void car_H_26(double *state, double *unused, double *out_9000859388213596943) {
  H_26(state, unused, out_9000859388213596943);
}
void car_h_27(double *state, double *unused, double *out_2363197836558668263) {
  h_27(state, unused, out_2363197836558668263);
}
void car_H_27(double *state, double *unused, double *out_517429039648348875) {
  H_27(state, unused, out_517429039648348875);
}
void car_h_29(double *state, double *unused, double *out_1498485639869833389) {
  h_29(state, unused, out_1498485639869833389);
}
void car_H_29(double *state, double *unused, double *out_2230791766517899908) {
  H_29(state, unused, out_2230791766517899908);
}
void car_h_28(double *state, double *unused, double *out_6657345575881808179) {
  h_28(state, unused, out_6657345575881808179);
}
void car_H_28(double *state, double *unused, double *out_7313190783587430482) {
  H_28(state, unused, out_7313190783587430482);
}
void car_h_31(double *state, double *unused, double *out_398394152601158533) {
  h_31(state, unused, out_398394152601158533);
}
void car_H_31(double *state, double *unused, double *out_5228710107462580291) {
  H_31(state, unused, out_5228710107462580291);
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
