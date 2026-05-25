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
void err_fun(double *nom_x, double *delta_x, double *out_8544853402428642963) {
   out_8544853402428642963[0] = delta_x[0] + nom_x[0];
   out_8544853402428642963[1] = delta_x[1] + nom_x[1];
   out_8544853402428642963[2] = delta_x[2] + nom_x[2];
   out_8544853402428642963[3] = delta_x[3] + nom_x[3];
   out_8544853402428642963[4] = delta_x[4] + nom_x[4];
   out_8544853402428642963[5] = delta_x[5] + nom_x[5];
   out_8544853402428642963[6] = delta_x[6] + nom_x[6];
   out_8544853402428642963[7] = delta_x[7] + nom_x[7];
   out_8544853402428642963[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4966147196229178357) {
   out_4966147196229178357[0] = -nom_x[0] + true_x[0];
   out_4966147196229178357[1] = -nom_x[1] + true_x[1];
   out_4966147196229178357[2] = -nom_x[2] + true_x[2];
   out_4966147196229178357[3] = -nom_x[3] + true_x[3];
   out_4966147196229178357[4] = -nom_x[4] + true_x[4];
   out_4966147196229178357[5] = -nom_x[5] + true_x[5];
   out_4966147196229178357[6] = -nom_x[6] + true_x[6];
   out_4966147196229178357[7] = -nom_x[7] + true_x[7];
   out_4966147196229178357[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5259284650049385741) {
   out_5259284650049385741[0] = 1.0;
   out_5259284650049385741[1] = 0.0;
   out_5259284650049385741[2] = 0.0;
   out_5259284650049385741[3] = 0.0;
   out_5259284650049385741[4] = 0.0;
   out_5259284650049385741[5] = 0.0;
   out_5259284650049385741[6] = 0.0;
   out_5259284650049385741[7] = 0.0;
   out_5259284650049385741[8] = 0.0;
   out_5259284650049385741[9] = 0.0;
   out_5259284650049385741[10] = 1.0;
   out_5259284650049385741[11] = 0.0;
   out_5259284650049385741[12] = 0.0;
   out_5259284650049385741[13] = 0.0;
   out_5259284650049385741[14] = 0.0;
   out_5259284650049385741[15] = 0.0;
   out_5259284650049385741[16] = 0.0;
   out_5259284650049385741[17] = 0.0;
   out_5259284650049385741[18] = 0.0;
   out_5259284650049385741[19] = 0.0;
   out_5259284650049385741[20] = 1.0;
   out_5259284650049385741[21] = 0.0;
   out_5259284650049385741[22] = 0.0;
   out_5259284650049385741[23] = 0.0;
   out_5259284650049385741[24] = 0.0;
   out_5259284650049385741[25] = 0.0;
   out_5259284650049385741[26] = 0.0;
   out_5259284650049385741[27] = 0.0;
   out_5259284650049385741[28] = 0.0;
   out_5259284650049385741[29] = 0.0;
   out_5259284650049385741[30] = 1.0;
   out_5259284650049385741[31] = 0.0;
   out_5259284650049385741[32] = 0.0;
   out_5259284650049385741[33] = 0.0;
   out_5259284650049385741[34] = 0.0;
   out_5259284650049385741[35] = 0.0;
   out_5259284650049385741[36] = 0.0;
   out_5259284650049385741[37] = 0.0;
   out_5259284650049385741[38] = 0.0;
   out_5259284650049385741[39] = 0.0;
   out_5259284650049385741[40] = 1.0;
   out_5259284650049385741[41] = 0.0;
   out_5259284650049385741[42] = 0.0;
   out_5259284650049385741[43] = 0.0;
   out_5259284650049385741[44] = 0.0;
   out_5259284650049385741[45] = 0.0;
   out_5259284650049385741[46] = 0.0;
   out_5259284650049385741[47] = 0.0;
   out_5259284650049385741[48] = 0.0;
   out_5259284650049385741[49] = 0.0;
   out_5259284650049385741[50] = 1.0;
   out_5259284650049385741[51] = 0.0;
   out_5259284650049385741[52] = 0.0;
   out_5259284650049385741[53] = 0.0;
   out_5259284650049385741[54] = 0.0;
   out_5259284650049385741[55] = 0.0;
   out_5259284650049385741[56] = 0.0;
   out_5259284650049385741[57] = 0.0;
   out_5259284650049385741[58] = 0.0;
   out_5259284650049385741[59] = 0.0;
   out_5259284650049385741[60] = 1.0;
   out_5259284650049385741[61] = 0.0;
   out_5259284650049385741[62] = 0.0;
   out_5259284650049385741[63] = 0.0;
   out_5259284650049385741[64] = 0.0;
   out_5259284650049385741[65] = 0.0;
   out_5259284650049385741[66] = 0.0;
   out_5259284650049385741[67] = 0.0;
   out_5259284650049385741[68] = 0.0;
   out_5259284650049385741[69] = 0.0;
   out_5259284650049385741[70] = 1.0;
   out_5259284650049385741[71] = 0.0;
   out_5259284650049385741[72] = 0.0;
   out_5259284650049385741[73] = 0.0;
   out_5259284650049385741[74] = 0.0;
   out_5259284650049385741[75] = 0.0;
   out_5259284650049385741[76] = 0.0;
   out_5259284650049385741[77] = 0.0;
   out_5259284650049385741[78] = 0.0;
   out_5259284650049385741[79] = 0.0;
   out_5259284650049385741[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5571654789601065205) {
   out_5571654789601065205[0] = state[0];
   out_5571654789601065205[1] = state[1];
   out_5571654789601065205[2] = state[2];
   out_5571654789601065205[3] = state[3];
   out_5571654789601065205[4] = state[4];
   out_5571654789601065205[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5571654789601065205[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5571654789601065205[7] = state[7];
   out_5571654789601065205[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7466465670683569774) {
   out_7466465670683569774[0] = 1;
   out_7466465670683569774[1] = 0;
   out_7466465670683569774[2] = 0;
   out_7466465670683569774[3] = 0;
   out_7466465670683569774[4] = 0;
   out_7466465670683569774[5] = 0;
   out_7466465670683569774[6] = 0;
   out_7466465670683569774[7] = 0;
   out_7466465670683569774[8] = 0;
   out_7466465670683569774[9] = 0;
   out_7466465670683569774[10] = 1;
   out_7466465670683569774[11] = 0;
   out_7466465670683569774[12] = 0;
   out_7466465670683569774[13] = 0;
   out_7466465670683569774[14] = 0;
   out_7466465670683569774[15] = 0;
   out_7466465670683569774[16] = 0;
   out_7466465670683569774[17] = 0;
   out_7466465670683569774[18] = 0;
   out_7466465670683569774[19] = 0;
   out_7466465670683569774[20] = 1;
   out_7466465670683569774[21] = 0;
   out_7466465670683569774[22] = 0;
   out_7466465670683569774[23] = 0;
   out_7466465670683569774[24] = 0;
   out_7466465670683569774[25] = 0;
   out_7466465670683569774[26] = 0;
   out_7466465670683569774[27] = 0;
   out_7466465670683569774[28] = 0;
   out_7466465670683569774[29] = 0;
   out_7466465670683569774[30] = 1;
   out_7466465670683569774[31] = 0;
   out_7466465670683569774[32] = 0;
   out_7466465670683569774[33] = 0;
   out_7466465670683569774[34] = 0;
   out_7466465670683569774[35] = 0;
   out_7466465670683569774[36] = 0;
   out_7466465670683569774[37] = 0;
   out_7466465670683569774[38] = 0;
   out_7466465670683569774[39] = 0;
   out_7466465670683569774[40] = 1;
   out_7466465670683569774[41] = 0;
   out_7466465670683569774[42] = 0;
   out_7466465670683569774[43] = 0;
   out_7466465670683569774[44] = 0;
   out_7466465670683569774[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7466465670683569774[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7466465670683569774[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7466465670683569774[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7466465670683569774[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7466465670683569774[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7466465670683569774[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7466465670683569774[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7466465670683569774[53] = -9.8100000000000005*dt;
   out_7466465670683569774[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7466465670683569774[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7466465670683569774[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7466465670683569774[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7466465670683569774[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7466465670683569774[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7466465670683569774[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7466465670683569774[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7466465670683569774[62] = 0;
   out_7466465670683569774[63] = 0;
   out_7466465670683569774[64] = 0;
   out_7466465670683569774[65] = 0;
   out_7466465670683569774[66] = 0;
   out_7466465670683569774[67] = 0;
   out_7466465670683569774[68] = 0;
   out_7466465670683569774[69] = 0;
   out_7466465670683569774[70] = 1;
   out_7466465670683569774[71] = 0;
   out_7466465670683569774[72] = 0;
   out_7466465670683569774[73] = 0;
   out_7466465670683569774[74] = 0;
   out_7466465670683569774[75] = 0;
   out_7466465670683569774[76] = 0;
   out_7466465670683569774[77] = 0;
   out_7466465670683569774[78] = 0;
   out_7466465670683569774[79] = 0;
   out_7466465670683569774[80] = 1;
}
void h_25(double *state, double *unused, double *out_7657999268865908143) {
   out_7657999268865908143[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8283767598475501035) {
   out_8283767598475501035[0] = 0;
   out_8283767598475501035[1] = 0;
   out_8283767598475501035[2] = 0;
   out_8283767598475501035[3] = 0;
   out_8283767598475501035[4] = 0;
   out_8283767598475501035[5] = 0;
   out_8283767598475501035[6] = 1;
   out_8283767598475501035[7] = 0;
   out_8283767598475501035[8] = 0;
}
void h_24(double *state, double *unused, double *out_8959567811302299328) {
   out_8959567811302299328[0] = state[4];
   out_8959567811302299328[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1708195791883982934) {
   out_1708195791883982934[0] = 0;
   out_1708195791883982934[1] = 0;
   out_1708195791883982934[2] = 0;
   out_1708195791883982934[3] = 0;
   out_1708195791883982934[4] = 1;
   out_1708195791883982934[5] = 0;
   out_1708195791883982934[6] = 0;
   out_1708195791883982934[7] = 0;
   out_1708195791883982934[8] = 0;
   out_1708195791883982934[9] = 0;
   out_1708195791883982934[10] = 0;
   out_1708195791883982934[11] = 0;
   out_1708195791883982934[12] = 0;
   out_1708195791883982934[13] = 0;
   out_1708195791883982934[14] = 1;
   out_1708195791883982934[15] = 0;
   out_1708195791883982934[16] = 0;
   out_1708195791883982934[17] = 0;
}
void h_30(double *state, double *unused, double *out_4661606344031996983) {
   out_4661606344031996983[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5765434639968252408) {
   out_5765434639968252408[0] = 0;
   out_5765434639968252408[1] = 0;
   out_5765434639968252408[2] = 0;
   out_5765434639968252408[3] = 0;
   out_5765434639968252408[4] = 1;
   out_5765434639968252408[5] = 0;
   out_5765434639968252408[6] = 0;
   out_5765434639968252408[7] = 0;
   out_5765434639968252408[8] = 0;
}
void h_26(double *state, double *unused, double *out_668943426824494179) {
   out_668943426824494179[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6421473156359994357) {
   out_6421473156359994357[0] = 0;
   out_6421473156359994357[1] = 0;
   out_6421473156359994357[2] = 0;
   out_6421473156359994357[3] = 0;
   out_6421473156359994357[4] = 0;
   out_6421473156359994357[5] = 0;
   out_6421473156359994357[6] = 0;
   out_6421473156359994357[7] = 1;
   out_6421473156359994357[8] = 0;
}
void h_27(double *state, double *unused, double *out_4581587017363022418) {
   out_4581587017363022418[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3541840568784309191) {
   out_3541840568784309191[0] = 0;
   out_3541840568784309191[1] = 0;
   out_3541840568784309191[2] = 0;
   out_3541840568784309191[3] = 1;
   out_3541840568784309191[4] = 0;
   out_3541840568784309191[5] = 0;
   out_3541840568784309191[6] = 0;
   out_3541840568784309191[7] = 0;
   out_3541840568784309191[8] = 0;
}
void h_29(double *state, double *unused, double *out_3311352477521500941) {
   out_3311352477521500941[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5255203295653860224) {
   out_5255203295653860224[0] = 0;
   out_5255203295653860224[1] = 1;
   out_5255203295653860224[2] = 0;
   out_5255203295653860224[3] = 0;
   out_5255203295653860224[4] = 0;
   out_5255203295653860224[5] = 0;
   out_5255203295653860224[6] = 0;
   out_5255203295653860224[7] = 0;
   out_5255203295653860224[8] = 0;
}
void h_28(double *state, double *unused, double *out_1769034914093169035) {
   out_1769034914093169035[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8109141760986160818) {
   out_8109141760986160818[0] = 1;
   out_8109141760986160818[1] = 0;
   out_8109141760986160818[2] = 0;
   out_8109141760986160818[3] = 0;
   out_8109141760986160818[4] = 0;
   out_8109141760986160818[5] = 0;
   out_8109141760986160818[6] = 0;
   out_8109141760986160818[7] = 0;
   out_8109141760986160818[8] = 0;
}
void h_31(double *state, double *unused, double *out_3703077070402039012) {
   out_3703077070402039012[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8253121636598540607) {
   out_8253121636598540607[0] = 0;
   out_8253121636598540607[1] = 0;
   out_8253121636598540607[2] = 0;
   out_8253121636598540607[3] = 0;
   out_8253121636598540607[4] = 0;
   out_8253121636598540607[5] = 0;
   out_8253121636598540607[6] = 0;
   out_8253121636598540607[7] = 0;
   out_8253121636598540607[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8544853402428642963) {
  err_fun(nom_x, delta_x, out_8544853402428642963);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4966147196229178357) {
  inv_err_fun(nom_x, true_x, out_4966147196229178357);
}
void car_H_mod_fun(double *state, double *out_5259284650049385741) {
  H_mod_fun(state, out_5259284650049385741);
}
void car_f_fun(double *state, double dt, double *out_5571654789601065205) {
  f_fun(state,  dt, out_5571654789601065205);
}
void car_F_fun(double *state, double dt, double *out_7466465670683569774) {
  F_fun(state,  dt, out_7466465670683569774);
}
void car_h_25(double *state, double *unused, double *out_7657999268865908143) {
  h_25(state, unused, out_7657999268865908143);
}
void car_H_25(double *state, double *unused, double *out_8283767598475501035) {
  H_25(state, unused, out_8283767598475501035);
}
void car_h_24(double *state, double *unused, double *out_8959567811302299328) {
  h_24(state, unused, out_8959567811302299328);
}
void car_H_24(double *state, double *unused, double *out_1708195791883982934) {
  H_24(state, unused, out_1708195791883982934);
}
void car_h_30(double *state, double *unused, double *out_4661606344031996983) {
  h_30(state, unused, out_4661606344031996983);
}
void car_H_30(double *state, double *unused, double *out_5765434639968252408) {
  H_30(state, unused, out_5765434639968252408);
}
void car_h_26(double *state, double *unused, double *out_668943426824494179) {
  h_26(state, unused, out_668943426824494179);
}
void car_H_26(double *state, double *unused, double *out_6421473156359994357) {
  H_26(state, unused, out_6421473156359994357);
}
void car_h_27(double *state, double *unused, double *out_4581587017363022418) {
  h_27(state, unused, out_4581587017363022418);
}
void car_H_27(double *state, double *unused, double *out_3541840568784309191) {
  H_27(state, unused, out_3541840568784309191);
}
void car_h_29(double *state, double *unused, double *out_3311352477521500941) {
  h_29(state, unused, out_3311352477521500941);
}
void car_H_29(double *state, double *unused, double *out_5255203295653860224) {
  H_29(state, unused, out_5255203295653860224);
}
void car_h_28(double *state, double *unused, double *out_1769034914093169035) {
  h_28(state, unused, out_1769034914093169035);
}
void car_H_28(double *state, double *unused, double *out_8109141760986160818) {
  H_28(state, unused, out_8109141760986160818);
}
void car_h_31(double *state, double *unused, double *out_3703077070402039012) {
  h_31(state, unused, out_3703077070402039012);
}
void car_H_31(double *state, double *unused, double *out_8253121636598540607) {
  H_31(state, unused, out_8253121636598540607);
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
