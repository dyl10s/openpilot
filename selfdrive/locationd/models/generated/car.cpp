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
void err_fun(double *nom_x, double *delta_x, double *out_6119760954545072171) {
   out_6119760954545072171[0] = delta_x[0] + nom_x[0];
   out_6119760954545072171[1] = delta_x[1] + nom_x[1];
   out_6119760954545072171[2] = delta_x[2] + nom_x[2];
   out_6119760954545072171[3] = delta_x[3] + nom_x[3];
   out_6119760954545072171[4] = delta_x[4] + nom_x[4];
   out_6119760954545072171[5] = delta_x[5] + nom_x[5];
   out_6119760954545072171[6] = delta_x[6] + nom_x[6];
   out_6119760954545072171[7] = delta_x[7] + nom_x[7];
   out_6119760954545072171[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3032957791392119605) {
   out_3032957791392119605[0] = -nom_x[0] + true_x[0];
   out_3032957791392119605[1] = -nom_x[1] + true_x[1];
   out_3032957791392119605[2] = -nom_x[2] + true_x[2];
   out_3032957791392119605[3] = -nom_x[3] + true_x[3];
   out_3032957791392119605[4] = -nom_x[4] + true_x[4];
   out_3032957791392119605[5] = -nom_x[5] + true_x[5];
   out_3032957791392119605[6] = -nom_x[6] + true_x[6];
   out_3032957791392119605[7] = -nom_x[7] + true_x[7];
   out_3032957791392119605[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6225772227410316778) {
   out_6225772227410316778[0] = 1.0;
   out_6225772227410316778[1] = 0.0;
   out_6225772227410316778[2] = 0.0;
   out_6225772227410316778[3] = 0.0;
   out_6225772227410316778[4] = 0.0;
   out_6225772227410316778[5] = 0.0;
   out_6225772227410316778[6] = 0.0;
   out_6225772227410316778[7] = 0.0;
   out_6225772227410316778[8] = 0.0;
   out_6225772227410316778[9] = 0.0;
   out_6225772227410316778[10] = 1.0;
   out_6225772227410316778[11] = 0.0;
   out_6225772227410316778[12] = 0.0;
   out_6225772227410316778[13] = 0.0;
   out_6225772227410316778[14] = 0.0;
   out_6225772227410316778[15] = 0.0;
   out_6225772227410316778[16] = 0.0;
   out_6225772227410316778[17] = 0.0;
   out_6225772227410316778[18] = 0.0;
   out_6225772227410316778[19] = 0.0;
   out_6225772227410316778[20] = 1.0;
   out_6225772227410316778[21] = 0.0;
   out_6225772227410316778[22] = 0.0;
   out_6225772227410316778[23] = 0.0;
   out_6225772227410316778[24] = 0.0;
   out_6225772227410316778[25] = 0.0;
   out_6225772227410316778[26] = 0.0;
   out_6225772227410316778[27] = 0.0;
   out_6225772227410316778[28] = 0.0;
   out_6225772227410316778[29] = 0.0;
   out_6225772227410316778[30] = 1.0;
   out_6225772227410316778[31] = 0.0;
   out_6225772227410316778[32] = 0.0;
   out_6225772227410316778[33] = 0.0;
   out_6225772227410316778[34] = 0.0;
   out_6225772227410316778[35] = 0.0;
   out_6225772227410316778[36] = 0.0;
   out_6225772227410316778[37] = 0.0;
   out_6225772227410316778[38] = 0.0;
   out_6225772227410316778[39] = 0.0;
   out_6225772227410316778[40] = 1.0;
   out_6225772227410316778[41] = 0.0;
   out_6225772227410316778[42] = 0.0;
   out_6225772227410316778[43] = 0.0;
   out_6225772227410316778[44] = 0.0;
   out_6225772227410316778[45] = 0.0;
   out_6225772227410316778[46] = 0.0;
   out_6225772227410316778[47] = 0.0;
   out_6225772227410316778[48] = 0.0;
   out_6225772227410316778[49] = 0.0;
   out_6225772227410316778[50] = 1.0;
   out_6225772227410316778[51] = 0.0;
   out_6225772227410316778[52] = 0.0;
   out_6225772227410316778[53] = 0.0;
   out_6225772227410316778[54] = 0.0;
   out_6225772227410316778[55] = 0.0;
   out_6225772227410316778[56] = 0.0;
   out_6225772227410316778[57] = 0.0;
   out_6225772227410316778[58] = 0.0;
   out_6225772227410316778[59] = 0.0;
   out_6225772227410316778[60] = 1.0;
   out_6225772227410316778[61] = 0.0;
   out_6225772227410316778[62] = 0.0;
   out_6225772227410316778[63] = 0.0;
   out_6225772227410316778[64] = 0.0;
   out_6225772227410316778[65] = 0.0;
   out_6225772227410316778[66] = 0.0;
   out_6225772227410316778[67] = 0.0;
   out_6225772227410316778[68] = 0.0;
   out_6225772227410316778[69] = 0.0;
   out_6225772227410316778[70] = 1.0;
   out_6225772227410316778[71] = 0.0;
   out_6225772227410316778[72] = 0.0;
   out_6225772227410316778[73] = 0.0;
   out_6225772227410316778[74] = 0.0;
   out_6225772227410316778[75] = 0.0;
   out_6225772227410316778[76] = 0.0;
   out_6225772227410316778[77] = 0.0;
   out_6225772227410316778[78] = 0.0;
   out_6225772227410316778[79] = 0.0;
   out_6225772227410316778[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1791723405675881227) {
   out_1791723405675881227[0] = state[0];
   out_1791723405675881227[1] = state[1];
   out_1791723405675881227[2] = state[2];
   out_1791723405675881227[3] = state[3];
   out_1791723405675881227[4] = state[4];
   out_1791723405675881227[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1791723405675881227[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1791723405675881227[7] = state[7];
   out_1791723405675881227[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4540850954218753986) {
   out_4540850954218753986[0] = 1;
   out_4540850954218753986[1] = 0;
   out_4540850954218753986[2] = 0;
   out_4540850954218753986[3] = 0;
   out_4540850954218753986[4] = 0;
   out_4540850954218753986[5] = 0;
   out_4540850954218753986[6] = 0;
   out_4540850954218753986[7] = 0;
   out_4540850954218753986[8] = 0;
   out_4540850954218753986[9] = 0;
   out_4540850954218753986[10] = 1;
   out_4540850954218753986[11] = 0;
   out_4540850954218753986[12] = 0;
   out_4540850954218753986[13] = 0;
   out_4540850954218753986[14] = 0;
   out_4540850954218753986[15] = 0;
   out_4540850954218753986[16] = 0;
   out_4540850954218753986[17] = 0;
   out_4540850954218753986[18] = 0;
   out_4540850954218753986[19] = 0;
   out_4540850954218753986[20] = 1;
   out_4540850954218753986[21] = 0;
   out_4540850954218753986[22] = 0;
   out_4540850954218753986[23] = 0;
   out_4540850954218753986[24] = 0;
   out_4540850954218753986[25] = 0;
   out_4540850954218753986[26] = 0;
   out_4540850954218753986[27] = 0;
   out_4540850954218753986[28] = 0;
   out_4540850954218753986[29] = 0;
   out_4540850954218753986[30] = 1;
   out_4540850954218753986[31] = 0;
   out_4540850954218753986[32] = 0;
   out_4540850954218753986[33] = 0;
   out_4540850954218753986[34] = 0;
   out_4540850954218753986[35] = 0;
   out_4540850954218753986[36] = 0;
   out_4540850954218753986[37] = 0;
   out_4540850954218753986[38] = 0;
   out_4540850954218753986[39] = 0;
   out_4540850954218753986[40] = 1;
   out_4540850954218753986[41] = 0;
   out_4540850954218753986[42] = 0;
   out_4540850954218753986[43] = 0;
   out_4540850954218753986[44] = 0;
   out_4540850954218753986[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4540850954218753986[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4540850954218753986[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4540850954218753986[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4540850954218753986[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4540850954218753986[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4540850954218753986[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4540850954218753986[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4540850954218753986[53] = -9.8100000000000005*dt;
   out_4540850954218753986[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4540850954218753986[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4540850954218753986[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4540850954218753986[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4540850954218753986[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4540850954218753986[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4540850954218753986[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4540850954218753986[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4540850954218753986[62] = 0;
   out_4540850954218753986[63] = 0;
   out_4540850954218753986[64] = 0;
   out_4540850954218753986[65] = 0;
   out_4540850954218753986[66] = 0;
   out_4540850954218753986[67] = 0;
   out_4540850954218753986[68] = 0;
   out_4540850954218753986[69] = 0;
   out_4540850954218753986[70] = 1;
   out_4540850954218753986[71] = 0;
   out_4540850954218753986[72] = 0;
   out_4540850954218753986[73] = 0;
   out_4540850954218753986[74] = 0;
   out_4540850954218753986[75] = 0;
   out_4540850954218753986[76] = 0;
   out_4540850954218753986[77] = 0;
   out_4540850954218753986[78] = 0;
   out_4540850954218753986[79] = 0;
   out_4540850954218753986[80] = 1;
}
void h_25(double *state, double *unused, double *out_6713287060643499630) {
   out_6713287060643499630[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2967415998501920459) {
   out_2967415998501920459[0] = 0;
   out_2967415998501920459[1] = 0;
   out_2967415998501920459[2] = 0;
   out_2967415998501920459[3] = 0;
   out_2967415998501920459[4] = 0;
   out_2967415998501920459[5] = 0;
   out_2967415998501920459[6] = 1;
   out_2967415998501920459[7] = 0;
   out_2967415998501920459[8] = 0;
}
void h_24(double *state, double *unused, double *out_7006841003408788110) {
   out_7006841003408788110[0] = state[4];
   out_7006841003408788110[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5140065597507420025) {
   out_5140065597507420025[0] = 0;
   out_5140065597507420025[1] = 0;
   out_5140065597507420025[2] = 0;
   out_5140065597507420025[3] = 0;
   out_5140065597507420025[4] = 1;
   out_5140065597507420025[5] = 0;
   out_5140065597507420025[6] = 0;
   out_5140065597507420025[7] = 0;
   out_5140065597507420025[8] = 0;
   out_5140065597507420025[9] = 0;
   out_5140065597507420025[10] = 0;
   out_5140065597507420025[11] = 0;
   out_5140065597507420025[12] = 0;
   out_5140065597507420025[13] = 0;
   out_5140065597507420025[14] = 1;
   out_5140065597507420025[15] = 0;
   out_5140065597507420025[16] = 0;
   out_5140065597507420025[17] = 0;
}
void h_30(double *state, double *unused, double *out_57548165706851306) {
   out_57548165706851306[0] = state[4];
}
void H_30(double *state, double *unused, double *out_449083039994671832) {
   out_449083039994671832[0] = 0;
   out_449083039994671832[1] = 0;
   out_449083039994671832[2] = 0;
   out_449083039994671832[3] = 0;
   out_449083039994671832[4] = 1;
   out_449083039994671832[5] = 0;
   out_449083039994671832[6] = 0;
   out_449083039994671832[7] = 0;
   out_449083039994671832[8] = 0;
}
void h_26(double *state, double *unused, double *out_5284319070179179257) {
   out_5284319070179179257[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6708919317375976683) {
   out_6708919317375976683[0] = 0;
   out_6708919317375976683[1] = 0;
   out_6708919317375976683[2] = 0;
   out_6708919317375976683[3] = 0;
   out_6708919317375976683[4] = 0;
   out_6708919317375976683[5] = 0;
   out_6708919317375976683[6] = 0;
   out_6708919317375976683[7] = 1;
   out_6708919317375976683[8] = 0;
}
void h_27(double *state, double *unused, double *out_2937147548800054846) {
   out_2937147548800054846[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2623846351795096743) {
   out_2623846351795096743[0] = 0;
   out_2623846351795096743[1] = 0;
   out_2623846351795096743[2] = 0;
   out_2623846351795096743[3] = 1;
   out_2623846351795096743[4] = 0;
   out_2623846351795096743[5] = 0;
   out_2623846351795096743[6] = 0;
   out_2623846351795096743[7] = 0;
   out_2623846351795096743[8] = 0;
}
void h_29(double *state, double *unused, double *out_3094334217151183991) {
   out_3094334217151183991[0] = state[1];
}
void H_29(double *state, double *unused, double *out_61148304319720352) {
   out_61148304319720352[0] = 0;
   out_61148304319720352[1] = 1;
   out_61148304319720352[2] = 0;
   out_61148304319720352[3] = 0;
   out_61148304319720352[4] = 0;
   out_61148304319720352[5] = 0;
   out_61148304319720352[6] = 0;
   out_61148304319720352[7] = 0;
   out_61148304319720352[8] = 0;
}
void h_28(double *state, double *unused, double *out_2064525718860790799) {
   out_2064525718860790799[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5021250712749810222) {
   out_5021250712749810222[0] = 1;
   out_5021250712749810222[1] = 0;
   out_5021250712749810222[2] = 0;
   out_5021250712749810222[3] = 0;
   out_5021250712749810222[4] = 0;
   out_5021250712749810222[5] = 0;
   out_5021250712749810222[6] = 0;
   out_5021250712749810222[7] = 0;
   out_5021250712749810222[8] = 0;
}
void h_31(double *state, double *unused, double *out_6870473728994628775) {
   out_6870473728994628775[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7335127419609328159) {
   out_7335127419609328159[0] = 0;
   out_7335127419609328159[1] = 0;
   out_7335127419609328159[2] = 0;
   out_7335127419609328159[3] = 0;
   out_7335127419609328159[4] = 0;
   out_7335127419609328159[5] = 0;
   out_7335127419609328159[6] = 0;
   out_7335127419609328159[7] = 0;
   out_7335127419609328159[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6119760954545072171) {
  err_fun(nom_x, delta_x, out_6119760954545072171);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3032957791392119605) {
  inv_err_fun(nom_x, true_x, out_3032957791392119605);
}
void car_H_mod_fun(double *state, double *out_6225772227410316778) {
  H_mod_fun(state, out_6225772227410316778);
}
void car_f_fun(double *state, double dt, double *out_1791723405675881227) {
  f_fun(state,  dt, out_1791723405675881227);
}
void car_F_fun(double *state, double dt, double *out_4540850954218753986) {
  F_fun(state,  dt, out_4540850954218753986);
}
void car_h_25(double *state, double *unused, double *out_6713287060643499630) {
  h_25(state, unused, out_6713287060643499630);
}
void car_H_25(double *state, double *unused, double *out_2967415998501920459) {
  H_25(state, unused, out_2967415998501920459);
}
void car_h_24(double *state, double *unused, double *out_7006841003408788110) {
  h_24(state, unused, out_7006841003408788110);
}
void car_H_24(double *state, double *unused, double *out_5140065597507420025) {
  H_24(state, unused, out_5140065597507420025);
}
void car_h_30(double *state, double *unused, double *out_57548165706851306) {
  h_30(state, unused, out_57548165706851306);
}
void car_H_30(double *state, double *unused, double *out_449083039994671832) {
  H_30(state, unused, out_449083039994671832);
}
void car_h_26(double *state, double *unused, double *out_5284319070179179257) {
  h_26(state, unused, out_5284319070179179257);
}
void car_H_26(double *state, double *unused, double *out_6708919317375976683) {
  H_26(state, unused, out_6708919317375976683);
}
void car_h_27(double *state, double *unused, double *out_2937147548800054846) {
  h_27(state, unused, out_2937147548800054846);
}
void car_H_27(double *state, double *unused, double *out_2623846351795096743) {
  H_27(state, unused, out_2623846351795096743);
}
void car_h_29(double *state, double *unused, double *out_3094334217151183991) {
  h_29(state, unused, out_3094334217151183991);
}
void car_H_29(double *state, double *unused, double *out_61148304319720352) {
  H_29(state, unused, out_61148304319720352);
}
void car_h_28(double *state, double *unused, double *out_2064525718860790799) {
  h_28(state, unused, out_2064525718860790799);
}
void car_H_28(double *state, double *unused, double *out_5021250712749810222) {
  H_28(state, unused, out_5021250712749810222);
}
void car_h_31(double *state, double *unused, double *out_6870473728994628775) {
  h_31(state, unused, out_6870473728994628775);
}
void car_H_31(double *state, double *unused, double *out_7335127419609328159) {
  H_31(state, unused, out_7335127419609328159);
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
