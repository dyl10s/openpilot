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
void err_fun(double *nom_x, double *delta_x, double *out_6318981254884856825) {
   out_6318981254884856825[0] = delta_x[0] + nom_x[0];
   out_6318981254884856825[1] = delta_x[1] + nom_x[1];
   out_6318981254884856825[2] = delta_x[2] + nom_x[2];
   out_6318981254884856825[3] = delta_x[3] + nom_x[3];
   out_6318981254884856825[4] = delta_x[4] + nom_x[4];
   out_6318981254884856825[5] = delta_x[5] + nom_x[5];
   out_6318981254884856825[6] = delta_x[6] + nom_x[6];
   out_6318981254884856825[7] = delta_x[7] + nom_x[7];
   out_6318981254884856825[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6625913990707465652) {
   out_6625913990707465652[0] = -nom_x[0] + true_x[0];
   out_6625913990707465652[1] = -nom_x[1] + true_x[1];
   out_6625913990707465652[2] = -nom_x[2] + true_x[2];
   out_6625913990707465652[3] = -nom_x[3] + true_x[3];
   out_6625913990707465652[4] = -nom_x[4] + true_x[4];
   out_6625913990707465652[5] = -nom_x[5] + true_x[5];
   out_6625913990707465652[6] = -nom_x[6] + true_x[6];
   out_6625913990707465652[7] = -nom_x[7] + true_x[7];
   out_6625913990707465652[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6152129630444976452) {
   out_6152129630444976452[0] = 1.0;
   out_6152129630444976452[1] = 0.0;
   out_6152129630444976452[2] = 0.0;
   out_6152129630444976452[3] = 0.0;
   out_6152129630444976452[4] = 0.0;
   out_6152129630444976452[5] = 0.0;
   out_6152129630444976452[6] = 0.0;
   out_6152129630444976452[7] = 0.0;
   out_6152129630444976452[8] = 0.0;
   out_6152129630444976452[9] = 0.0;
   out_6152129630444976452[10] = 1.0;
   out_6152129630444976452[11] = 0.0;
   out_6152129630444976452[12] = 0.0;
   out_6152129630444976452[13] = 0.0;
   out_6152129630444976452[14] = 0.0;
   out_6152129630444976452[15] = 0.0;
   out_6152129630444976452[16] = 0.0;
   out_6152129630444976452[17] = 0.0;
   out_6152129630444976452[18] = 0.0;
   out_6152129630444976452[19] = 0.0;
   out_6152129630444976452[20] = 1.0;
   out_6152129630444976452[21] = 0.0;
   out_6152129630444976452[22] = 0.0;
   out_6152129630444976452[23] = 0.0;
   out_6152129630444976452[24] = 0.0;
   out_6152129630444976452[25] = 0.0;
   out_6152129630444976452[26] = 0.0;
   out_6152129630444976452[27] = 0.0;
   out_6152129630444976452[28] = 0.0;
   out_6152129630444976452[29] = 0.0;
   out_6152129630444976452[30] = 1.0;
   out_6152129630444976452[31] = 0.0;
   out_6152129630444976452[32] = 0.0;
   out_6152129630444976452[33] = 0.0;
   out_6152129630444976452[34] = 0.0;
   out_6152129630444976452[35] = 0.0;
   out_6152129630444976452[36] = 0.0;
   out_6152129630444976452[37] = 0.0;
   out_6152129630444976452[38] = 0.0;
   out_6152129630444976452[39] = 0.0;
   out_6152129630444976452[40] = 1.0;
   out_6152129630444976452[41] = 0.0;
   out_6152129630444976452[42] = 0.0;
   out_6152129630444976452[43] = 0.0;
   out_6152129630444976452[44] = 0.0;
   out_6152129630444976452[45] = 0.0;
   out_6152129630444976452[46] = 0.0;
   out_6152129630444976452[47] = 0.0;
   out_6152129630444976452[48] = 0.0;
   out_6152129630444976452[49] = 0.0;
   out_6152129630444976452[50] = 1.0;
   out_6152129630444976452[51] = 0.0;
   out_6152129630444976452[52] = 0.0;
   out_6152129630444976452[53] = 0.0;
   out_6152129630444976452[54] = 0.0;
   out_6152129630444976452[55] = 0.0;
   out_6152129630444976452[56] = 0.0;
   out_6152129630444976452[57] = 0.0;
   out_6152129630444976452[58] = 0.0;
   out_6152129630444976452[59] = 0.0;
   out_6152129630444976452[60] = 1.0;
   out_6152129630444976452[61] = 0.0;
   out_6152129630444976452[62] = 0.0;
   out_6152129630444976452[63] = 0.0;
   out_6152129630444976452[64] = 0.0;
   out_6152129630444976452[65] = 0.0;
   out_6152129630444976452[66] = 0.0;
   out_6152129630444976452[67] = 0.0;
   out_6152129630444976452[68] = 0.0;
   out_6152129630444976452[69] = 0.0;
   out_6152129630444976452[70] = 1.0;
   out_6152129630444976452[71] = 0.0;
   out_6152129630444976452[72] = 0.0;
   out_6152129630444976452[73] = 0.0;
   out_6152129630444976452[74] = 0.0;
   out_6152129630444976452[75] = 0.0;
   out_6152129630444976452[76] = 0.0;
   out_6152129630444976452[77] = 0.0;
   out_6152129630444976452[78] = 0.0;
   out_6152129630444976452[79] = 0.0;
   out_6152129630444976452[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6830787204701444163) {
   out_6830787204701444163[0] = state[0];
   out_6830787204701444163[1] = state[1];
   out_6830787204701444163[2] = state[2];
   out_6830787204701444163[3] = state[3];
   out_6830787204701444163[4] = state[4];
   out_6830787204701444163[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6830787204701444163[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6830787204701444163[7] = state[7];
   out_6830787204701444163[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2889206061873137605) {
   out_2889206061873137605[0] = 1;
   out_2889206061873137605[1] = 0;
   out_2889206061873137605[2] = 0;
   out_2889206061873137605[3] = 0;
   out_2889206061873137605[4] = 0;
   out_2889206061873137605[5] = 0;
   out_2889206061873137605[6] = 0;
   out_2889206061873137605[7] = 0;
   out_2889206061873137605[8] = 0;
   out_2889206061873137605[9] = 0;
   out_2889206061873137605[10] = 1;
   out_2889206061873137605[11] = 0;
   out_2889206061873137605[12] = 0;
   out_2889206061873137605[13] = 0;
   out_2889206061873137605[14] = 0;
   out_2889206061873137605[15] = 0;
   out_2889206061873137605[16] = 0;
   out_2889206061873137605[17] = 0;
   out_2889206061873137605[18] = 0;
   out_2889206061873137605[19] = 0;
   out_2889206061873137605[20] = 1;
   out_2889206061873137605[21] = 0;
   out_2889206061873137605[22] = 0;
   out_2889206061873137605[23] = 0;
   out_2889206061873137605[24] = 0;
   out_2889206061873137605[25] = 0;
   out_2889206061873137605[26] = 0;
   out_2889206061873137605[27] = 0;
   out_2889206061873137605[28] = 0;
   out_2889206061873137605[29] = 0;
   out_2889206061873137605[30] = 1;
   out_2889206061873137605[31] = 0;
   out_2889206061873137605[32] = 0;
   out_2889206061873137605[33] = 0;
   out_2889206061873137605[34] = 0;
   out_2889206061873137605[35] = 0;
   out_2889206061873137605[36] = 0;
   out_2889206061873137605[37] = 0;
   out_2889206061873137605[38] = 0;
   out_2889206061873137605[39] = 0;
   out_2889206061873137605[40] = 1;
   out_2889206061873137605[41] = 0;
   out_2889206061873137605[42] = 0;
   out_2889206061873137605[43] = 0;
   out_2889206061873137605[44] = 0;
   out_2889206061873137605[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2889206061873137605[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2889206061873137605[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2889206061873137605[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2889206061873137605[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2889206061873137605[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2889206061873137605[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2889206061873137605[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2889206061873137605[53] = -9.8100000000000005*dt;
   out_2889206061873137605[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2889206061873137605[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2889206061873137605[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2889206061873137605[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2889206061873137605[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2889206061873137605[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2889206061873137605[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2889206061873137605[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2889206061873137605[62] = 0;
   out_2889206061873137605[63] = 0;
   out_2889206061873137605[64] = 0;
   out_2889206061873137605[65] = 0;
   out_2889206061873137605[66] = 0;
   out_2889206061873137605[67] = 0;
   out_2889206061873137605[68] = 0;
   out_2889206061873137605[69] = 0;
   out_2889206061873137605[70] = 1;
   out_2889206061873137605[71] = 0;
   out_2889206061873137605[72] = 0;
   out_2889206061873137605[73] = 0;
   out_2889206061873137605[74] = 0;
   out_2889206061873137605[75] = 0;
   out_2889206061873137605[76] = 0;
   out_2889206061873137605[77] = 0;
   out_2889206061873137605[78] = 0;
   out_2889206061873137605[79] = 0;
   out_2889206061873137605[80] = 1;
}
void h_25(double *state, double *unused, double *out_489826982790321982) {
   out_489826982790321982[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3101426217352337927) {
   out_3101426217352337927[0] = 0;
   out_3101426217352337927[1] = 0;
   out_3101426217352337927[2] = 0;
   out_3101426217352337927[3] = 0;
   out_3101426217352337927[4] = 0;
   out_3101426217352337927[5] = 0;
   out_3101426217352337927[6] = 1;
   out_3101426217352337927[7] = 0;
   out_3101426217352337927[8] = 0;
}
void h_24(double *state, double *unused, double *out_8333585936499166595) {
   out_8333585936499166595[0] = state[4];
   out_8333585936499166595[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8374920500265350521) {
   out_8374920500265350521[0] = 0;
   out_8374920500265350521[1] = 0;
   out_8374920500265350521[2] = 0;
   out_8374920500265350521[3] = 0;
   out_8374920500265350521[4] = 1;
   out_8374920500265350521[5] = 0;
   out_8374920500265350521[6] = 0;
   out_8374920500265350521[7] = 0;
   out_8374920500265350521[8] = 0;
   out_8374920500265350521[9] = 0;
   out_8374920500265350521[10] = 0;
   out_8374920500265350521[11] = 0;
   out_8374920500265350521[12] = 0;
   out_8374920500265350521[13] = 0;
   out_8374920500265350521[14] = 1;
   out_8374920500265350521[15] = 0;
   out_8374920500265350521[16] = 0;
   out_8374920500265350521[17] = 0;
}
void h_30(double *state, double *unused, double *out_7403112512094201377) {
   out_7403112512094201377[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5619759175859586554) {
   out_5619759175859586554[0] = 0;
   out_5619759175859586554[1] = 0;
   out_5619759175859586554[2] = 0;
   out_5619759175859586554[3] = 0;
   out_5619759175859586554[4] = 1;
   out_5619759175859586554[5] = 0;
   out_5619759175859586554[6] = 0;
   out_5619759175859586554[7] = 0;
   out_5619759175859586554[8] = 0;
}
void h_26(double *state, double *unused, double *out_6041958293954504594) {
   out_6041958293954504594[0] = state[7];
}
void H_26(double *state, double *unused, double *out_640077101521718297) {
   out_640077101521718297[0] = 0;
   out_640077101521718297[1] = 0;
   out_640077101521718297[2] = 0;
   out_640077101521718297[3] = 0;
   out_640077101521718297[4] = 0;
   out_640077101521718297[5] = 0;
   out_640077101521718297[6] = 0;
   out_640077101521718297[7] = 1;
   out_640077101521718297[8] = 0;
}
void h_27(double *state, double *unused, double *out_8492142189216518783) {
   out_8492142189216518783[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3444995864059161643) {
   out_3444995864059161643[0] = 0;
   out_3444995864059161643[1] = 0;
   out_3444995864059161643[2] = 0;
   out_3444995864059161643[3] = 1;
   out_3444995864059161643[4] = 0;
   out_3444995864059161643[5] = 0;
   out_3444995864059161643[6] = 0;
   out_3444995864059161643[7] = 0;
   out_3444995864059161643[8] = 0;
}
void h_29(double *state, double *unused, double *out_610869538462469598) {
   out_610869538462469598[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6129990520173978738) {
   out_6129990520173978738[0] = 0;
   out_6129990520173978738[1] = 1;
   out_6129990520173978738[2] = 0;
   out_6129990520173978738[3] = 0;
   out_6129990520173978738[4] = 0;
   out_6129990520173978738[5] = 0;
   out_6129990520173978738[6] = 0;
   out_6129990520173978738[7] = 0;
   out_6129990520173978738[8] = 0;
}
void h_28(double *state, double *unused, double *out_3490468921555673138) {
   out_3490468921555673138[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1047591503104448164) {
   out_1047591503104448164[0] = 1;
   out_1047591503104448164[1] = 0;
   out_1047591503104448164[2] = 0;
   out_1047591503104448164[3] = 0;
   out_1047591503104448164[4] = 0;
   out_1047591503104448164[5] = 0;
   out_1047591503104448164[6] = 0;
   out_1047591503104448164[7] = 0;
   out_1047591503104448164[8] = 0;
}
void h_31(double *state, double *unused, double *out_1315479088578164838) {
   out_1315479088578164838[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1266285203755069773) {
   out_1266285203755069773[0] = 0;
   out_1266285203755069773[1] = 0;
   out_1266285203755069773[2] = 0;
   out_1266285203755069773[3] = 0;
   out_1266285203755069773[4] = 0;
   out_1266285203755069773[5] = 0;
   out_1266285203755069773[6] = 0;
   out_1266285203755069773[7] = 0;
   out_1266285203755069773[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6318981254884856825) {
  err_fun(nom_x, delta_x, out_6318981254884856825);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6625913990707465652) {
  inv_err_fun(nom_x, true_x, out_6625913990707465652);
}
void car_H_mod_fun(double *state, double *out_6152129630444976452) {
  H_mod_fun(state, out_6152129630444976452);
}
void car_f_fun(double *state, double dt, double *out_6830787204701444163) {
  f_fun(state,  dt, out_6830787204701444163);
}
void car_F_fun(double *state, double dt, double *out_2889206061873137605) {
  F_fun(state,  dt, out_2889206061873137605);
}
void car_h_25(double *state, double *unused, double *out_489826982790321982) {
  h_25(state, unused, out_489826982790321982);
}
void car_H_25(double *state, double *unused, double *out_3101426217352337927) {
  H_25(state, unused, out_3101426217352337927);
}
void car_h_24(double *state, double *unused, double *out_8333585936499166595) {
  h_24(state, unused, out_8333585936499166595);
}
void car_H_24(double *state, double *unused, double *out_8374920500265350521) {
  H_24(state, unused, out_8374920500265350521);
}
void car_h_30(double *state, double *unused, double *out_7403112512094201377) {
  h_30(state, unused, out_7403112512094201377);
}
void car_H_30(double *state, double *unused, double *out_5619759175859586554) {
  H_30(state, unused, out_5619759175859586554);
}
void car_h_26(double *state, double *unused, double *out_6041958293954504594) {
  h_26(state, unused, out_6041958293954504594);
}
void car_H_26(double *state, double *unused, double *out_640077101521718297) {
  H_26(state, unused, out_640077101521718297);
}
void car_h_27(double *state, double *unused, double *out_8492142189216518783) {
  h_27(state, unused, out_8492142189216518783);
}
void car_H_27(double *state, double *unused, double *out_3444995864059161643) {
  H_27(state, unused, out_3444995864059161643);
}
void car_h_29(double *state, double *unused, double *out_610869538462469598) {
  h_29(state, unused, out_610869538462469598);
}
void car_H_29(double *state, double *unused, double *out_6129990520173978738) {
  H_29(state, unused, out_6129990520173978738);
}
void car_h_28(double *state, double *unused, double *out_3490468921555673138) {
  h_28(state, unused, out_3490468921555673138);
}
void car_H_28(double *state, double *unused, double *out_1047591503104448164) {
  H_28(state, unused, out_1047591503104448164);
}
void car_h_31(double *state, double *unused, double *out_1315479088578164838) {
  h_31(state, unused, out_1315479088578164838);
}
void car_H_31(double *state, double *unused, double *out_1266285203755069773) {
  H_31(state, unused, out_1266285203755069773);
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
