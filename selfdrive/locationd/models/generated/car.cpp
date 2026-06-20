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
void err_fun(double *nom_x, double *delta_x, double *out_787387508528698300) {
   out_787387508528698300[0] = delta_x[0] + nom_x[0];
   out_787387508528698300[1] = delta_x[1] + nom_x[1];
   out_787387508528698300[2] = delta_x[2] + nom_x[2];
   out_787387508528698300[3] = delta_x[3] + nom_x[3];
   out_787387508528698300[4] = delta_x[4] + nom_x[4];
   out_787387508528698300[5] = delta_x[5] + nom_x[5];
   out_787387508528698300[6] = delta_x[6] + nom_x[6];
   out_787387508528698300[7] = delta_x[7] + nom_x[7];
   out_787387508528698300[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4326351974821968285) {
   out_4326351974821968285[0] = -nom_x[0] + true_x[0];
   out_4326351974821968285[1] = -nom_x[1] + true_x[1];
   out_4326351974821968285[2] = -nom_x[2] + true_x[2];
   out_4326351974821968285[3] = -nom_x[3] + true_x[3];
   out_4326351974821968285[4] = -nom_x[4] + true_x[4];
   out_4326351974821968285[5] = -nom_x[5] + true_x[5];
   out_4326351974821968285[6] = -nom_x[6] + true_x[6];
   out_4326351974821968285[7] = -nom_x[7] + true_x[7];
   out_4326351974821968285[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_253192225752308971) {
   out_253192225752308971[0] = 1.0;
   out_253192225752308971[1] = 0.0;
   out_253192225752308971[2] = 0.0;
   out_253192225752308971[3] = 0.0;
   out_253192225752308971[4] = 0.0;
   out_253192225752308971[5] = 0.0;
   out_253192225752308971[6] = 0.0;
   out_253192225752308971[7] = 0.0;
   out_253192225752308971[8] = 0.0;
   out_253192225752308971[9] = 0.0;
   out_253192225752308971[10] = 1.0;
   out_253192225752308971[11] = 0.0;
   out_253192225752308971[12] = 0.0;
   out_253192225752308971[13] = 0.0;
   out_253192225752308971[14] = 0.0;
   out_253192225752308971[15] = 0.0;
   out_253192225752308971[16] = 0.0;
   out_253192225752308971[17] = 0.0;
   out_253192225752308971[18] = 0.0;
   out_253192225752308971[19] = 0.0;
   out_253192225752308971[20] = 1.0;
   out_253192225752308971[21] = 0.0;
   out_253192225752308971[22] = 0.0;
   out_253192225752308971[23] = 0.0;
   out_253192225752308971[24] = 0.0;
   out_253192225752308971[25] = 0.0;
   out_253192225752308971[26] = 0.0;
   out_253192225752308971[27] = 0.0;
   out_253192225752308971[28] = 0.0;
   out_253192225752308971[29] = 0.0;
   out_253192225752308971[30] = 1.0;
   out_253192225752308971[31] = 0.0;
   out_253192225752308971[32] = 0.0;
   out_253192225752308971[33] = 0.0;
   out_253192225752308971[34] = 0.0;
   out_253192225752308971[35] = 0.0;
   out_253192225752308971[36] = 0.0;
   out_253192225752308971[37] = 0.0;
   out_253192225752308971[38] = 0.0;
   out_253192225752308971[39] = 0.0;
   out_253192225752308971[40] = 1.0;
   out_253192225752308971[41] = 0.0;
   out_253192225752308971[42] = 0.0;
   out_253192225752308971[43] = 0.0;
   out_253192225752308971[44] = 0.0;
   out_253192225752308971[45] = 0.0;
   out_253192225752308971[46] = 0.0;
   out_253192225752308971[47] = 0.0;
   out_253192225752308971[48] = 0.0;
   out_253192225752308971[49] = 0.0;
   out_253192225752308971[50] = 1.0;
   out_253192225752308971[51] = 0.0;
   out_253192225752308971[52] = 0.0;
   out_253192225752308971[53] = 0.0;
   out_253192225752308971[54] = 0.0;
   out_253192225752308971[55] = 0.0;
   out_253192225752308971[56] = 0.0;
   out_253192225752308971[57] = 0.0;
   out_253192225752308971[58] = 0.0;
   out_253192225752308971[59] = 0.0;
   out_253192225752308971[60] = 1.0;
   out_253192225752308971[61] = 0.0;
   out_253192225752308971[62] = 0.0;
   out_253192225752308971[63] = 0.0;
   out_253192225752308971[64] = 0.0;
   out_253192225752308971[65] = 0.0;
   out_253192225752308971[66] = 0.0;
   out_253192225752308971[67] = 0.0;
   out_253192225752308971[68] = 0.0;
   out_253192225752308971[69] = 0.0;
   out_253192225752308971[70] = 1.0;
   out_253192225752308971[71] = 0.0;
   out_253192225752308971[72] = 0.0;
   out_253192225752308971[73] = 0.0;
   out_253192225752308971[74] = 0.0;
   out_253192225752308971[75] = 0.0;
   out_253192225752308971[76] = 0.0;
   out_253192225752308971[77] = 0.0;
   out_253192225752308971[78] = 0.0;
   out_253192225752308971[79] = 0.0;
   out_253192225752308971[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7053536604478710960) {
   out_7053536604478710960[0] = state[0];
   out_7053536604478710960[1] = state[1];
   out_7053536604478710960[2] = state[2];
   out_7053536604478710960[3] = state[3];
   out_7053536604478710960[4] = state[4];
   out_7053536604478710960[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7053536604478710960[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7053536604478710960[7] = state[7];
   out_7053536604478710960[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1214429005669720164) {
   out_1214429005669720164[0] = 1;
   out_1214429005669720164[1] = 0;
   out_1214429005669720164[2] = 0;
   out_1214429005669720164[3] = 0;
   out_1214429005669720164[4] = 0;
   out_1214429005669720164[5] = 0;
   out_1214429005669720164[6] = 0;
   out_1214429005669720164[7] = 0;
   out_1214429005669720164[8] = 0;
   out_1214429005669720164[9] = 0;
   out_1214429005669720164[10] = 1;
   out_1214429005669720164[11] = 0;
   out_1214429005669720164[12] = 0;
   out_1214429005669720164[13] = 0;
   out_1214429005669720164[14] = 0;
   out_1214429005669720164[15] = 0;
   out_1214429005669720164[16] = 0;
   out_1214429005669720164[17] = 0;
   out_1214429005669720164[18] = 0;
   out_1214429005669720164[19] = 0;
   out_1214429005669720164[20] = 1;
   out_1214429005669720164[21] = 0;
   out_1214429005669720164[22] = 0;
   out_1214429005669720164[23] = 0;
   out_1214429005669720164[24] = 0;
   out_1214429005669720164[25] = 0;
   out_1214429005669720164[26] = 0;
   out_1214429005669720164[27] = 0;
   out_1214429005669720164[28] = 0;
   out_1214429005669720164[29] = 0;
   out_1214429005669720164[30] = 1;
   out_1214429005669720164[31] = 0;
   out_1214429005669720164[32] = 0;
   out_1214429005669720164[33] = 0;
   out_1214429005669720164[34] = 0;
   out_1214429005669720164[35] = 0;
   out_1214429005669720164[36] = 0;
   out_1214429005669720164[37] = 0;
   out_1214429005669720164[38] = 0;
   out_1214429005669720164[39] = 0;
   out_1214429005669720164[40] = 1;
   out_1214429005669720164[41] = 0;
   out_1214429005669720164[42] = 0;
   out_1214429005669720164[43] = 0;
   out_1214429005669720164[44] = 0;
   out_1214429005669720164[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1214429005669720164[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1214429005669720164[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1214429005669720164[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1214429005669720164[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1214429005669720164[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1214429005669720164[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1214429005669720164[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1214429005669720164[53] = -9.8100000000000005*dt;
   out_1214429005669720164[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1214429005669720164[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1214429005669720164[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1214429005669720164[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1214429005669720164[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1214429005669720164[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1214429005669720164[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1214429005669720164[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1214429005669720164[62] = 0;
   out_1214429005669720164[63] = 0;
   out_1214429005669720164[64] = 0;
   out_1214429005669720164[65] = 0;
   out_1214429005669720164[66] = 0;
   out_1214429005669720164[67] = 0;
   out_1214429005669720164[68] = 0;
   out_1214429005669720164[69] = 0;
   out_1214429005669720164[70] = 1;
   out_1214429005669720164[71] = 0;
   out_1214429005669720164[72] = 0;
   out_1214429005669720164[73] = 0;
   out_1214429005669720164[74] = 0;
   out_1214429005669720164[75] = 0;
   out_1214429005669720164[76] = 0;
   out_1214429005669720164[77] = 0;
   out_1214429005669720164[78] = 0;
   out_1214429005669720164[79] = 0;
   out_1214429005669720164[80] = 1;
}
void h_25(double *state, double *unused, double *out_3464829860448870764) {
   out_3464829860448870764[0] = state[6];
}
void H_25(double *state, double *unused, double *out_9000363622045005408) {
   out_9000363622045005408[0] = 0;
   out_9000363622045005408[1] = 0;
   out_9000363622045005408[2] = 0;
   out_9000363622045005408[3] = 0;
   out_9000363622045005408[4] = 0;
   out_9000363622045005408[5] = 0;
   out_9000363622045005408[6] = 1;
   out_9000363622045005408[7] = 0;
   out_9000363622045005408[8] = 0;
}
void h_24(double *state, double *unused, double *out_4762731858686047091) {
   out_4762731858686047091[0] = state[4];
   out_4762731858686047091[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6827714023039505842) {
   out_6827714023039505842[0] = 0;
   out_6827714023039505842[1] = 0;
   out_6827714023039505842[2] = 0;
   out_6827714023039505842[3] = 0;
   out_6827714023039505842[4] = 1;
   out_6827714023039505842[5] = 0;
   out_6827714023039505842[6] = 0;
   out_6827714023039505842[7] = 0;
   out_6827714023039505842[8] = 0;
   out_6827714023039505842[9] = 0;
   out_6827714023039505842[10] = 0;
   out_6827714023039505842[11] = 0;
   out_6827714023039505842[12] = 0;
   out_6827714023039505842[13] = 0;
   out_6827714023039505842[14] = 1;
   out_6827714023039505842[15] = 0;
   out_6827714023039505842[16] = 0;
   out_6827714023039505842[17] = 0;
}
void h_30(double *state, double *unused, double *out_3738386096537115206) {
   out_3738386096537115206[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6928047493157297581) {
   out_6928047493157297581[0] = 0;
   out_6928047493157297581[1] = 0;
   out_6928047493157297581[2] = 0;
   out_6928047493157297581[3] = 0;
   out_6928047493157297581[4] = 1;
   out_6928047493157297581[5] = 0;
   out_6928047493157297581[6] = 0;
   out_6928047493157297581[7] = 0;
   out_6928047493157297581[8] = 0;
}
void h_26(double *state, double *unused, double *out_3696757337891585607) {
   out_3696757337891585607[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6141854481903745607) {
   out_6141854481903745607[0] = 0;
   out_6141854481903745607[1] = 0;
   out_6141854481903745607[2] = 0;
   out_6141854481903745607[3] = 0;
   out_6141854481903745607[4] = 0;
   out_6141854481903745607[5] = 0;
   out_6141854481903745607[6] = 0;
   out_6141854481903745607[7] = 1;
   out_6141854481903745607[8] = 0;
}
void h_27(double *state, double *unused, double *out_8319345477692799991) {
   out_8319345477692799991[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4704453421973354364) {
   out_4704453421973354364[0] = 0;
   out_4704453421973354364[1] = 0;
   out_4704453421973354364[2] = 0;
   out_4704453421973354364[3] = 1;
   out_4704453421973354364[4] = 0;
   out_4704453421973354364[5] = 0;
   out_4704453421973354364[6] = 0;
   out_4704453421973354364[7] = 0;
   out_4704453421973354364[8] = 0;
}
void h_29(double *state, double *unused, double *out_6118557469171333555) {
   out_6118557469171333555[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6417816148842905397) {
   out_6417816148842905397[0] = 0;
   out_6417816148842905397[1] = 1;
   out_6417816148842905397[2] = 0;
   out_6417816148842905397[3] = 0;
   out_6417816148842905397[4] = 0;
   out_6417816148842905397[5] = 0;
   out_6417816148842905397[6] = 0;
   out_6417816148842905397[7] = 0;
   out_6417816148842905397[8] = 0;
}
void h_28(double *state, double *unused, double *out_5845834754773091117) {
   out_5845834754773091117[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6946528907797115645) {
   out_6946528907797115645[0] = 1;
   out_6946528907797115645[1] = 0;
   out_6946528907797115645[2] = 0;
   out_6946528907797115645[3] = 0;
   out_6946528907797115645[4] = 0;
   out_6946528907797115645[5] = 0;
   out_6946528907797115645[6] = 0;
   out_6946528907797115645[7] = 0;
   out_6946528907797115645[8] = 0;
}
void h_31(double *state, double *unused, double *out_3122998066027424399) {
   out_3122998066027424399[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6768062584137097083) {
   out_6768062584137097083[0] = 0;
   out_6768062584137097083[1] = 0;
   out_6768062584137097083[2] = 0;
   out_6768062584137097083[3] = 0;
   out_6768062584137097083[4] = 0;
   out_6768062584137097083[5] = 0;
   out_6768062584137097083[6] = 0;
   out_6768062584137097083[7] = 0;
   out_6768062584137097083[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_787387508528698300) {
  err_fun(nom_x, delta_x, out_787387508528698300);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4326351974821968285) {
  inv_err_fun(nom_x, true_x, out_4326351974821968285);
}
void car_H_mod_fun(double *state, double *out_253192225752308971) {
  H_mod_fun(state, out_253192225752308971);
}
void car_f_fun(double *state, double dt, double *out_7053536604478710960) {
  f_fun(state,  dt, out_7053536604478710960);
}
void car_F_fun(double *state, double dt, double *out_1214429005669720164) {
  F_fun(state,  dt, out_1214429005669720164);
}
void car_h_25(double *state, double *unused, double *out_3464829860448870764) {
  h_25(state, unused, out_3464829860448870764);
}
void car_H_25(double *state, double *unused, double *out_9000363622045005408) {
  H_25(state, unused, out_9000363622045005408);
}
void car_h_24(double *state, double *unused, double *out_4762731858686047091) {
  h_24(state, unused, out_4762731858686047091);
}
void car_H_24(double *state, double *unused, double *out_6827714023039505842) {
  H_24(state, unused, out_6827714023039505842);
}
void car_h_30(double *state, double *unused, double *out_3738386096537115206) {
  h_30(state, unused, out_3738386096537115206);
}
void car_H_30(double *state, double *unused, double *out_6928047493157297581) {
  H_30(state, unused, out_6928047493157297581);
}
void car_h_26(double *state, double *unused, double *out_3696757337891585607) {
  h_26(state, unused, out_3696757337891585607);
}
void car_H_26(double *state, double *unused, double *out_6141854481903745607) {
  H_26(state, unused, out_6141854481903745607);
}
void car_h_27(double *state, double *unused, double *out_8319345477692799991) {
  h_27(state, unused, out_8319345477692799991);
}
void car_H_27(double *state, double *unused, double *out_4704453421973354364) {
  H_27(state, unused, out_4704453421973354364);
}
void car_h_29(double *state, double *unused, double *out_6118557469171333555) {
  h_29(state, unused, out_6118557469171333555);
}
void car_H_29(double *state, double *unused, double *out_6417816148842905397) {
  H_29(state, unused, out_6417816148842905397);
}
void car_h_28(double *state, double *unused, double *out_5845834754773091117) {
  h_28(state, unused, out_5845834754773091117);
}
void car_H_28(double *state, double *unused, double *out_6946528907797115645) {
  H_28(state, unused, out_6946528907797115645);
}
void car_h_31(double *state, double *unused, double *out_3122998066027424399) {
  h_31(state, unused, out_3122998066027424399);
}
void car_H_31(double *state, double *unused, double *out_6768062584137097083) {
  H_31(state, unused, out_6768062584137097083);
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
